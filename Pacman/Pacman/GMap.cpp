#include "stdafx.h"
#include "GMap.h"

int GMap::LD = 36;       //墙的宽度
int GMap::PD = 3;         //豆子的直径

//敌我双方出现位置没有豆子出现
void GMap::InitOP()
{
	peaMapData[E_ROW][E_ARRAY] = false;   //敌方位置没有豆子
	peaMapData[P_ROW][P_ARRAY] = false;  //我方位置没有豆子
}

//绘制地图
void GMap::DrawMap(HDC &memDC)
{
	HBRUSH hBrush = CreateSolidBrush(color);
	for (int i = 0; i < MAPLENTH; i++)
	{
		for(int j=0;j<MAPLENTH;j++)
		{
			//绘制墙壁
			if (!mapData[i][j])
			{
				RECT rect;
				rect.left = j * LD;
				rect.top = i * LD;
				rect.right = (j + 1)*LD;
				rect.bottom = (i + 1)*LD;
				FillRect(memDC, &rect, hBrush);  //填充矩形区域，模拟墙体
			}
		}
	}
	DeleteObject(hBrush);//删除画刷对象
}

//绘制豆子
void GMap::DrawPeas(HDC &hdc)
{
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			if (peaMapData[i][j])
			{
				Ellipse(hdc, (LD / 2 - PD) + j * LD,   //画圆，模拟豆子
					(LD / 2 - PD) + i * LD,
					(LD / 2 + PD) + j * LD,
					(LD / 2 + PD) + i * LD);
			}
		}
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		MessageBoxA(NULL, "无意中发现了秘笈", "", MB_OK);
		for (int i = 0; i < MAPLENTH; i++)
		{
			for (int j = 0; j < MAPLENTH; j++)
			{
				peaMapData[i][j] = false;
			}
		}
	}
}


