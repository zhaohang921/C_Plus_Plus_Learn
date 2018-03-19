#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "GObject.h"
class Player :              //玩家对象
	public GObject
{
protected:
	virtual void AchiveCtrl() override;

public:
	POINT GetPos();               //游戏是否结束
	bool IsOver();                   //玩家是否赢得游戏
	bool IsWin();                     //负责绘制自己
	void Draw(HDC &hdc);      //设置玩家下一步指令
	void SetTwCommand(TWARDS command); //设置玩家下一步指令
	Player(int x, int y) :GObject(x, y)
	{
		this->m_nSpeed = PLAYERSPEED;      //设置玩家速度
		m_cmd = m_dir = LEFT;                     //设置朝向
	}
	Player();
	~Player();
	void action();           //玩家的动作函数
	void SetOver();        //设置游戏结束函数
};
#endif