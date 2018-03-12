#ifndef EXTENDEDLINEARLIST_H
#define EXTENDEDLINEARLIST_H

#include<linearlist.h>

//扩展的线性表的抽象类，增加两个方法
template<typename T>
class extendedLinearList : public linearList<T>
{
public:
    extendedLinearList();
    virtual ~extendedLinearList(){}

    virtual void clear()=0;
    virtual void push_back(const T& theElement)=0;//将元素theElement插入表尾

};

#endif // EXTENDEDLINEARLIST_H
