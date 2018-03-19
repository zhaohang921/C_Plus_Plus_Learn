#include "stdafx.h"
#include "GObject.h"

GMap *GObject::pStage = NULL;

int GObject::GetRow()      //返回行
{
	return m_nRow;
}
int GObject::GetArray()    //返回数组首地址
{
	return m_nArray;
}
int GObject::PtTransform(int k)       //将实际坐标转换为逻辑坐标
{
	return (k - (pStage->LD) / 2) / pStage->LD;
}
bool GObject::Achive()                   //判断物体是否到达逻辑坐标位置
{
	int n = (m_ptCenter.x - pStage->LD / 2) % pStage->LD;//计算x坐标的余数
	int k = (m_ptCenter.y - pStage->LD / 2) % pStage->LD;//计算y坐标的余数
	bool l = (n == 0 && k == 0);//如果两个余数都为0，说明到达中心位置
	return 1;
}
void GObject::AchiveCtrl()   //到达逻辑点后更新数据
{
	if (Achive())                                                     //如果到达逻辑坐标
	{
		m_nArray = PtTransform(m_ptCenter.x);           //更新列
		m_nRow = PtTransform(m_ptCenter.y);  //更新行
	}
}

void GObject::DrawBlank(HDC &hdc)                 //画空白
{
	// 申请资源,并交给智能指针处理
	HBRUSH hbr = ::CreateSolidBrush(RGB(255, 255, 255));         //创建画刷，绘制矩形函数要求使用
	std::shared_ptr<HBRUSH> phbr(&hbr, [](auto hbr) {
		// 离开 DrawBlank函数时,会自动调用释放资源
		DeleteObject(hbr);		
	});
	RECT rect;
	rect.top = m_nY - RD;
	rect.left = m_nX - RD;
	rect.right = m_nX + RD;
	rect.bottom = m_nY + RD;
	// 埴充
	FillRect(hdc, &rect, *phbr);
}

void GObject::SetPosition(int Row, int Array)      //设置中心位置
{
	m_nRow = Row;
	m_nArray = Array;
	this->m_ptCenter.y = m_nRow * pStage->LD + pStage->LD / 2;
	this->m_ptCenter.x = m_nArray * pStage->LD + pStage->LD / 2;
}

bool GObject::Collision()                 //逻辑碰撞检测，将物体摆放到合理的位置
{
	bool b = false;

	//更新行、列的数据若是大嘴,则会执行PacMan重写的AchiveCtrl函数消除豆子
	AchiveCtrl();
	//判断指令的有效性
	if (m_nArray < 0 || m_nRow < 0 || m_nArray > MAPLENTH - 1 || m_nRow > MAPLENTH - 1) 
		b = true;
	else if (Achive()) {
		switch (m_cmd) {  //判断行进的方向
		case LEFT:
			//判断下一个格子是否能够通行
			if (m_nArray > 0 &&
				!pStage->mapData[m_nRow][m_nArray - 1]) {
				b = true;//指令无效
			}
			break;
			//以下方向的判断原理相同
		case RIGHT:
			if (m_nArray < MAPLENTH - 1 &&
				!pStage->mapData[m_nRow][m_nArray + 1]) {
				b = true;
			}
			break;
		case UP:
			if (m_nRow > 0 &&
				!pStage->mapData[m_nRow - 1][m_nArray]) {
				b = true;
			}
			break;
		case DOWN:
			if (m_nRow < MAPLENTH - 1 &&
				!pStage->mapData[m_nRow + 1][m_nArray]) {
				b = true;
			}
			break;
		}
		if (!b) 
			m_dir = m_cmd; //没撞墙,指令成功	
	}
	//依照真实的方向位移
	m_nX = m_ptCenter.x;
	m_nY = m_ptCenter.y;
	int MAX = pStage->LD * MAPLENTH + pStage->LD / 2;
	int MIN = pStage->LD / 2;
	switch (m_dir) {  //判断行进的方向
	case LEFT:
		//判断下一个格子是否能够通行
		if (m_nArray > 0 &&
			!pStage->mapData[m_nRow][m_nArray - 1]) {
			b = true;
			break;//"撞墙了"
		}
		m_ptCenter.x -= m_nSpeed;
		if (m_ptCenter.x < MIN) 
			m_ptCenter.x = MAX;		
		break;
		//以下方向的判断原理相同
	case RIGHT:
		if (m_nArray < MAPLENTH - 1 &&
			!pStage->mapData[m_nRow][m_nArray + 1]) {
			b = true;
			break;//"撞墙了"
		}
		m_ptCenter.x += m_nSpeed;
		if (m_ptCenter.x > MAX) 
			m_ptCenter.x = MIN;
		break;
	case UP:
		if (m_nRow > 0 &&
			!pStage->mapData[m_nRow - 1][m_nArray]) {
			b = true;
			break;//"撞墙了"
		}
		m_ptCenter.y -= m_nSpeed;
		if (m_ptCenter.y < MIN) 
			m_ptCenter.y = MAX;	
		break;
	case DOWN:
		if (m_nRow < MAPLENTH - 1 &&
			!pStage->mapData[m_nRow + 1][m_nArray]) {
			b = true;
			break;//"撞墙了"
		}
		m_ptCenter.y += m_nSpeed;
		if (m_ptCenter.y > MAX) 
			m_ptCenter.y = MIN;	
		break;
	}
	return b;
}

