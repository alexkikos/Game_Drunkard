#include "MyQueue.h"



void MyQueue::AddFirst(int card, bool second_player)
{
	if (first == nullptr)
	{
		if (second_player)
		{
			first = new InfoCard<int>{ card, first, 5, 18 };
			last = first;
			count = 1;
		}
		else
		{
			first = new InfoCard<int>{card, first, 5, 6};
			last = first;
			count = 1;
		}
	}

}


void MyQueue::AddLast(int card, bool second_player)
{
	if (first == nullptr) { AddFirst(card, second_player); return; }
	if (last != nullptr)
	{
		InfoCard<int>* tmp = new InfoCard<int>{ card, nullptr, last->xpos + 4, first->ypos };
		last->next = tmp;
		last = tmp;
		count++;
	}
	else 
		cout << "\nCheck last input";
}


void MyQueue::RemoveFirst()
{
	if (first)
	{
		InfoCard<int>* tmp = first;
		first = first->next;
		count--;
		delete tmp;
		
		int c_x = 0;
		InfoCard<int>* tmp1 = first;//смещаю мои карты по позициям , после удаляния первой карты
		while (tmp1)
		{
			tmp1->xpos -= tmp1->picture_card.GetLength()+1;//4 - размер кнопки
			tmp1->picture_card.SetXpos(tmp1->xpos);
			tmp1 = tmp1->next;
		}
		delete tmp1;
	}
	else
	{
		first = last = nullptr;	
		count = 0;
		cout << "\nTrouble with removefirst";
	}
}


void MyQueue::ShowFirst() const
{
	if (first) cout << first->number;
	else cout << "Queue is empty";
}



void MyQueue::ShowALLCards(bool bot) const
{
	if (first)
	{
		InfoCard<int>* temp = first;	
		while (temp)
		{
			//cout << temp->number << " ";
			if (bot) temp->picture_card.SetText("?");
			temp->picture_card.ShowButton();
			temp = temp->next;
		}
		cout << endl;
		delete temp;
	}
	else cout << "\nNo more cards\n";
}



int MyQueue::GetFirstCard() const
{
	if (first) return first->number;
	else cout << "\nError GetFirstCard";
}



int MyQueue::GetCount() const
{
	return count;
}

void MyQueue::DeleteAll()
{
	while (count != 0) RemoveFirst();
}

void MyQueue::SetName(string s)
{
	if (s.length() > 0) user_name = s;
}



MyQueue::MyQueue()
{
	first = nullptr;
	last = nullptr;
	count = 5;
}

MyQueue::~MyQueue()
{
	DeleteAll();
}

MyQueue::MyQueue(const InfoCard<int>& src)
{
	this->first = src.next;
	this->last = src.next;
	count = 0;
}
