#pragma once
#ifndef STAGE_3_H
#define STAGE_3_H
//������
#include "GMap.h"
class Stage_3 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //��ͼ����
public:
	Stage_3();
	~Stage_3();
};
#endif
