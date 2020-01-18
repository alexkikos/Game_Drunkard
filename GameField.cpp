#include "GameField.h"


GameField::GameField()
{
	rounds = pow(10, 6);
	//текс, but_symv, хпос, упос, отсуп_х, отступ_н, ширина, длина, текст цвет, цвет бек
	lobbi = { "", '#', 0,0,0,0, 27, 80, 4, 8 };
	foonbutton = { "", '#', 0,0,0,0, 30, 30, 1, 11 };
	user_button = { "", '#',35,2,1,1, 3, 10, 5, 11 };
	bot_button = { "Player_bot", '#', 35,22,2,1, 3, 13, 11, 13 };
	winner = { "", '#', 3,22,2,1, 3, 28, 1, 11 };
	botva = { "BOTVA", '#', 3,22,2,1, 3, 28, 1, 11 };
	helper = { "Press N", '#', 67,12,1,1, 3, 9, 6, 7 };
}

bool GameField::StartGame()
{
Start:
	menu.SetCurrentPos(1);
	menu.Show();
	char a = ' ';
	char b = ' ';
	while (a != 13)
	{
		a = _getch();
	}
	menu.SetFirstStart(true);
	menu.Show();
	a = menu.SwitchMenu();
	if (a == 1 or a == 27)
	{
		system("cls");
		goto Start;
	}
	else
		if (a == 4)
		{
			return false;
		}
	system("cls");
	if (user.length() == 0)
	{
		cout << "enter name: ";
		cin >> user;
	}
	card.Shuffle();
	for (int i = 0; i < card.GetCardsCount() / 2; i++)
	{
		player.AddLast(card.GetCard(i), false);
		player2.AddLast(card.GetCard(card.GetCardsCount() - i - 1), true);
		player2.last->picture_card.SetColorText(11);
		player2.last->picture_card.SetColorBackground(12);
	}
	user_button.SetText(user);
	user_button.SetLength(user.length() + 2);
	while ((player.first != nullptr and player2.first != nullptr) and b != 27)
	{
	
		lobbi.ShowButton();
		helper.ShowButton();
		player.ShowALLCards();
		player2.ShowALLCards(true);
		user_button.ShowButton();
		bot_button.ShowButton();
		rounds--;
		MoveCardOnBoard();
		if (a == 3 and !_kbhit()) Sleep(1000);
		else
		{
			while (b!= 'n' and b != 'N') {
				b = _getch();
				if (b == 27)
				{
					system("cls"); 
					player.DeleteAll();
					player2.DeleteAll();
					goto Start;
				}
			}
		}
		if (player.GetFirstCard() > player2.GetFirstCard() and player.GetFirstCard() != 0 and player2.GetFirstCard() != 9)
		{

			player.AddLast(player.GetFirstCard());
			player.AddLast(player2.GetFirstCard());
			player.last->picture_card.SetColorText(player2.first->picture_card.GetColorText());
			player.last->picture_card.SetColorBackground(player2.first->picture_card.GetColorBackground());

			player2.RemoveFirst();
			player.RemoveFirst();
		}
		else
		{
			player2.AddLast(player2.GetFirstCard());
			player2.last->picture_card.SetColorText(11);
			player2.last->picture_card.SetColorBackground(12);

			player2.AddLast(player.GetFirstCard());
			player2.last->picture_card.SetColorText(player.first->picture_card.GetColorText());
			player2.last->picture_card.SetColorBackground(player.first->picture_card.GetColorBackground());

			player2.RemoveFirst();
			player.RemoveFirst();
		}
		if (a != 3) b = ' ';
	}	

	ShowResults();
	b = _getch();
	system("cls");
	goto Start;
}

void GameField::ShowResults()
{

	if (rounds > 0)
	{
		if (player.count > 1)
		{
			winner.SetYpos(user_button.GetYpos());
			player.DeleteAll();
		}
		else
		{
			winner.SetYpos(bot_button.GetYpos());
			player2.DeleteAll();
		}
		int res = (pow(10, 6) - (int)rounds);
		winner.SetText("WINNER!!Total Round: " + to_string(res));
		winner.ShowButton();
	}
	else
	{
		botva.ShowButton();
		player.DeleteAll();
		player2.DeleteAll();
	}
	rounds = pow(10, 6);
}

void GameField::ClearLobbi()
{
	for (int i = 0; i < 18; i++)
	{
		menu.GotoXy(4+i, 0);
		for (int c = 0; c < 40; c++)
		{
			cout << " ";
		}
	}
}



void GameField::MoveCardOnBoard()
{
	player.first->picture_card.SetXpos(35);
	player2.first->picture_card.SetXpos(35);
	player.first->picture_card.SetYpos(10);
	player2.first->picture_card.SetYpos(14);
	player2.first->picture_card.SetText(to_string(player2.first->number));
	player.first->picture_card.ShowButton();
	player2.first->picture_card.ShowButton();
}

