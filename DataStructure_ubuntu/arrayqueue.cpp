#include "arrayqueue.h"

template<typename T>
arrayQueue<T>::arrayQueue()
{
    queue=new T[arrayLength];
    theFront=arrayLength-1;
    theBack=arrayLength-2;
    queueFront=0;
    queueBack=arrayLength-1;
}

template<typename T>
arrayQueue<T>::~arrayQueue()
{
    delete [] queue;
}

template<typename T>
bool arrayQueue<T>::empty() const
{
    return arrayLength=0;
}

template<typename T>
int arrayQueue<T>::size()const
{
    return arrayLength;
}

template<typename T>
T& arrayQueue<T>::front()
{
    return theFront;
}

template<typename T>
T& arrayQueue<T>::back()
{
    return theBack;
}

template<typename T>
void arrayQueue<T>::pop()
{
    if(theFront==theBack)
        throw queueEmpty();
    theFront=(theFront+1)%arrayLength;
    queue[theFront].~T();
}

template<typename T>
void arrayQueue<T>::push(const T& theElement)
{
    if((theBack+1)%arrayLength==theFront)
    {//加倍数组长度
        T* newQueue=new T[2*arrayLength];

        int start=(theFront+1)%arrayLength;
        if(start<2)
            //没有形成环
            copy(queue+start,queue+start+arrayLength-1,newQueue);
        else
        {//形成环
            copy(queue+start,queue+arrayLength,newQueue);
            copy(queue,queue+theBack+1,newQueue+arrayLength-start);
        }
        theFront=2*arrayLength-1;
        theBack=arrayLength-2;
        arrayLength*=2;
        delete[] queue;
        queue=newQueue;
    }
    queueBack=(queueBack+1)%arrayLength;
    queue[queueBack]=theElement;
}






