#include "iterator.h"

template<typename T>
iterator<T>::iterator()
{
}

template<typename T>
iterator<T>::iterator(T* thePosition)
{
    position=thePosition;
}

template<typename T>
T& iterator<T>::operator*() const
{
    return *position;
}

template<typename T>
T* iterator<T>::operator->() const
{
    return &*position;
}

template<typename T>
iterator<T>& iterator<T>::operator++()
{
    ++position;
    return *this;
}

template<typename T>
iterator<T> iterator<T>::operator++(int)
{
    iterator old=*this;
    ++position;
    return old;
}

template<typename T>
iterator<T>& iterator<T>::operator--()
{
    --position;
    return *this;
}

template<typename T>
iterator<T> iterator<T>::operator--(int)
{
    iterator old=*this;
    --position;
    return old;
}

template<typename T>
bool iterator<T>::operator!=(const iterator right) const
{
    return position != right.position;
}

template<typename T>
bool iterator<T>::operator==(const iterator right) const
{
    return position == right.position;
}
