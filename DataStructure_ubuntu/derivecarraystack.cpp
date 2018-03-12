#include "derivecarraystack.h"

template<typename T>
derivecArrayStack<T>::derivecArrayStack()
{
}

template<typename T>
bool derivecArrayStack<T>::empty() const
{
    return arrayList<T>::empty();
}

template<typename T>
int derivecArrayStack<T>::size() const
{
    return arrayList<T>::size();
}

template<typename T>
T& derivecArrayStack<T>::top()
{
//    if(arrayList<T>::empty())
//        throw stackEmpty();
//    return get(arrayList<T>::size()-1);

    try{return get(arrayList<T>::size()-1);}
    catch(illegalIndex)
    {
        throw stackEmpty();
    }
}

template<typename T>
void derivecArrayStack<T>::pop()
{
    if(arrayList<T>::empty())
        throw stackEmpty();
    erase(arrayList<T>::size()-1);
}

template<typename T>
void derivecArrayStack<T>::push(const T& theElement)
{
    insert(arrayList<T>::size(),theElement);
}
