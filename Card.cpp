#include "Card.h"

void Card::Shuffle()
{
	for (int i = 0; i < 10; i++)
	{	
		card[i] = 11;
	}
	for (int i = 0; i < 10; i++)
	{
		int c = rand() % 10+0;
		while (FindCard(c))
		{
			c = (rand() % 10+0);
		}
		card[i] = c;
	}
}

bool Card::FindCard(int n) const
{
	for (int i = 0; i < 10; i++)
	{
		if (card[i] == n) return true;
	}
	return false;
}

int Card::GetCardsCount() const
{
	return count_cards;
}

int Card::GetCard(int number) const
{
	if (number >= 0 and number < 10)
	{
		return card[number];
	}
	else 
		cout << "\nWrong serach index";
}

Card::Card()
{
	Shuffle();
	count_cards = 10;
}
