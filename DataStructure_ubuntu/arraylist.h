#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include"linearlist.h"
#include"iterator.h"

//用数组来描述线性表
template<typename T>
class arrayList : public linearList<T>
{
    //重载输入输出运算符只能是非成员函数，就声明为友元函数就行
    friend ostream& operator<<(ostream& out,const arrayList<T>& x);

public:
    //arrayList();
    arrayList(int initialCapacity=10);
    //拷贝构造函数
    arrayList(const arrayList<T>&);
    ~arrayList();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& get(int theIndex) const;
    virtual int indexOf(const T& theElement) const;
    virtual void erase(int theIndex);
    virtual void insert(int theIndex,const T& theElement);
    virtual void output(ostream& out) const;

       //其他方法（函数）
    int capacity() const;
    //改变一维数组的长度
    void changeLength1D(T*& a,int oldLength,int newLength);

    void reSet(int newSize);
    void set(int theIndex,const T& theElement);
    void clear();

    class iterator;
    iterator begin(){return iterator(element);}
    iterator end(){return iterator(element+listSize);}
protected:
    //若索引theIndex无效，则抛出异常
    void checkIndex(int theIndex) const;
    T* element;//存储线性表元素的一维数组
    int arrayLength;//一维数组的容量
    int listSize;//线性表元素个数

};

#endif // ARRAYLIST_H
