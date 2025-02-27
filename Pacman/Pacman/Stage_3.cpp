#include "stdafx.h"
#include "Stage_3.h"
#define A true
#define B false
bool Stage_3::initData[MAPLENTH][MAPLENTH] =
{
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, //0
	A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, //1
	B, A, A, B, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B, //2
	B, A, B, B, A, A, A, A, A, A, A, A, B, A, A, A, B, A, B, //3
	B, A, B, A, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B, //4
	B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B, //5
	B, A, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, B, //6
	B, A, B, A, B, A, A, A, A, A, A, A, A, B, A, A, B, A, B, //7
	B, A, B, A, B, B, A, A, B, A, B, A, A, B, A, A, B, A, B, //8
	B, A, A, A, A, B, A, A, B, B, B, A, A, B, A, A, B, A, B, //9
	B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, //10
	B, A, B, A, A, B, A, A, A, A, A, A, B, B, B, A, B, A, B, //11
	B, A, B, A, A, B, A, B, B, B, B, B, B, A, B, A, B, A, B, //12
	B, A, B, A, A, B, A, A, A, A, A, A, A, A, B, A, B, A, B, //13
	B, A, B, B, A, B, B, B, B, B, B, A, B, A, B, A, B, A, B, //14
	B, A, A, A, A, B, A, A, A, A, A, A, B, A, B, A, B, A, B, //15
	B, B, B, B, B, B, A, A, B, B, B, A, B, A, B, A, B, A, B, //16
	A, A, A, A, A, A, A, A, B, A, A, A, A, A, B, A, A, A, A, //17
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, //18
};

Stage_3::Stage_3()
{
	color = RGB(100,44,100);         //墙的颜色
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			this->mapData[i][j] = this->initData[i][j];
			this->peaMapData[i][j] = this->initData[i][j];
		}
	}
	//敌我双方出现的位置没有豆子出现
	this->InitOP();
}


Stage_3::~Stage_3()
{
}
