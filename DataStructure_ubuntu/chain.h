#ifndef CHAIN_H
#define CHAIN_H

#include<linearlist.h>
#include<chainnode.h>

//线性表的链式描述，也就是链表
template<typename T>
class chain : public linearList<T>
{
    friend ostream& operator<<(ostream& out,const chain<T>& x);

public:
//    chain();
    chain(int initialCapacity=10);
    chain(const chain<T>&);
    ~chain();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& get(int theIndex) const;
    virtual int indexOf(const T &theElement) const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex, const T &theElement);
    virtual void output(ostream &out) const;

    //箱子排序，作为链表chain的一个成员函数
    void binSort(int range);

protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;//指向链表的第一个节点的指针
    int listSize;
};

#endif // CHAIN_H
