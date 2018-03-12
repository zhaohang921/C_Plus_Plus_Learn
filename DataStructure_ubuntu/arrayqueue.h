#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include"queue.h"
#include<iostream>
#include"myexception.h"

using namespace std;

template<typename T>
class arrayQueue : public queue<T>
{
public:
    arrayQueue();
    ~arrayQueue();
    bool empty() const;
    int size()const;
    T& front();
    T& back();
    void pop();
    void push(const T& theElement);

private:
    T theFront;
    T theBack;
    int queueFront;
    int queueBack;
    T* queue;
    int arrayLength;//一维数组的容量
    //int listSize;//线性表元素个数

};

#endif // ARRAYQUEUE_H
