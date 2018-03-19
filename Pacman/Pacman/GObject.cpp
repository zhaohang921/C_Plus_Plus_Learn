#include "stdafx.h"
#include "GObject.h"

GMap *GObject::pStage = NULL;

int GObject::GetRow()      //������
{
	return m_nRow;
}
int GObject::GetArray()    //���������׵�ַ
{
	return m_nArray;
}
int GObject::PtTransform(int k)       //��ʵ������ת��Ϊ�߼�����
{
	return (k - (pStage->LD) / 2) / pStage->LD;
}
bool GObject::Achive()                   //�ж������Ƿ񵽴��߼�����λ��
{
	int n = (m_ptCenter.x - pStage->LD / 2) % pStage->LD;//����x���������
	int k = (m_ptCenter.y - pStage->LD / 2) % pStage->LD;//����y���������
	bool l = (n == 0 && k == 0);//�������������Ϊ0��˵����������λ��
	return 1;
}
void GObject::AchiveCtrl()   //�����߼�����������
{
	if (Achive())                                                     //��������߼�����
	{
		m_nArray = PtTransform(m_ptCenter.x);           //������
		m_nRow = PtTransform(m_ptCenter.y);  //������
	}
}

void GObject::DrawBlank(HDC &hdc)                 //���հ�
{
	// ������Դ,����������ָ�봦��
	HBRUSH hbr = ::CreateSolidBrush(RGB(255, 255, 255));         //������ˢ�����ƾ��κ���Ҫ��ʹ��
	std::shared_ptr<HBRUSH> phbr(&hbr, [](auto hbr) {
		// �뿪 DrawBlank����ʱ,���Զ������ͷ���Դ
		DeleteObject(hbr);		
	});
	RECT rect;
	rect.top = m_nY - RD;
	rect.left = m_nX - RD;
	rect.right = m_nX + RD;
	rect.bottom = m_nY + RD;
	// ����
	FillRect(hdc, &rect, *phbr);
}

void GObject::SetPosition(int Row, int Array)      //��������λ��
{
	m_nRow = Row;
	m_nArray = Array;
	this->m_ptCenter.y = m_nRow * pStage->LD + pStage->LD / 2;
	this->m_ptCenter.x = m_nArray * pStage->LD + pStage->LD / 2;
}

bool GObject::Collision()                 //�߼���ײ��⣬������ڷŵ������λ��
{
	bool b = false;

	//�����С��е��������Ǵ���,���ִ��PacMan��д��AchiveCtrl������������
	AchiveCtrl();
	//�ж�ָ�����Ч��
	if (m_nArray < 0 || m_nRow < 0 || m_nArray > MAPLENTH - 1 || m_nRow > MAPLENTH - 1) 
		b = true;
	else if (Achive()) {
		switch (m_cmd) {  //�ж��н��ķ���
		case LEFT:
			//�ж���һ�������Ƿ��ܹ�ͨ��
			if (m_nArray > 0 &&
				!pStage->mapData[m_nRow][m_nArray - 1]) {
				b = true;//ָ����Ч
			}
			break;
			//���·�����ж�ԭ����ͬ
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
			m_dir = m_cmd; //ûײǽ,ָ��ɹ�	
	}
	//������ʵ�ķ���λ��
	m_nX = m_ptCenter.x;
	m_nY = m_ptCenter.y;
	int MAX = pStage->LD * MAPLENTH + pStage->LD / 2;
	int MIN = pStage->LD / 2;
	switch (m_dir) {  //�ж��н��ķ���
	case LEFT:
		//�ж���һ�������Ƿ��ܹ�ͨ��
		if (m_nArray > 0 &&
			!pStage->mapData[m_nRow][m_nArray - 1]) {
			b = true;
			break;//"ײǽ��"
		}
		m_ptCenter.x -= m_nSpeed;
		if (m_ptCenter.x < MIN) 
			m_ptCenter.x = MAX;		
		break;
		//���·�����ж�ԭ����ͬ
	case RIGHT:
		if (m_nArray < MAPLENTH - 1 &&
			!pStage->mapData[m_nRow][m_nArray + 1]) {
			b = true;
			break;//"ײǽ��"
		}
		m_ptCenter.x += m_nSpeed;
		if (m_ptCenter.x > MAX) 
			m_ptCenter.x = MIN;
		break;
	case UP:
		if (m_nRow > 0 &&
			!pStage->mapData[m_nRow - 1][m_nArray]) {
			b = true;
			break;//"ײǽ��"
		}
		m_ptCenter.y -= m_nSpeed;
		if (m_ptCenter.y < MIN) 
			m_ptCenter.y = MAX;	
		break;
	case DOWN:
		if (m_nRow < MAPLENTH - 1 &&
			!pStage->mapData[m_nRow + 1][m_nArray]) {
			b = true;
			break;//"ײǽ��"
		}
		m_ptCenter.y += m_nSpeed;
		if (m_ptCenter.y > MAX) 
			m_ptCenter.y = MIN;	
		break;
	}
	return b;
}

