#pragma once
#ifndef GOBJECT_H
#define GOBJECT_H
#include"stdafx.h"
#include<time.h>
#include"GMap.h"

#define PLAYERSPEED 6                     //玩家速度
#define ENERMYSPEED 4                //敌人速度
#define LEGCOUNTS 5                        //敌人腿的数量
#define DISTANCE 10                   //图形范围
#define BLUE_ALERT 8                  //蓝色警戒范围
#define D_OFFSET 2                     //绘图误差
#define RD (DISTANCE+D_OFFSET)    //绘图范围

enum TWARDS {       //方向枚举
	UP,
	DOWN,
	LEFT,
	RIGHT,
	OVER,           //游戏结束
};
class GObject
{
public:
	GObject() {}
	GObject(int Row, int Array)
	{
		m_nFrame = 1;                   //帧数
		pStage = NULL;                 //当前关卡
		this->m_nRow = Row;        //行
		this->m_nArray = Array;    //数组
		//中心位置
		this->m_ptCenter.y = m_nRow * pStage->LD + pStage->LD / 2;
		this->m_ptCenter.x = m_nArray * pStage->LD + pStage->LD / 2;
		this->m_nX = m_ptCenter.x;
		this->m_nY = m_ptCenter.y;
	}
	void SetPosition(int Row, int Array);      //设置位置
	void DrawBlank(HDC &hdc);                 //画空白
	void virtual Draw(HDC &hdc) = 0;         //绘制对象
	void virtual action() = 0;                       //数据变更的表现

	int GetRow();
	int GetArray();
	~GObject() {}
	
	static GMap *pStage;   //指向地图类的指针，设置为静态，使所有子类对象都能够使用相同的地图
protected:
	int m_nX;
	int m_nY;
	TWARDS m_cmd;                //指令缓存
	POINT m_ptCenter;             //中心坐标
	int m_nRow;                       //逻辑横坐标
	int m_nArray;                     //逻辑纵坐标
	int m_nSpeed;                    //速度
	TWARDS m_dir;                 //朝向
	int m_nFrame;                   //帧数
	bool Achive();                    //判断物体是否到达逻辑坐标位置
	bool Collision();                 //逻辑碰撞检测，将物体摆放到合理的位置
	int PtTransform(int k);       //将实际坐标转换为逻辑坐标
	virtual void AchiveCtrl();    //到达逻辑点后更新数据
};

#endif
