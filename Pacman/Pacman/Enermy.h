#pragma once
#ifndef ENERMY_H
#define ENERMY_H
#include "GObject.h"
#include"Player.h"
class Enermy :                //敌军对象
	public GObject
{
protected:
	void Catch();               //是否抓住玩家
	void virtual MakeDecision(bool b) = 0;  //AI实现，确定方向
	COLORREF color;
public:
	static std::shared_ptr<Player> player;
	void virtual Draw(HDC &hdc);                      //负责绘制自己
	Enermy(int x, int y) :GObject(x, y)
	{
		this->m_nSpeed = ENERMYSPEED;         //设置速度
		m_dir = LEFT;                                          //设置朝向
		m_cmd = UP;                                         //设置移动方向
	}
	Enermy() {}
	~Enermy() {}
	void virtual action();                                   //负责行为
};

//三种敌人
class RedOne : public Enermy              //随机移动S
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
class BlueOne : public RedOne        //守卫者
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
class YellowOne : public RedOne      //扰乱者
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