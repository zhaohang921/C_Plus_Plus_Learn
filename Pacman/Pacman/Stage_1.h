#pragma once
#ifndef STAGE_1_H
#define STAGE_1_H
//��һ��
#include "GMap.h"
class Stage_1 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //��ͼ����
public:
	Stage_1();
	~Stage_1();
};
#endif

