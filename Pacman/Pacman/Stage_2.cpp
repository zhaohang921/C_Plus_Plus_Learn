#include "stdafx.h"
#include "Stage_2.h"

#define A true
#define B false

bool Stage_2::initData[MAPLENTH][MAPLENTH]=
{
	B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B, //0
	A, A, A, A, A, A, A, B, A, A, B, A, A, A, B, A, B, A, A, //1
	B, A, A, A, B, A, A, B, A, A, B, A, B, A, B, A, B, A, B, //2
	B, B, B, A, B, A, A, B, B, A, B, A, B, A, B, A, B, B, B, //3
	B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, A, A, A, B, //4
	B, A, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, //5
	B, A, A, B, A, A, A, B, B, B, B, B, B, A, A, B, A, A, B, //6
	B, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, A, B, //7
	B, A, A, B, A, B, A, A, B, A, B, A, A, B, A, B, A, A, B, //8
	A, A, A, B, A, B, A, A, B, B, B, A, A, B, A, B, A, A, A, //9
	B, A, A, B, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, //10
	B, A, A, B, A, A, A, B, B, B, B, B, A, B, A, A, A, A, B, //11
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, //12
	B, A, A, A, B, B, B, B, B, B, B, A, A, A, A, A, A, A, B, //13
	B, A, A, A, A, A, A, A, A, A, A, A, A, B, A, A, A, A, B, //14
	B, B, B, B, B, A, A, A, A, B, B, B, A, B, A, A, A, A, B, //15
	B, A, A, A, B, B, B, A, A, A, A, B, A, B, B, B, A, A, B, //16
	A, A, A, A, B, A, A, A, A, A, A, B, A, A, A, B, A, A, A, //17
	B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B, //18
};

Stage_2::Stage_2()
{
	color = RGB(240,140,140);         //ǽ����ɫ
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			this->mapData[i][j] = this->initData[i][j];
			this->peaMapData[i][j] = this->initData[i][j];
		}
	}
	//����˫�����ֵ�λ��û�ж��ӳ���
	this->InitOP();
}


Stage_2::~Stage_2()
{
}
