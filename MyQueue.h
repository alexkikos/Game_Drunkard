#pragma once
#include "InfoCard.h"
#include <iostream>
using namespace std;


class MyQueue
{

	InfoCard<int>* first, *last;
	int count;
	string user_name = "Player_bot";
	void AddFirst(int card, bool second_player=false);
	void AddLast(int card, bool second_player=false);
	void RemoveFirst();
	void ShowFirst() const;
	void ShowALLCards(bool bot=false) const;
	int GetFirstCard() const;
	int GetCount() const;
	void DeleteAll();
	void SetName(string s);
	MyQueue();
	~MyQueue();
	MyQueue(const InfoCard<int>&src);
	MyQueue(const MyQueue& src) = delete;
	MyQueue(MyQueue&& src) = delete;
	MyQueue operator = (MyQueue&& src) = delete;
	MyQueue operator = (const MyQueue&& src) = delete;
	friend class GameField;
};


