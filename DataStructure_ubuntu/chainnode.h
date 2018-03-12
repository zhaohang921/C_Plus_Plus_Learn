#ifndef CHAINNODE_H
#define CHAINNODE_H

//链表节点的结构定义
template<typename T>
class chainNode
{
public:
    chainNode();
    chainNode(const T& element);
    chainNode(const T& element,chainNode<T>* next);


    T element;
    chainNode<T> *next;
};

#endif // CHAINNODE_H
