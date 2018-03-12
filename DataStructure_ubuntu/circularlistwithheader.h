#ifndef CIRCULARLISTWITHHEADER_H
#define CIRCULARLISTWITHHEADER_H

#include"linearlist.h"
#include<chainnode.h>

//带有头结点的循环链表
template<typename T>
class circularListWithHeader : public linearList<T>
{
public:
    circularListWithHeader();


    int indexOf(const T& theElement) const;

protected:
    chainNode<T>* headerNode;
    //chainNode<T>* lastNode;//指向链表的尾节点指针
    chainNode<T>* firstNode;//指向链表的第一个节点的指针
    int listSize;

};

#endif // CIRCULARLISTWITHHEADER_H
