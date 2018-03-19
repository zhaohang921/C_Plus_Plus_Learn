#pragma once
#ifndef GOBJECT_H
#define GOBJECT_H
#include"stdafx.h"
#include<time.h>
#include"GMap.h"

#define PLAYERSPEED 6                     //����ٶ�
#define ENERMYSPEED 4                //�����ٶ�
#define LEGCOUNTS 5                        //�����ȵ�����
#define DISTANCE 10                   //ͼ�η�Χ
#define BLUE_ALERT 8                  //��ɫ���䷶Χ
#define D_OFFSET 2                     //��ͼ���
#define RD (DISTANCE+D_OFFSET)    //��ͼ��Χ

enum TWARDS {       //����ö��
	UP,
	DOWN,
	LEFT,
	RIGHT,
	OVER,           //��Ϸ����
};
class GObject
{
public:
	GObject() {}
	GObject(int Row, int Array)
	{
		m_nFrame = 1;                   //֡��
		pStage = NULL;                 //��ǰ�ؿ�
		this->m_nRow = Row;        //��
		this->m_nArray = Array;    //����
		//����λ��
		this->m_ptCenter.y = m_nRow * pStage->LD + pStage->LD / 2;
		this->m_ptCenter.x = m_nArray * pStage->LD + pStage->LD / 2;
		this->m_nX = m_ptCenter.x;
		this->m_nY = m_ptCenter.y;
	}
	void SetPosition(int Row, int Array);      //����λ��
	void DrawBlank(HDC &hdc);                 //���հ�
	void virtual Draw(HDC &hdc) = 0;         //���ƶ���
	void virtual action() = 0;                       //���ݱ���ı���

	int GetRow();
	int GetArray();
	~GObject() {}
	
	static GMap *pStage;   //ָ���ͼ���ָ�룬����Ϊ��̬��ʹ������������ܹ�ʹ����ͬ�ĵ�ͼ
protected:
	int m_nX;
	int m_nY;
	TWARDS m_cmd;                //ָ���
	POINT m_ptCenter;             //��������
	int m_nRow;                       //�߼�������
	int m_nArray;                     //�߼�������
	int m_nSpeed;                    //�ٶ�
	TWARDS m_dir;                 //����
	int m_nFrame;                   //֡��
	bool Achive();                    //�ж������Ƿ񵽴��߼�����λ��
	bool Collision();                 //�߼���ײ��⣬������ڷŵ������λ��
	int PtTransform(int k);       //��ʵ������ת��Ϊ�߼�����
	virtual void AchiveCtrl();    //�����߼�����������
};

#endif
