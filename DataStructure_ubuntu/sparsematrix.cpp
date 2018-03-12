#include "sparsematrix.h"

template<typename T>
ostream& operator<<(ostream& out,sparseMatrix<T>& x)
{
    out<<"rows= "<<x.rows<<"columns= "<<x.cols<<endl;
    out<<"nonzero terms ="<<x.terms.size()<<endl;
    for(typename arrayList<matrixTerm<T> >::iterator i=x.terms.begin();i != x.terms.end();i++)
        out<<"a("<<(*i).row<<','<<(*i).col<<")"<<(*i).value<<endl;
    return out;
}

template<typename T>
istream& operator>>(istream& in,sparseMatrix<T>& x)
{
    int numberOfTerms;
    cout<<"Enter number of rows, columns, and #terms"<<endl;
    in>>x.rows>>x.cols>>numberOfTerms;
    if(x.rows<0 || x.cols<0)
        throw illegalParameterValue("Rows and columns must be >= 0");
    if((x.rows==0 || x.cols==0) && (x.rows!=0 || x.cols!=0))
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    x.terms.reSet(numberOfTerms);

    matrixTerm<T> mTerm;
    for(int i=0;i!=numberOfTerms;i++)
    {
        cout<<"Enter row,column,and value of term"<<(i+1)<<endl;
        in>>mTerm.row>>mTerm.col>>mTerm.value;
        if(mTerm.row<0 || mTerm.col<0)
            throw illegalParameterValue("Rows and columns must be >= 0");
        if((mTerm.row==0 || mTerm.col==0) && (mTerm.row!=0 || mTerm.col!=0))
            throw illegalParameterValue("Either both or neither rows and columns should be zero");
        x.terms.set(i,mTerm);
    }
    return in;
}

template<typename T>
sparseMatrix<T>::sparseMatrix()
{
}

template<typename T>
void sparseMatrix<T>::transpose(sparseMatrix<T> &b)
{
    b.cols=rows;
    b.rows=cols;
    b.terms.reSet(terms.size());

    int* colSize=new int[cols+1];
    int* rowNext=new int[cols+1];

    //寻找*this中每一列的项的数目
    for(int i=1;i!=cols+1;i++)
        colSize[i]=0;
    for(typename arrayList<matrixTerm<T> >::iterator i=terms.begin();i!=terms.end();i++)
        colSize[(*i).col]++;

    //寻找b中每一行的起点
    rowNext[1]=0;
    for(int i=2;i<=cols;i++)
        rowNext[i]=rowNext[i-1]+colSize[i-1];

    //实施从*this到b的转置复制
    matrixTerm<T> mTerm;
    for(typename arrayList<matrixTerm<T> >::iterator i=terms.begin();i!=terms.end();i++)
    {
        int j=rowNext[(*i).col]++;
        mTerm.row=(*i).col;
        mTerm.col=(*i).row;
        mTerm.value=(*i).value;
        b.terms.set(j,mTerm);
    }
}

template<typename T>
void sparseMatrix<T>::add(sparseMatrix<T> &b,sparseMatrix<T> &c)
{//计算c=(*this）+b
    if(rows!=b.rows || cols!=b.cols)
        throw matrixSizeMismatch();

    c.rows=rows;
    c.cols=cols;
    c.terms.clear();
    int cSize=0;

    typename arrayList<matrixTerm<T> >::iterator it=terms.begin();
    typename arrayList<matrixTerm<T> >::iterator ib=b.terms.begin();
    typename arrayList<matrixTerm<T> >::iterator itEnd=terms.end();
    typename arrayList<matrixTerm<T> >::iterator ibEnd=b.terms.end();

    //遍历*this和b，把相关项相加
    while(it!=itEnd && ib!=ibEnd)
    {
        //行主索引加上每一项的列数
        int tIndex=(*it).row*cols+(*it).col;
        int bIndex=(*ib).row*cols+(*ib).col;

        if(tIndex<bIndex)
        {
            //b项在后
            c.terms.insert(cSize++,*it);
            it++;
        }
        else
        {
            if(tIndex==bIndex)
            {
                //两项在同一位置
                //仅当相加后不为0时加入c
                if((*it).value+(*ib).value!=0)
                {
                    matrixTerm<T> mTerm;
                    mTerm.row=(*it).row;
                    mTerm.col=(*it).col;
                    mTerm.value=(*it).value+(*ib).value;
                    c.terms.insert(cSize++,mTerm);
                }
                it++;
                ib++;
            }
            else
            {
                c.terms.insert(cSize++,*ib);
                ib++;
            }
        }
    }

    //复制剩余项
    for(;it!=itEnd;it++)
        c.terms.insert(cSize++,*it);
    for(;ib!=ibEnd;ib++)
        c.terms.insert(cSize++,*ib);
}





















