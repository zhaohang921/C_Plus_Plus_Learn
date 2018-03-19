#include "stdafx.h"
#include "Enermy.h"
std::shared_ptr<Player> Enermy::player = nullptr;
// ץס����Ϸ����
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
		m_ptCenter.x - DISTANCE, m_ptCenter.y); //��Բ�͵�ͷ
	int const LEGLENTH = (DISTANCE) / (LEGCOUNTS);
	//����֡������������͡��Ȳ���
	if (m_nFrame % 2 == 0) {
		//���ε�����
		MoveToEx(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x - DISTANCE,
			m_ptCenter.y + DISTANCE - LEGLENTH);
		MoveToEx(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x + DISTANCE,
			m_ptCenter.y + DISTANCE - LEGLENTH);
		for (int i = 0; i < LEGCOUNTS; i++) {  //�������һ��ơ��Ȳ���
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
		MoveToEx(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y, NULL);   //��������
		LineTo(hdc, m_ptCenter.x - DISTANCE, m_ptCenter.y + DISTANCE);
		MoveToEx(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y, NULL);
		LineTo(hdc, m_ptCenter.x + DISTANCE, m_ptCenter.y + DISTANCE);

		MoveToEx(hdc, m_ptCenter.x - DISTANCE,
			m_ptCenter.y + DISTANCE, NULL);
		LineTo(hdc, m_ptCenter.x - DISTANCE + LEGLENTH,
			m_ptCenter.y + DISTANCE - LEGLENTH);

		for (int i = 0; i < LEGCOUNTS - 1; i++) {          		//�������һ��ơ��Ȳ���
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
	//���ݷ�������۾�
	int R = DISTANCE / 5; //�۾��İ뾶
	switch (m_dir) {
	case UP:
		Ellipse(hdc, m_ptCenter.x - 2 * R, m_ptCenter.y - 2 * R,//������
			m_ptCenter.x, m_ptCenter.y);
		Ellipse(hdc, m_ptCenter.x, m_ptCenter.y - 2 * R,           //������
			m_ptCenter.x + 2 * R, m_ptCenter.y);
		break;
	case DOWN:
		Ellipse(hdc, m_ptCenter.x - 2 * R, m_ptCenter.y,            //������
			m_ptCenter.x, m_ptCenter.y + 2 * R);
		Ellipse(hdc, m_ptCenter.x, m_ptCenter.y,                      //������
			m_ptCenter.x + 2 * R, m_ptCenter.y + 2 * R); 
		break;
	case LEFT:
		Ellipse(hdc, m_ptCenter.x - 3 * R, m_ptCenter.y - R,      //������
			m_ptCenter.x - R, m_ptCenter.y + R);
		Ellipse(hdc, m_ptCenter.x - R, m_ptCenter.y - R,           //������
			m_ptCenter.x + R, m_ptCenter.y + R);
		break;
	case RIGHT:
		Ellipse(hdc, m_ptCenter.x - R, m_ptCenter.y - R,         //������
			m_ptCenter.x + R, m_ptCenter.y + R);
		Ellipse(hdc, m_ptCenter.x + R, m_ptCenter.y - R,        //������
			m_ptCenter.x + 3 * R, m_ptCenter.y + R);
		break;
	}

	m_nFrame++; //׼��������һ֡
	SelectObject(hdc, oldPen);//��ԭ����
	DeleteObject(pen);       //ɾ�����ʶ���
	return;
}
void Enermy::action()
{
	bool b = Collision();          //�ж��Ƿ�����ײ
	MakeDecision(b);             //�趨����
	Catch();                            //��ʼץ��
}

//RedOne��Ա
void RedOne::Draw(HDC &hdc)
{
	Enermy::Draw(hdc);
}
void RedOne::MakeDecision(bool b)
{
	//srand(time(0));
	int i = rand();
	if (b) 
	{  //ײ��ǽ��,�ı䷽��
			  //��ʱ��ת��
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

//BlueOne��Ա����
void BlueOne::Draw(HDC &hdc)
{
	Enermy::Draw(hdc);
}

void BlueOne::MakeDecision(bool b)
{

	const int DR = this->m_nRow - player->GetRow();
	const int DA = this->m_nArray - player->GetArray();
	if (!b && DR == 0) {
		if (DA <= BLUE_ALERT && DA > 0) {  //��������߾��䷶Χs
			m_cmd = LEFT;   //�����ƶ�
			return;
		}
		if (DA < 0 && DA >= -BLUE_ALERT) {  //�Ҳྯ�䷶Χ
			m_cmd = RIGHT;//�����ƶ�
			return;
		}
	}
	if (!b && DA == 0) {
		if (DR <= BLUE_ALERT && DR > 0) {  //�·����䷶Χ
			m_cmd = UP;
			return;
		}
		if (DR < 0 && DR >= -BLUE_ALERT) {  //�Ϸ����䷶Χ
			m_cmd = DOWN;
			return;
		}
	}

	RedOne::MakeDecision(b);  //����׷��ģʽʱRED��Ϊ��ͬ
}

//YellowOne��Ա����
void YellowOne::MakeDecision(bool b)
{
	const int DR = this->m_nRow - player->GetRow();
	const int DA = this->m_nArray - player->GetArray();
	if (!b) {
		if (DR * DR > DA * DA) {
			if (DA > 0) {  //��������߾��䷶Χ
				m_cmd = LEFT;   //�����ƶ�
				return;
			}
			else if (DA < 0) {  //�Ҳྯ�䷶Χ
				m_cmd = RIGHT;//�����ƶ�
				return;
			}
		}
		else {
			if (DR > 0) {  //�·����䷶Χ
				m_cmd = UP;
				return;
			}
			if (DR < 0) {  //�Ϸ����䷶Χ
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