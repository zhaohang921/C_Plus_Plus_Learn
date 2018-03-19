#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "GObject.h"
class Player :              //��Ҷ���
	public GObject
{
protected:
	virtual void AchiveCtrl() override;

public:
	POINT GetPos();               //��Ϸ�Ƿ����
	bool IsOver();                   //����Ƿ�Ӯ����Ϸ
	bool IsWin();                     //��������Լ�
	void Draw(HDC &hdc);      //���������һ��ָ��
	void SetTwCommand(TWARDS command); //���������һ��ָ��
	Player(int x, int y) :GObject(x, y)
	{
		this->m_nSpeed = PLAYERSPEED;      //��������ٶ�
		m_cmd = m_dir = LEFT;                     //���ó���
	}
	Player();
	~Player();
	void action();           //��ҵĶ�������
	void SetOver();        //������Ϸ��������
};
#endif