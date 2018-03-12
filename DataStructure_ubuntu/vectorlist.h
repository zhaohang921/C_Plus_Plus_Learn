#ifndef VECTORLIST_H
#define VECTORLIST_H

#include"linearlist.h"
#include<vector>

//用vector实现的基于数组的线性表
template<typename T>
class vectorList  : public linearList<T>
{
public:
    //vectorList();
    vectorList(int initialCapacity=10);
    vectorList(const vectorList<T>&);
    ~vectorList();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& get(int theIndex) const;
    virtual int indexOf(const T& theElement) const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex,const T& theElement);
    virtual void output(ostream& out) const;

    int capacity() const;
    //typedef typename vector<T>::iterator iterator;
    typename vector<T>::iterator begin();
    typename vector<T>::iterator end();

protected:
    void checkIndex(int theIndex) const;
    vector<T>* element;//存储线性表元素的向量
};

#endif // VECTORLIST_H
