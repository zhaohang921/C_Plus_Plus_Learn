#include "arraystack.h"

template<typename T>
arrayStack<T>::arrayStack()
{
}

template<typename T>
arrayStack<T>::arrayStack(int initialcapacity)
{
    if(initialcapacity<1)
    {
        ostringstream s;
        s<<"Initial capacity= = "<<initialcapacity<<"Must be >0";
        throw illegalParameterValue(s.str());
    }
    arrayLength=initialcapacity;
    stack=new T[arrayLength];
    stackTop=-1;
}

template<typename T>
arrayStack<T>::~arrayStack()
{
    delete [] stack;
}

template<typename T>
bool arrayStack<T>::empty() const
{
    return stackTop==-1;
}

template<typename T>
int arrayStack<T>::size() const
{
    return stackTop+1;
}

template<typename T>
T& arrayStack<T>::top()
{
    if(stackTop==-1)
        throw stackEmpty();
    return stack[stackTop];
}

template<typename T>
void arrayStack<T>::pop()
{
    if(stackTop==-1)
        throw stackEmpty();
    stack[stackTop--].~T();
}

template<typename T>
void arrayStack<T>::push(const T& theElement)
{
    if(stackTop==arrayLength-1)
    {
        changeLength1D(stack,arrayLength,2*arrayLength);
        arrayLength*=2;
    }
    stack[++stackTop]=theElement;
}

template<typename T>
void arrayStack<T>::changeLength1D(T*& a,int oldLength,int newLength)
{
    if(newLength<0)
        throw illegalParameterValue("new length must be >=0");
    T* temp=new T(newLength);
    int number=min(oldLength,newLength);
    copy(a,a+number,temp);
    delete [] a;
    a=temp;
}
