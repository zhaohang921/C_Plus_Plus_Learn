#include "chainnode.h"

template<typename T>
chainNode<T>::chainNode()
{
}

template<typename T>
chainNode<T>::chainNode(const T& element)
{
    this->element=element;
}

template<typename T>
chainNode<T>::chainNode(const T& element,chainNode<T>* next)
{
    this->element=element;
    this->next=next;
}
