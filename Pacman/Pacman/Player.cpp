#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}
//Player��Ա����
void Player::AchiveCtrl()
{
	GObject::AchiveCtrl();
	if (Achive()) {
		if (m_nRow >= 0 && m_nRow < MAPLENTH &&
			m_nArray >= 0 && m_nArray < MAPLENTH) {  //��ֹ����Խ��
			if (pStage->peaMapData[m_nRow][m_nArray]) {
				pStage->peaMapData[m_nRow][m_nArray] = false;
			}			
		}
	}
}

void Player::action()
{
	Collision();                     //������ײ���
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
				return false; //��������һ������,ûȡ��ʤ��
			}
		}
	}
	return true;//û�ж���,ʤ��
}
POINT Player::GetPos()
{
	return m_ptCenter;           //���ض��������λ��
}

void Player::SetOver()
{
	m_dir = OVER;           //������Ϸ����
}

void Player::Draw(HDC &memDC)
{
	if (m_dir == OVER) {
		                                               //��Ϸ������ʲôҲ����
	}
	else if (m_nFrame % 2 == 0) {  //��4֡�������2֡������������״
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		int offsetX = DISTANCE / 2 + D_OFFSET; //���ҽ���X
		int offsetY = DISTANCE / 2 + D_OFFSET; //���ҽ���Y
		switch (m_dir) {
		case UP:                                                        //�����ƶ�
			x1 = m_ptCenter.x - offsetX;
			x2 = m_ptCenter.x + offsetX;
			y2 = y1 = m_ptCenter.y - offsetY;
			break;
		case DOWN:                                                 //�����ƶ�
			x1 = m_ptCenter.x + offsetX;
			x2 = m_ptCenter.x - offsetX;
			y2 = y1 = m_ptCenter.y + offsetY;
			break;
		case LEFT:                                                      //�����ƶ�
			x2 = x1 = m_ptCenter.x - offsetX;
			y1 = m_ptCenter.y + offsetY;
			y2 = m_ptCenter.y - offsetY;
			break;
		case RIGHT:                                                   //�����ƶ�
			x2 = x1 = m_ptCenter.x + offsetX;
			y1 = m_ptCenter.y - offsetY;
			y2 = m_ptCenter.y + offsetY;
			break;

		}
		//�������߲���
		Arc(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE,
			x1, y1,
			x2, y2);
		//��ֱ�߲��֣������ϳ���Ҷ���һ�����������
		MoveToEx(memDC, x1, y1, NULL);
		LineTo(memDC, m_ptCenter.x, m_ptCenter.y);
		LineTo(memDC, x2, y2);
	}
	else if (m_nFrame % 3 == 0) {         //��3֡��������������Բ��
		Ellipse(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE);
	}
	else {                                                  //�����ȫ�ſ�����״
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		switch (m_dir) {
		case UP:                                          //�����ƶ�
			x1 = m_ptCenter.x - DISTANCE;
			x2 = m_ptCenter.x + DISTANCE;
			y2 = y1 = m_ptCenter.y;
			break;
		case DOWN:                                    //�����ƶ�
			x1 = m_ptCenter.x + DISTANCE; 
			x2 = m_ptCenter.x - DISTANCE;
			y2 = y1 = m_ptCenter.y;
			break;
		case LEFT:                                        //�����ƶ�
			x2 = x1 = m_ptCenter.x;
			y1 = m_ptCenter.y + DISTANCE;
			y2 = m_ptCenter.y - DISTANCE;
			break;
		case RIGHT:                                    //�����ƶ�
			x2 = x1 = m_ptCenter.x;
			y1 = m_ptCenter.y - DISTANCE;
			y2 = m_ptCenter.y + DISTANCE;
			break;

		}
		//�������߲���
		Arc(memDC, m_ptCenter.x - DISTANCE, m_ptCenter.y - DISTANCE,
			m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE,
			x1, y1,
			x2, y2);
		//��ֱ�߲��֣������ϳ���Ҷ���һ����������
		MoveToEx(memDC, x1, y1, NULL);
		LineTo(memDC, m_ptCenter.x, m_ptCenter.y);
		LineTo(memDC, x2, y2);
	}
	m_nFrame++;//������һ֡
}