#pragma once
#include "MyQueue.h"
#include "Card.h"
#include "Menu.h"
#include <iostream>
#include <string.h>
#include "GameButton.h"
#include "InfoCard.h"
class GameField
{

	MyQueue player, player2;
	int rounds;
	Card card;
	Menu menu;
	string user;
	GameButton lobbi, foonbutton, user_button, bot_button, winner, botva, helper;
public:


	bool StartGame();
	void ShowResults();
	void ClearLobbi();
	void MoveCardOnBoard();
	GameField();
	GameField(const GameField& src) = delete;
	GameField(GameField&& src) = delete;
	GameField operator = (GameField&& src) = delete;
	GameField operator = (const GameField&& src) = delete;
};

