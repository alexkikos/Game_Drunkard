#pragma once
#include "GameButton.h"
template<class T>
struct InfoCard
{
private:
	InfoCard<T> *next;
	GameButton picture_card;//������� �����
	T number;
	int xpos;//��������� � ����� ��� �������� ��������� ������ �����, �� ���� ����� ����� ����� � ���� � ���
	int ypos;
	InfoCard<T>(T nubmer=0, InfoCard* next = nullptr, int xpos =0, int ypos=0)
	{		
		this->xpos = xpos;
		this->ypos = ypos;
		this->number = nubmer;	
		this->next = next;
		picture_card.SetText(to_string(number));
		picture_card.SetColorText(14);
		picture_card.SetColorBackground(12);
		picture_card.SetLength(3);
		picture_card.SetWidth(3);
		picture_card.SetXindent(1);
		picture_card.SetYindent(1);
		picture_card.SetXpos(this->xpos);
		picture_card.SetYpos(this->ypos);
		picture_card.SetButtonChar('#');
		//����, but_symv, ����, ����, �����_�, ������_�, ������, �����, ����� ����, ���� ���
	}
	friend class MyQueue;
	friend class GameField;
};