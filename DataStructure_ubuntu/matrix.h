#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include"myexception.h"

using namespace std;

//矩阵
template<typename T>
class matrix
{
    friend ostream& operator<<(ostream& ,const matrix<T>&);

public:
    matrix();
    matrix(int theRows=0,int theColumns=0);
    matrix(const matrix<T>&);
    ~matrix();
    int rows() const;
    int columns() const;
    T& operator()(int i,int j) const;
    matrix<T>& operator=(const matrix<T>&);
    matrix<T> operator+() const;//一元的加
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-() const;//一元的
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T> operator+=(const T&);
private:
    int theRows,
        theColumns;
    T *element;//数组element

};

#endif // MATRIX_H
