#include "Calendar.h"



Calendar::Calendar()
{
}


Calendar::~Calendar()
{
}

void Calendar::input()
{
	int choice;
	bool flag = true;
	while (flag)
	{
		cout << "�������ѯ����" << endl;
		cout << "1:������" << endl;
		cout << "2:�����꣬��" << endl;
		cout << "3:�����꣬�£���" << endl;
		cout << "0:�˳�" << endl;
		cin >> choice;
		switch (choice)
		{
		case(1):outyear();
			break;
		case(2):outmonth();
			break;
		case(3):outday();
			break;
		case(0):flag = false; break;
		default:cout << "�����������������" << endl;
		}
	}
}

void Calendar::outyear()
{
	int year;
	int i;
	cout << "�������꣺" << endl;
	cin >> year;
	if (isleap(year))//���������Ķ���
	{
		monthset[2] = 29;
	}
	else
	{
		monthset[2] = 28;
	}
	cout << "The calendar of the year " << year << endl << endl;
	for (i = 1; i <= 12; i++)
	{
		print(year, i);
	}
}

void Calendar::outmonth()
{
	int year, month;
	cout << "�������꣺" << endl;
	cin >> year;
	if (isleap(year))//���������Ķ���
	{
		monthset[2] = 29;
	}
	else
	{
		monthset[2] = 28;
	}
	cout << "�������£�" << endl;
	cin >> month;
	print(year, month);
}

void Calendar::outday()
{
	int year, month, day;
	int sumday, weekday;
	cout << "�������꣺" << endl;
	cin >> year;
	if (isleap(year))//���������Ķ���
	{
		monthset[2] = 29;
	}
	else
	{
		monthset[2] = 28;
	}
	cout << "�������£�" << endl;
	cin >> month;
	cout << "�������գ�" << endl;
	cin >> day;
	cout << year << "��" << month << "��" << day << "���ǣ�";
	sumday = getday(year, month, day);
	weekday = sumday % 7;
	switch (weekday)
	{
	case(0):cout << "������";
		break;
	case(1):cout << "����һ";
		break;
	case(2):cout << "���ڶ�";
		break;
	case(3):cout << "������";
		break;
	case(4):cout << "������";
		break;
	case(5):cout << "������";
		break;
	case(6):cout << "������";
		break;
	}
	cout << endl << endl;
}

bool Calendar::isleap(int year)//�ж��Ƿ�������
{
	//1.�ܱ�4���������ܱ�100������
	//2.�ܱ�400������
	if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
		return true;
	else return false;
}

int Calendar::getday(int year, int month, int day)//��ȡ��ĿǰΪֹ����������
{
	int i;
	int x = 0;
	int yearday = 0;
	int monthday = 0;
	int sumday = 0; //�ӹ�Ԫ1��1��1�յ���ǰ���ڵ���������
	for (i = 1; i<year; i++)
	{
		if (isleap(i))//��������꣬������������һ
			x++;
	}
	yearday = x + (year - 1) * 365;
	for (i = 1; i<month; i++)
	{
		monthday += monthset[i];
	}
	sumday = yearday + monthday + day;
	return sumday;
}

void Calendar::print(int year, int month)//���ĳһ��ĳһ�µ�����
{
	int sumday = getday(year, month, 1);//�ӹ�Ԫ1��1��1�յ�����1�ŵ���������
	int i;
	int weekday = sumday % 7;//�õ�����һ�ŵ�����ֵ

	switch (month)
	{
	case (1):cout << "Januray 1" << endl; break;
	case (2):cout << "February 2" << endl; break;
	case (3):cout << "Match 3" << endl; break;
	case (4):cout << "April 4" << endl; break;
	case (5):cout << "May 5" << endl; break;
	case (6):cout << "Juno 6" << endl; break;
	case (7):cout << "July 7" << endl; break;
	case (8):cout << "August 8" << endl; break;
	case (9):cout << "September 9" << endl; break;
	case (10):cout << "October 10" << endl; break;
	case (11):cout << "November 11" << endl; break;
	case (12):cout << "December 12" << endl; break;
	}

	cout << "========================================" << endl;
	cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl << endl;
	//���ø���һ�ŵ�λ��
	switch (weekday)
	{
		//setw��int n��ֻ�Ƕ�ֱ�Ӹ���<<����������������
		//n�������ʱ������n���ַ��������ȣ�Ȼ��Ĭ�ϵ�����n���ַ�������Ҷ������
		//setiosflags(ios::left)�������
	case(0):cout << " " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(1):cout << "       " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(2):cout << "             " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(3):cout << "                   " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(4):cout << "                         " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(5):cout << "                               " << setw(6) << setiosflags(ios::left) << "1";
		break;
	case(6):cout << "                                     " << setw(6) << setiosflags(ios::left) << "1" << endl;
		break;
	}
	//��ʣ����������
	for (i = 2; i <= monthset[month]; i++)
	{
		weekday = (weekday++) % 7;
		//��������ʱ��Ҫ����
		if (weekday == 6)
		{
			//cout<<endl;
			cout << setw(6) << setiosflags(ios::left) << i;
			cout << endl;
		}
		else
			cout << setw(6) << setiosflags(ios::left) << i;
	}
	cout << endl << endl;
}