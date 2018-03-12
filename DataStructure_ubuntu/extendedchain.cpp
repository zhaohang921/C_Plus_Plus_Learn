#include "extendedchain.h"

template<typename T>
extendedChain<T>::extendedChain()
{
}

template<typename T>
void extendedChain<T>::clear()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
    listSize=0;
}

template<typename T>
void extendedChain<T>::push_back(const T& theElement)
{
    chainNode<T>* newNode=new chainNode<T>(theElement,NULL);
    if(firstNode==NULL)
        firstNode=lastNode=newNode;
    else
    {
        lastNode->next=newNode;
        lastNode=newNode;
    }
    listSize++;
}
