#pragma once
#ifndef STAGE_2_H
#define STAGE_2_H
//第二关
#include "GMap.h"
class Stage_2 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //地图数据
public:
	Stage_2();
	~Stage_2();
};
#endif

