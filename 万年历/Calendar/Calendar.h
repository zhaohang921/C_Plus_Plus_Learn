#pragma once
#ifndef CALENDAR_H
#define CALENDAR_H
/*
万年历：
根据提示选择功能，然后输入提示输入的数据
若输入的是年，则输出该年的日历
若输入的是年月，则输出该月的日历
若输入的是年月日，则输出该日期属于本年的第几周，星期几
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
	bool isleap(int year);//判断是否是闰年
	int getday(int year, int month, int day);//获取从公元1年1月1日到目前为止的所有天数
	void print(int year, int month);//输出某一年某一月的月历

private:
	int monthset[20] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

};

#endif