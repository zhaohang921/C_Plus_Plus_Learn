#pragma once
#ifndef STAGE_3_H
#define STAGE_3_H
//第三关
#include "GMap.h"
class Stage_3 :
	public GMap
{
private:
	bool static initData[MAPLENTH][MAPLENTH]; //地图数据
public:
	Stage_3();
	~Stage_3();
};
#endif
