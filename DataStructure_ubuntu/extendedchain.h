#ifndef EXTENDEDCHAIN_H
#define EXTENDEDCHAIN_H
#include"chain.h"
#include"extendedlinearlist.h"

//作为抽象类extendedLinearList的链式描述
template<typename T>
class extendedChain : public chain<T>, public extendedLinearList<T>
{
public:
    extendedChain();
    virtual void clear();
    virtual void push_back(const T& theElement);

protected:
    chainNode<T>* lastNode;//指向链表的尾节点指针
    chainNode<T>* firstNode;//指向链表的第一个节点的指针
    int listSize;
};

#endif // EXTENDEDCHAIN_H
