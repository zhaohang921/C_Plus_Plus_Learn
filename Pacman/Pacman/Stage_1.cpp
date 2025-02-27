#include "stdafx.h"
#include "Stage_1.h"
#define A true      //true表示豆子
#define B false     //false表示墙壁
bool Stage_1::initData[MAPLENTH][MAPLENTH]=
{
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, //0
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, //1
	B, A, A, B, A, A, B, B, B, A, B, B, B, A, A, B, A, A, B, //2
	B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B, //3
	B, A, B, A, A, A, B, B, B, A, B, B, B, A, A, A, B, A, B, //4
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, //5
	B, A, A, A, A, A, B, B, A, A, A, B, B, A, A, A, A, A, B, //6
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, //7
	B, A, B, A, A, A, A, A, B, A, B, A, A, A, A, A, B, A, B, //8
	A, A, A, A, A, A, A, A, B, B, B, A, A, A, A, A, A, A, A, //9
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, //10
	B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, B, A, B, //11
	B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B, //12
	B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, //13
	B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B, //14
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, //15
	B, A, A, A, A, B, B, B, A, B, A, B, B, B, A, A, A, A, B, //16
	B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, //17
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, //18
};


Stage_1::Stage_1()
{
	color = RGB(140, 240, 240);         //墙的颜色
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


Stage_1::~Stage_1()
{
}
