#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H
/*
��������
������ʾѡ���ܣ�Ȼ��������ʾ���������
����������꣬��������������
������������£���������µ�����
��������������գ���������������ڱ���ĵڼ��ܣ����ڼ�
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class Calendar
{
public:
	Calendar();
	~Calendar();

	void input();
	void outyear();
	void outmonth();
	void outday();
	bool isleap(int year);//�ж��Ƿ�������
	int getday(int year, int month, int day);//��ȡ�ӹ�Ԫ1��1��1�յ�ĿǰΪֹ����������
	void print(int year, int month);//���ĳһ��ĳһ�µ�����

private:
	int monthset[20] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

};

#endif