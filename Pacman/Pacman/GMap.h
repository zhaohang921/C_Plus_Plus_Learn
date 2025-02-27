#pragma once
#ifndef GMAP_H
#define GMAP_H
#include<list>
#define MAPLENTH 19     //逻辑地图大小
#define P_ROW 10           //我方位置坐标
#define P_ARRAY 9          //我方位置坐标
#define E_ROW 8             //敌方位置坐标
#define E_ARRAY 9          //敌方位置坐标
class GMap
{
protected:
	static int LD;															 //障碍物的尺寸，墙的宽度
	static int PD;															 //豆子的半径
	void InitOP();														 //敌我双方出现位置没有豆子出现
	bool mapData[MAPLENTH][MAPLENTH];				 //障碍物逻辑地图点阵
	bool peaMapData[MAPLENTH][MAPLENTH];         //豆子逻辑地图点阵
	COLORREF color;                                                  //地图中墙的颜色
public:
	void DrawMap(HDC &hdc);                                  //绘制地图
	void DrawPeas(HDC &hdc);                                  //绘制豆子
	
	GMap() {}
	virtual ~GMap() {}
	friend class GObject;          //允许物体类使用直线的起点和终点的信息做碰撞检测
	friend class Player;            //允许玩家“大嘴”访问豆子地图
};
#endif
