#ifndef LINAEARLIST_H
#define LINAEARLIST_H

#include<iostream>
#include<exception>
#include<sstream>
#include"myexception.h"


using namespace std;

//一个线性表的抽象类
template<typename T>
class linearList
{
public:
    linearList();
    virtual ~linearList() {}

    virtual bool empty() const =0;
    virtual int size() const =0;
    //theIndex是索引也就是序号
    virtual T& get(int theIndex) const =0;
    //theElement是该索引的元素值
    virtual int indexOf(const T& theElement) const =0;
    virtual void erase(int theIndex) =0;
    virtual void insert(int theIndex, const T& theElement) =0;
    virtual void output(ostream& out) const =0;
};

#endif // LINAEARLIST_H
