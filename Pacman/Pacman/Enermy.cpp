#include "stdafx.h"
#include "Enermy.h"
std::shared_ptr<Player> Enermy::player = nullptr;
// 抓住，游戏结束
void Enermy::Catch()
{
	int DX = m_ptCenter.x - player->GetPos().x;
	int DY = m_ptCenter.y - player->GetPos().y;
	if ((-RD < DX && DX < RD) && (-RD < DY && DY < RD)) {
		player->SetOver();
	}
}

void Enermy::Draw(HDC &hdc)
{
	HPEN pen = ::CreatePen(0, 0, color);
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	Arc(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
		m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE,
		m_ptCenter.x + DISTANCE, m_ptCenter.y,
		m_ptCenter.x - DISTANCE, m_ptCenter.y); //半圆型的头
	int const LEGLENTH = (DISTANCE) / (LEGCOUNTS);
	//根据帧数来绘制身体和“腿部”
	if (m_nFrame % 2 == 0) {
		//矩形的身子
		MoveToEx(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x - DISTANCE,
			m_ptCenter.y + DISTANCE - LEGLENTH);
		MoveToEx(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x + DISTANCE,
			m_ptCenter.y + DISTANCE - LEGLENTH);
		for (int i = 0; i < LEGCOUNTS; i++) {  //从左往右绘制“腿部”
			Arc(hdc,
				m_ptCenter.x - DISTANCE + i * 2 * LEGLENTH,
				m_ptCenter.y + DISTANCE - 2 * LEGLENTH,
				m_ptCenter.x - DISTANCE + (i + 1) * 2 * LEGLENTH,
				m_ptCenter.y + DISTANCE,
				m_ptCenter.x - DISTANCE + i * 2 * LEGLENTH,
				m_ptCenter.y + DISTANCE - LEGLENTH,
				m_ptCenter.x - DISTANCE + (i + 1) * 2 * LEGLENTH,
				m_ptCenter.y + DISTANCE - LEGLENTH
			);
		}
	}
	else {
		MoveToEx(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y, NULL);   //绘制身体
		LineTo(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y + DISTANCE);
		MoveToEx(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE);

		MoveToEx(hdc, m_ptCenter.x - DISTANCE,
			m_ptCenter.y + DISTANCE, NULL);
		LineTo(hdc, m_ptCenter.x - DISTANCE + LEGLENTH,
			m_ptCenter.y + DISTANCE - LEGLENTH);

		for (int i = 0; i < LEGCOUNTS - 1; i++) {          		//从左往右绘制“腿部”
			Arc(hdc,
				m_ptCenter.x - DISTANCE + (1 + i * 2)*LEGLENTH,
				m_ptCenter.y + DISTANCE - 2 * LEGLENTH,
				m_ptCenter.x - DISTANCE + (3 + i * 2)*LEGLENTH,
				m_ptCenter.y + DISTANCE,
				m_ptCenter.x - DISTANCE + (1 + i * 2)*LEGLENTH,
				m_ptCenter.y + DISTANCE - LEGLENTH,
				m_ptCenter.x - DISTANCE + (3 + i * 2)*LEGLENTH,
				m_ptCenter.y + DISTANCE - LEGLENTH
			);
		}

		MoveToEx(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE, NULL);
		LineTo(hdc, m_ptCenter.x + DISTANCE - LEGLENTH,
			m_ptCenter.y + DISTANCE - LEGLENTH);
	}
	//根据方向绘制眼睛
	int R = DISTANCE / 5; //眼睛的半径
	switch (m_dir) {
	case UP:
		Ellipse(hdc, m_ptCenter.x - 2 * R, m_ptCenter.y - 2 * R,//画左眼
			m_ptCenter.x, m_ptCenter.y);
		Ellipse(hdc, m_ptCenter.x, m_ptCenter.y - 2 * R,           //画右眼
			m_ptCenter.x + 2 * R, m_ptCenter.y);
		break;
	case DOWN:
		Ellipse(hdc, m_ptCenter.x - 2 * R, m_ptCenter.y,            //画左眼
			m_ptCenter.x, m_ptCenter.y + 2 * R);
		Ellipse(hdc, m_ptCenter.x, m_ptCenter.y,                      //画右眼
			m_ptCenter.x + 2 * R, m_ptCenter.y + 2 * R); 
		break;
	case LEFT:
		Ellipse(hdc, m_ptCenter.x - 3 * R, m_ptCenter.y - R,      //画左眼
			m_ptCenter.x - R, m_ptCenter.y + R);
		Ellipse(hdc, m_ptCenter.x - R, m_ptCenter.y - R,           //画右眼
			m_ptCenter.x + R, m_ptCenter.y + R);
		break;
	case RIGHT:
		Ellipse(hdc, m_ptCenter.x - R, m_ptCenter.y - R,         //画左眼
			m_ptCenter.x + R, m_ptCenter.y + R);
		Ellipse(hdc, m_ptCenter.x + R, m_ptCenter.y - R,        //画右眼
			m_ptCenter.x + 3 * R, m_ptCenter.y + R);
		break;
	}

	m_nFrame++; //准备绘制下一帧
	SelectObject(hdc, oldPen);//还原画笔
	DeleteObject(pen);       //删除画笔对象
	return;
}
void Enermy::action()
{
	bool b = Collision();          //判断是否发生碰撞
	MakeDecision(b);             //设定方向
	Catch();                            //开始抓捕
}

