#ifndef DERIVECARRAYSTACK_H
#define DERIVECARRAYSTACK_H
#include"arraylist.h"
#include"stack.h"
#include"myexception.h"

//从arrayList派生的数组栈类
template<typename T>
class derivecArrayStack:private arrayList<T> , public stack<T>
{
public:
    derivecArrayStack();
    derivecArrayStack(int initialcapacity=10):arrayList<T> (initialcapacity){}
    bool empty() const;
    int size() const;
    T& top();
    void pop();
    void push(const T& theElement);

};

#endif // DERIVECARRAYSTACK_H
