#pragma once
#ifndef STAGE_1_H
#define STAGE_1_H
//第一关
#include "GMap.h"
class Stage_1 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //地图数据
public:
	Stage_1();
	~Stage_1();
};
#endif

