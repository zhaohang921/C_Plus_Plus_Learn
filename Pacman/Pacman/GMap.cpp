#include "stdafx.h"
#include "GMap.h"

int GMap::LD = 36;       //ǽ�Ŀ��
int GMap::PD = 3;         //���ӵ�ֱ��

//����˫������λ��û�ж��ӳ���
void GMap::InitOP()
{
	peaMapData[E_ROW][E_ARRAY] = false;   //�з�λ��û�ж���
	peaMapData[P_ROW][P_ARRAY] = false;  //�ҷ�λ��û�ж���
}

//���Ƶ�ͼ
void GMap::DrawMap(HDC &memDC)
{
	HBRUSH hBrush = CreateSolidBrush(color);
	for (int i = 0; i < MAPLENTH; i++)
	{
		for(int j=0;j<MAPLENTH;j++)
		{
			//����ǽ��
			if (!mapData[i][j])
			{
				RECT rect;
				rect.left = j * LD;
				rect.top = i * LD;
				rect.right = (j + 1)*LD;
				rect.bottom = (i + 1)*LD;
				FillRect(memDC, &rect, hBrush);  //����������ģ��ǽ��
			}
		}
	}
	DeleteObject(hBrush);//ɾ����ˢ����
}

//���ƶ���
void GMap::DrawPeas(HDC &hdc)
{
	for (int i = 0; i < MAPLENTH; i++)
	{
		for (int j = 0; j < MAPLENTH; j++)
		{
			if (peaMapData[i][j])
			{
				Ellipse(hdc, (LD / 2 - PD) + j * LD,   //��Բ��ģ�ⶹ��
					(LD / 2 - PD) + i * LD,
					(LD / 2 + PD) + j * LD,
					(LD / 2 + PD) + i * LD);
			}
		}
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		MessageBoxA(NULL, "�����з���������", "", MB_OK);
		for (int i = 0; i < MAPLENTH; i++)
		{
			for (int j = 0; j < MAPLENTH; j++)
			{
				peaMapData[i][j] = false;
			}
		}
	}
}


