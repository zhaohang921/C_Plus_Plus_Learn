#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}
//Player成员定义
void Player::AchiveCtrl()
{
	GObject::AchiveCtrl();
	if (Achive()) {
		if (m_nRow >= 0 && m_nRow < MAPLENTH &&
			m_nArray >= 0 && m_nArray < MAPLENTH) {  //防止数组越界
			if (pStage->peaMapData[m_nRow][m_nArray]) {
				pStage->peaMapData[m_nRow][m_nArray] = false;
			}			
		}
	}
}

void Player::action()
{
	Collision();                     //进行碰撞检测
}

void Player::SetTwCommand(TWARDS command)
{
	m_cmd = command;
}
bool Player::IsOver()
{
	return m_dir == OVER;
}

bool Player::IsWin()
{
	for (int i = 0; i <= MAPLENTH; i++) {
		for (int j = 0; j <= MAPLENTH; j++) {
			if (pStage->peaMapData[i][j] == true) {
				return false; //存在任意一个豆子,没取得胜利
			}
		}
	}
	return true;//没有豆子,胜利
}
POINT Player::GetPos()
{
	return m_ptCenter;           //返回对象的中心位置
}

void Player::SetOver()
{
	m_dir = OVER;           //设置游戏结束
}

void Player::Draw(HDC &memDC)
{
	if (m_dir == OVER) {
		                                               //游戏结束，什么也不干
	}
	else if (m_nFrame % 2 == 0) {  //第4帧动画与第2帧动画：张嘴形状
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		int offsetX = DISTANCE / 2 + D_OFFSET; //弧弦交点X
		int offsetY = DISTANCE / 2 + D_OFFSET; //弧弦交点Y
		switch (m_dir) {
		case UP:                                                        //向上移动
			x1 = m_ptCenter.x - offsetX;
			x2 = m_ptCenter.x + offsetX;
			y2 = y1 = m_ptCenter.y - offsetY;
			break;
		case DOWN:                                                 //向下移动
			x1 = m_ptCenter.x + offsetX;
			x2 = m_ptCenter.x - offsetX;
			y2 = y1 = m_ptCenter.y + offsetY;
			break;
		case LEFT:                                                      //向左移动
			x2 = x1 = m_ptCenter.x - offsetX;
			y1 = m_ptCenter.y + offsetY;
			y2 = m_ptCenter.y - offsetY;
			break;
		case RIGHT:                                                   //向右移动
			x2 = x1 = m_ptCenter.x + offsetX;
			y1 = m_ptCenter.y - offsetY;
			y2 = m_ptCenter.y + offsetY;
			break;

		}
		//画出弧线部分
		Arc(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE,
			x1, y1,
			x2, y2);
		//画直线部分，最后组合成玩家对象；一个大嘴的形象
		MoveToEx(memDC, x1, y1, NULL);
		LineTo(memDC, m_ptCenter.x, m_ptCenter.y);
		LineTo(memDC, x2, y2);
	}
	else if (m_nFrame % 3 == 0) {         //第3帧动画：画出整个圆形
		Ellipse(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE);
	}
	else {                                                  //嘴巴完全张开的形状
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		switch (m_dir) {
		case UP:                                          //向上移动
			x1 = m_ptCenter.x - DISTANCE;
			x2 = m_ptCenter.x + DISTANCE;
			y2 = y1 = m_ptCenter.y;
			break;
		case DOWN:                                    //向下移动
			x1 = m_ptCenter.x + DISTANCE; 
			x2 = m_ptCenter.x - DISTANCE;
			y2 = y1 = m_ptCenter.y;
			break;
		case LEFT:                                        //向左移动
			x2 = x1 = m_ptCenter.x;
			y1 = m_ptCenter.y + DISTANCE;
			y2 = m_ptCenter.y - DISTANCE;
			break;
		case RIGHT:                                    //向右移动
			x2 = x1 = m_ptCenter.x;
			y1 = m_ptCenter.y - DISTANCE;
			y2 = m_ptCenter.y + DISTANCE;
			break;

		}
		//画出弧线部分
		Arc(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE,
			x1, y1,
			x2, y2);
		//画直线部分，最后组合成玩家对象：一个大嘴形象
		MoveToEx(memDC, x1, y1, NULL);
		LineTo(memDC, m_ptCenter.x, m_ptCenter.y);
		LineTo(memDC, x2, y2);
	}
	m_nFrame++;//绘制下一帧
}