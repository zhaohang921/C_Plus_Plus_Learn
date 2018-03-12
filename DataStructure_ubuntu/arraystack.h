#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include"stack.h"
#include"myexception.h"
#include<sstream>
#include<iostream>

using namespace std;

//数组栈
template<typename T>
class arrayStack : public stack<T>
{
    friend ostream& operator<<(ostream& out,const arrayStack<T>& x);
public:
    arrayStack();
    arrayStack(int initialcapacity=10);
    ~arrayStack();
    bool empty() const;
    int size() const;
    T& top();
    void pop();
    void push(const T& theElement);

    void changeLength1D(T*& a,int oldLength,int newLength);

private:
    int stackTop;//当前栈顶
    int arrayLength;//栈容量
    T *stack;//元素数组
};

#endif // ARRAYSTACK_H
