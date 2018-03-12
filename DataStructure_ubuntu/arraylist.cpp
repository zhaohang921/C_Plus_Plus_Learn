#include "arraylist.h"

//template<typename T>
//ostream& operator<<(ostream& out,const arrayList<T>& x)
//{
//    x.output(out);
//    return out;
//}

//template<typename T>
//arrayList<T>::arrayList()
//{

//}

template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"Initial capacity= "<<initialCapacity<<" Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength=initialCapacity;
    element=new T[arrayLength];
    listSize=0;
}

//拷贝构造函数
template<typename T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength=theList.arrayLength;
    listSize=theList.listSize;
    element=new T[arrayLength];
    copy(theList.element,theList.element+listSize,element);
}

template<typename T>
arrayList<T>::~arrayList()
{
    delete [] element;
}

template<typename T>
bool arrayList<T>::empty() const
{
    return listSize==0;
}

template<typename T>
int arrayList<T>::size() const
{
    return listSize;
}

template<typename T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element(theIndex);
}

template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex=(int) (find(element,element+listSize,theElement)-element);
    if(theIndex==listSize)
        return -1;
    else
        return theIndex;
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    //把从theIndex之后开始的元素向前移动一位
    copy(element+theIndex+1,element+listSize,element+theIndex);
    element[--listSize].~T();
}

template<typename T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{
    if(theIndex<0 || theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<listSize;
        throw illegalIndex(s.str());
    }
    if(listSize == arrayLength)
    {
        //数组空间已满，数组长度加倍
        changeLength1D(element,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    copy_backward(element+theIndex,element+listSize,element+listSize+1);
    element[theIndex]=theElement;
    listSize++;
}

template<typename T>
void arrayList<T>::output(ostream& out) const
{
    copy(element,element+listSize,ostreambuf_iterator<T>(out," "));
}

template<typename T>
int arrayList<T>::capacity() const
{
    return arrayLength;
}

template<typename T>
void arrayList<T>::changeLength1D(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        throw illegalParameterValue("new length must be >=0");
    T* temp=new T(newLength);
    int number=min(oldLength,newLength);
    copy(a,a+number,temp);
    delete [] a;
    a=temp;
}

template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex<0 || theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<listSize;
        throw illegalIndex(s.str());
    }
}












