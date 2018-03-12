#include "linkedstack.h"

template<typename T>
linkedStack<T>::linkedStack()
{

}

template<typename T>
linkedStack<T>::linkedStack(int initialCapacity)
{
    stackTop=NULL;
    stackSize=0;
}

template<typename T>
linkedStack<T>::~linkedStack()
{
    while(stackTop!=NULL)
    {
        chainNode<T>* nextNode=stackTop->next;
        delete stackTop;
        stackTop=nextNode;
    }
}

template<typename T>
bool linkedStack<T>::empty() const
{
    return stackSize==0;
}

template<typename T>
int linkedStack<T>::size() const
{
    return stackSize;
}

template<typename T>
T& linkedStack<T>::top()//栈顶元素
{
    if(stackSize==0)
        throw stackEmpty();
    return stackTop->element;
}

template<typename T>
void linkedStack<T>::pop()//出栈，删除栈顶元素
{
    if(stackSize==0)
        throw stackEmpty();
    chainNode<T>* nextNode=stackTop->next;
    delete stackTop;
    stackTop=nextNode;
    stackSize--;
}

template<typename T>
void linkedStack<T>::push(const T& theElement)//压栈，将元素x压入栈顶
{
    stackTop=new chainNode<T>(theElement,stackTop);
    stackSize++;
}