//RedOne成员
void RedOne::Draw(HDC &hdc)
{
	Enermy::Draw(hdc);
}
void RedOne::MakeDecision(bool b)
{
	//srand(time(0));
	int i = rand();
	if (b) 
	{  //撞到墙壁,改变方向
			  //逆时针转向
		if (i % 4 == 0) 
			m_dir == UP ? m_cmd = LEFT : m_cmd = UP;
		else if (i % 3 == 0) 
			m_dir == DOWN ? m_cmd = RIGHT : m_cmd = DOWN;
		else if (i % 2 == 0) 
			m_dir == RIGHT ? m_cmd = UP : m_cmd = RIGHT;
		else 
			m_dir == LEFT ? m_cmd = DOWN : m_cmd = LEFT;
		return;
	}
	if (i % 4 == 0)	
		m_cmd != UP ? m_dir == DOWN : m_cmd == UP;	
	else if (i % 3 == 0) 
		m_dir != DOWN ? m_cmd = UP : m_cmd = DOWN;
	else if (i % 2 == 0) 
		m_dir != RIGHT ? m_cmd = LEFT : m_cmd = RIGHT;
	else 
		m_dir != LEFT ? m_cmd = RIGHT : m_cmd = LEFT;	
}

//BlueOne成员定义
void BlueOne::Draw(HDC &hdc)
{
	Enermy::Draw(hdc);
}

void BlueOne::MakeDecision(bool b)
{

	const int DR = this->m_nRow - player->GetRow();
	const int DA = this->m_nArray - player->GetArray();
	if (!b && DR == 0) {
		if (DA <= BLUE_ALERT && DA > 0) {  //玩家在左侧边警戒范围s
			m_cmd = LEFT;   //向左移动
			return;
		}
		if (DA < 0 && DA >= -BLUE_ALERT) {  //右侧警戒范围
			m_cmd = RIGHT;//向右移动
			return;
		}
	}
	if (!b && DA == 0) {
		if (DR <= BLUE_ALERT && DR > 0) {  //下方警戒范围
			m_cmd = UP;
			return;
		}
		if (DR < 0 && DR >= -BLUE_ALERT) {  //上方警戒范围
			m_cmd = DOWN;
			return;
		}
	}

	RedOne::MakeDecision(b);  //不在追踪模式时RED行为相同
}

//YellowOne成员定义
void YellowOne::MakeDecision(bool b)
{
	const int DR = this->m_nRow - player->GetRow();
	const int DA = this->m_nArray - player->GetArray();
	if (!b) {
		if (DR * DR > DA * DA) {
			if (DA > 0) {  //玩家在左侧边警戒范围
				m_cmd = LEFT;   //向左移动
				return;
			}
			else if (DA < 0) {  //右侧警戒范围
				m_cmd = RIGHT;//向右移动
				return;
			}
		}
		else {
			if (DR > 0) {  //下方警戒范围
				m_cmd = UP;
				return;
			}
			if (DR < 0) {  //上方警戒范围
				m_cmd = DOWN;
				return;
			}
		}
	}
	RedOne::MakeDecision(b);
}
void YellowOne::Draw(HDC &hdc)
{
	Enermy::Draw(hdc);
}