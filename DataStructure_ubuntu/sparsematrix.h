#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<iostream>
#include"myexception.h"
#include"arraylist.h"

using namespace std;

template<typename T>
struct matrixTerm{
    int row, col;
    T value;
};

//稀疏矩阵
template<typename T>
class sparseMatrix
{
    friend ostream& operator<<(ostream& out,sparseMatrix<T>& x);
    friend istream& operator>>(istream& in,sparseMatrix<T>& x);

public:
    sparseMatrix();

    //矩阵的转置
    void transpose(sparseMatrix<T> &b);

    //两个稀疏矩阵相加
    void add(sparseMatrix<T> &b,sparseMatrix<T> &c);
private:
    int rows, cols;
    arrayList<matrixTerm<T> > terms;

};

#endif // SPARSEMATRIX_H
