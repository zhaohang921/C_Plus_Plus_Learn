#ifndef STACK_H
#define STACK_H

template<typename T>
class stack
{
public:
    stack();
    virtual ~stack();
    virtual bool empty() const=0;
    virtual int size() const=0;
    virtual T& top()=0;//栈顶元素
    virtual void pop()=0;//出栈，删除栈顶元素
    virtual void push(const T& theElement)=0;//压栈，将元素x压入栈顶
};

#endif // STACK_H
