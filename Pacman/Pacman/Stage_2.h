#pragma once
#ifndef STAGE_2_H
#define STAGE_2_H
//�ڶ���
#include "GMap.h"
class Stage_2 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //��ͼ����
public:
	Stage_2();
	~Stage_2();
};
#endif

