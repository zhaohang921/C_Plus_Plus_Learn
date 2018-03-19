#pragma once
#ifndef ENERMY_H
#define ENERMY_H
#include "GObject.h"
#include"Player.h"
class Enermy :                //�о�����
	public GObject
{
protected:
	void Catch();               //�Ƿ�ץס���
	void virtual MakeDecision(bool b) = 0;  //AIʵ�֣�ȷ������
	COLORREF color;
public:
	static std::shared_ptr<Player> player;
	void virtual Draw(HDC &hdc);                      //��������Լ�
	Enermy(int x, int y) :GObject(x, y)
	{
		this->m_nSpeed = ENERMYSPEED;         //�����ٶ�
		m_dir = LEFT;                                          //���ó���
		m_cmd = UP;                                         //�����ƶ�����
	}
	Enermy() {}
	~Enermy() {}
	void virtual action();                                   //������Ϊ
};

//���ֵ���
class RedOne : public Enermy              //����ƶ�S
{
protected:
	void virtual MakeDecision(bool b);
public:
	void Draw(HDC &hdc);
	RedOne(int x, int y) :Enermy(x,y)
	{
		color = RGB(255, 0, 0);
	}
};
class BlueOne : public RedOne        //������
{
protected:
	void virtual MakeDecision(bool b);
public:
	void Draw(HDC &hdc);
	BlueOne(int x, int y) :RedOne(x, y)
	{
		color = RGB(0, 0, 255);
	}
}; 
class YellowOne : public RedOne      //������
{
protected:
	void virtual MakeDecision(bool b);
public:
	void Draw(HDC &hdc);
	YellowOne(int x, int y) :RedOne(x, y)
	{
		color = RGB(200,200,100);
	}
};









#endif