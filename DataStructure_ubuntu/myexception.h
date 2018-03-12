#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

//自己定义的异常类，包含了所有的异常

#include<string>
#include<iostream>

using namespace std;

class illegalParameterValue
{
    //friend ostream &operator << (ostream &out, const illegalParameterValue &ill);
public:
    illegalParameterValue(string theMessage = "Illegal parameter value")
    {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl; }
private:
    string message;
};

class illegalIndex
{
public:
    illegalIndex(string theMessage = "Illegal index")
    {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl; }
private:
    string message;
};

class matrixIndexOutOfBounds
{
public:
    matrixIndexOutOfBounds(string theMessage = "matrixIndexOutOfBounds")
    {
        message=theMessage;
    }
    void outputMessage() { cout << message << endl; }
private:
    string message;
};

class matrixSizeMismatch
{
public:
    matrixSizeMismatch(string theMessage="matrixSizeMismatch ")
    {
        message=theMessage;
    }

private:
    string message;
};

class stackEmpty
{
public:
    stackEmpty(string theMessage="stackEmpty ")
    {
        message=theMessage;
    }

private:
    string message;
};

class queueEmpty
{
public:
    queueEmpty(string theMessage="queueEmpty ")
    {
        message=theMessage;
    }

private:
    string message;
};
#endif // MYEXCEPTION_H
