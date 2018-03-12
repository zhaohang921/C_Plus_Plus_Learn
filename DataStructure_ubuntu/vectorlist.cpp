#include "vectorlist.h"

//template<typename T>
//vectorList<T>::vectorList()
//{
//}

template<typename T>
vectorList<T>::vectorList(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"Initial capacity= "<<initialCapacity<<" Must be > 0";
        throw illegalParameterValue(s.str());
    }
    element=new vector<T>;
    element->reserve(initialCapacity);
}

template<typename T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
    element=new vector<T>(*theList.element);
}

template<typename T>
vectorList<T>::~vectorList()
{
    delete element;
}

template<typename T>
bool vectorList<T>::empty() const
{
    return element->empty();
}

template<typename T>
int vectorList<T>::size() const
{
    return (int)element->size();
}

template<typename T>
T& vectorList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element(theIndex);
}

template<typename T>
int vectorList<T>::indexOf(const T& theElement) const
{
    int theIndex=(int) (find(element->begin(),element->end(),theElement)-element);
    if(theIndex==element->size())
        return -1;
    else
        return theIndex;
}

template<typename T>
void vectorList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    element->erase(begin()+theIndex);
}

template<typename T>
void vectorList<T>::insert(int theIndex,const T& theElement)
{
    if(theIndex<0 || theIndex>element->size())
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<element->size();
        throw illegalIndex(s.str());
    }
    element->insert(element->begin()+theIndex,theElement);
}

template<typename T>
void vectorList<T>::output(ostream& out) const
{

}

template<typename T>
int vectorList<T>::capacity() const
{
    return (int) element->capacity();
}

template<typename T>
typename vector<T>::iterator vectorList<T>::begin()
{
    return element->begin();
}

template<typename T>
typename vector<T>::iterator vectorList<T>::end()
{
    return element->end();
}

template<typename T>
void vectorList<T>::checkIndex(int theIndex) const
{
    if(theIndex<0 || theIndex>=element->size())
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<element->size();
        throw illegalIndex(s.str());
    }
}
