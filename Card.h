#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;
class Card
{
private:
	int card[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count_cards;
	void Shuffle();
	bool FindCard(int n) const;
	int GetCardsCount() const;
	int GetCard(int number) const;
	Card();
	~Card() = default;
	Card(const Card& src) = delete;
	Card(Card&& src) = delete;
	Card operator = (Card&& src) = delete;
	Card operator = (const Card&& src) = delete;
	friend class GameField;
};

