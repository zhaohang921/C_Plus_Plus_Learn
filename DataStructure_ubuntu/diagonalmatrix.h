#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include<iostream>
#include"myexception.h"

using namespace std;

//对角矩阵
template<typename T>
class diagonalMatrix
{
public:
    diagonalMatrix();
    diagonalMatrix(int theN=10);
    ~diagonalMatrix();
    T get(int,int) const;
    void set(int,int,const T&);
private:
    int n;//矩阵维数
    T *element;
};

#endif // DIAGONALMATRIX_H
