#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include"stack.h"
#include"chainnode.h"
#include"myexception.h"


template<typename T>
class linkedStack : public stack<T>
{
public:
    linkedStack();
    linkedStack(int initialCapacity=10);
    ~linkedStack();
    bool empty() const;
    int size() const;
    T& top();//栈顶元素
    void pop();//出栈，删除栈顶元素
    void push(const T& theElement);//压栈，将元素x压入栈顶

private:
    chainNode<T>* stackTop;
    int stackSize;
};

#endif // LINKEDSTACK_H
