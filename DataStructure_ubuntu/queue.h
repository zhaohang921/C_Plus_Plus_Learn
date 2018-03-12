#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class queue
{
public:
    queue();
    virtual ~queue(){}
    virtual bool empty() const=0;
    virtual int size()const=0;
    virtual T& front()=0;
    virtual T& back()=0;
    virtual void pop()=0;
    virtual void push(const T& theElement)=0;
};

#endif // QUEUE_H
