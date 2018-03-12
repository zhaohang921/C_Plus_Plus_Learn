#include "matrix.h"

template<typename T>
ostream& operator<<(ostream& out,const matrix<T>& x)
{
    x.output(out);
    return out;
}

template<typename T>
matrix<T>::matrix()
{
}

template<typename T>
matrix<T>::matrix(int theRows,int theColumns)
{
    if(theRows<0 || theColumns<0)
        throw illegalParameterValue("Rows and columns must be >= 0");
    if((theRows==0 || theColumns==0) && (theRows!=0 || theColumns!=0))
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    this->theRows=theRows;
    this->theColumns=theColumns;
    element=new T [theRows*theColumns];
}

template<typename T>
matrix<T>::matrix(const matrix<T>& m)
{
    theRows=m.theRows;
    theColumns=m.theColumns;
    element=new T [theRows*theColumns];
    copy(m.element,
         m.element+theRows*theColumns,
         element);
}

template<typename T>
matrix<T>::~matrix()
{
    delete [] element;
}

template<typename T>
int matrix<T>::rows() const
{
    return theRows;
}

template<typename T>
int matrix<T>::columns() const
{
    return theColumns;
}

template<typename T>
T& matrix<T>::operator()(int i,int j) const
{
    if(i<1 || i>theRows || j<1 || j>theColumns)
        throw matrixIndexOutOfBounds();
    return element[(i-1)*theColumns+j-1];
}

template<typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    if(this!=&m)//不能自己复制自己
    {
        delete [] element;
        theRows=m.theRows;
        theColumns=m.theColumns;
        element=new T [theRows*theColumns];
        copy(m.element,m.element+theRows*theColumns,element);
    }
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+() const//一元的加
{

}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
    if(theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows,theColumns);
    for(int i=0;i<theRows*theColumns;i++)
        w.element[i]=element[i]+m.element[i];
    return w;
}

template<typename T>
matrix<T> matrix<T>::operator-() const//一元的
{

}

template<typename T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
    if(theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows,theColumns);
    for(int i=0;i<theRows*theColumns;i++)
        w.element[i]=element[i]-m.element[i];
    return w;
}

template<typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
    if(theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows,theColumns);
    int ct=0,cm=0,cw=0;
    for(int i=1;i<=theRows;i++)
    {
        for(int j=1;j<=m.theColumns;j++)
        {
            T sum=element[ct]*m.element[cm];//计算第一项
            for(int k=2;k<=theColumns;k++)
            {
                ct++;//*this中第i行的下一项
                cm+=m.theColumns;//m中第j列的下一项
                sum+=element[ct]*m.element[cm];
            }
            w.element[cw++]=sum;
            ct-=theColumns-1;
            cm=j;
        }
        ct+=theColumns;
        cm=0;
    }
    return w;
}

template<typename T>
matrix<T> matrix<T>::operator+=(const T& m)
{
    if(theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    matrix<T> w(theRows,theColumns);
    for(int i=0;i<theRows*theColumns;i++)
        w.element[i]=element[i]+m.element[i];
    return w;
}

