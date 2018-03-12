#include "circularlistwithheader.h"

template<typename T>
circularListWithHeader<T>::circularListWithHeader()
{
    headerNode=new chainNode<T>();
    headerNode->next=headerNode;
    listSize=0;
}

template<typename T>
int circularListWithHeader<T>::indexOf(const T& theElement) const
{
    headerNode->element=theElement;
    chainNode<T>* currentNode=headerNode->next;
    int index=0;
    while(currentNode->element!=theElement)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==headerNode)
        return -1;
    else
        return index;
}
