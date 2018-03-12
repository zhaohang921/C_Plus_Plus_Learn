#include "chain.h"

template<typename T>
ostream& operator<<(ostream& out,const chain<T>& x)
{
    x.output(out);
    return out;
}

//template<typename T>
//chain<T>::chain()
//{
//}

template<typename T>
chain<T>::chain(int initialCapacity)
{
    if(initialCapacity<1)
    {
        ostringstream s;
        s<<"Initial capacity= "<<initialCapacity<<" Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode=NULL;
    listSize=0;
}

template<typename T>
chain<T>::chain(const chain<T>& theList)
{
    listSize=theList.listSize;
    if(listSize==0)
    {
        firstNode=NULL;
        return;
    }
    chainNode<T>* sourceNode=theList.firstNode;//要拷贝的链表theList的节点
    firstNode=new chainNode<T>(sourceNode->element);
    sourceNode=sourceNode->next;
    chainNode<T>* targetNode=firstNode;//当前链表*this的最后一个节点
    //复制剩余元素
    while(sourceNode!=NULL)
    {
        targetNode->next=new chainNode<T>(sourceNode->element);
        targetNode=targetNode->next;
        sourceNode=sourceNode->next;
    }
    targetNode->next=NULL;
}

template<typename T>
chain<T>::~chain()
{
    while(firstNode!=NULL)
    {
        chainNode<T>* nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
}

template<typename T>
bool chain<T>::empty() const
{
    return listSize==0;
}

template<typename T>
int chain<T>::size() const
{
    return listSize;
}

template<typename T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode=firstNode;
    for(int i=0;i<theIndex;i++)
        currentNode=currentNode->next;
    return currentNode->element;
}

template<typename T>
int chain<T>::indexOf(const T &theElement) const
{
    chainNode<T>* currentNode=firstNode;
    int index=0;
    while(currentNode!=NULL &&
          currentNode->element!=theElement)
    {
        currentNode=currentNode->next;
        index++;
    }
    if(currentNode==NULL)
        return -1;
    else
        return index;
}

template<typename T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode;
    if(theIndex==0)
    {//如果是首节点,删除链表的首节点
        deleteNode=firstNode;
        firstNode=firstNode->next;
    }
    else
    {//用指针p指向要删除节点的前驱节点
        chainNode<T>* p=firstNode;
        for(int i=0;i<theIndex;i++)
            p=p->next;
        deleteNode=p->next;
        p->next=p->next->next;
    }
    listSize--;
    delete deleteNode;
}

template<typename T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    if(theIndex<0 || theIndex>listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<listSize;
        throw illegalIndex(s.str());
    }
    if(theIndex==0)
        //在链表头插入
        firstNode=new chainNode<T>(theElement,firstNode);
    else
    {//寻找新元素的前驱
        chainNode<T>* p=firstNode;
        for(int i=0;i<theIndex-1;i++)
            p=p->next;
        //在p之后插入
        p->next=new chainNode<T>(theElement,p->next);
    }
    listSize++;
}

template<typename T>
void chain<T>::output(ostream &out) const
{
    for(chainNode<T>* currentNode=firstNode;
        currentNode!=NULL;
        currentNode=currentNode->next)
        out<<currentNode->element<<" ";
}

template<typename T>
void chain<T>::checkIndex(int theIndex) const
{
    if(theIndex<0 || theIndex>=listSize)
    {
        ostringstream s;
        s<<"index="<<theIndex<<" size= "<<listSize;
        throw illegalIndex(s.str());
    }
}

template<typename T>
void chain<T>::binSort(int range)
{
    //创建并初始化箱子
    chainNode<T> **bottom, **top;
    bottom=new chainNode<T>* [range+1];
    top=new chainNode<T>* [range+1];
    for(int b=0;b<=range;b++)
        bottom[b]=NULL;

    //把链表的节点分配到箱子
    for(;firstNode!=NULL;firstNode=firstNode->next)
    {
        //把首节点加到箱子中
        int theBin=firstNode->element;
        if(bottom[theBin]==NULL)
            //若箱子为空，则首尾指向同一个节点
            bottom[theBin]=top[theBin]=firstNode;
        else
        {
            top[theBin]->next=firstNode;
            top[theBin]=firstNode;
        }
    }

    //把箱子中的节点收集到有序链表
    chainNode<T>* y=NULL;
    for(int theBin=0;theBin<=range;theBin++)
        if(bottom[theBin]!=NULL)
        {
            if(y==NULL)
                firstNode=bottom[theBin];
            else
                y->next=bottom[theBin];
            y=top[theBin];
        }
    if(y!=NULL)
        y->next=NULL;
    delete [] bottom;
    delete [] top;
}



