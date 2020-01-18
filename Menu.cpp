#include "Menu.h"


void Menu::GotoXy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}


void Menu::SetColor(int text, int background)
{
	if (text == 0 or text == 7 or text == 8) text = 6;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Menu::SetCurrentPos(int n)
{
	if (n > 0 and n < 5) current_pos = n;
	else
		if (n < 1) current_pos = 4;
		else	current_pos = 1;
}

int Menu::GetCurrenPos() const
{
	return current_pos;
}

void Menu::SetStrelka1(const char* a)
{
	if (strlen(a) > 0)	strelka = a;
}

string Menu::GetStrelka1() const
{
	return strelka;
}

void Menu::SetStrelka2(const char* a)
{
	if (strlen(a) > 0) strelka2 = a;
}

string Menu::GetStrelka2() const
{
	return strelka2;
}

void Menu::SetFirstStart(bool first)
{
	this->first = first;
}

bool Menu::GetFirstStartStatus() const
{
	return first;
}

void Menu::SetUser(string str)
{
	if (str.length() > 0) user = str;
	else user = "default";
}

string Menu::GetUser() const
{
	return user;
}

int Menu::SwitchMenu()
{

	char k = '1';

	do
	{
		k = _getch();

		switch (k)
		{
		case 13: return current_pos; break;
		case 27: current_pos = 1; CleArea();  Show(); break;
		case 's': ClearPosition(); current_pos++; SetCurrentPos(current_pos); Show(); break;
		case 'w': ClearPosition(); current_pos--; SetCurrentPos(current_pos); Show();  break;
		default: k = '1'; break;

		}

	} while (k != 13 and k != 27);


	
}

void Menu::ClearPosition()
{

	if (current_pos == 1)
	{
		menu.GotoXY(menu.GetXpos() - strelka.length() - 1, menu.GetYpos() + 1);
		for (int i = 0; i < strelka.length(); i++)
		{
			cout << " ";
		}
		menu.GotoXY(menu.GetXpos() + menu.GetLength() + 1, menu.GetYpos() + 1);
		for (int i = 0; i < strelka2.length(); i++)
		{
			cout << " ";
		}
	}
	else
		if (current_pos == 2)
		{
			newgame.GotoXY(newgame.GetXpos() - strelka.length() - 1, newgame.GetYpos() + 1);
			for (int i = 0; i < strelka.length(); i++)
			{
				cout << " ";
			}
			newgame.GotoXY(newgame.GetXpos() + newgame.GetLength() + 1, newgame.GetYpos() + 1);
			for (int i = 0; i < strelka2.length(); i++)
			{
				cout << " ";
			}
		}
		else
			if (current_pos == 4)
			{
				exit.GotoXY(exit.GetXpos() - strelka.length() - 1, exit.GetYpos() + 1);
				for (int i = 0; i < strelka.length(); i++)
				{
					cout << " ";
				}
				exit.GotoXY(exit.GetXpos() + exit.GetLength() + 1, exit.GetYpos() + 1);
				for (int i = 0; i < strelka2.length(); i++)
				{
					cout << " ";
				}
			}	
			else
				if (current_pos == 3)
				{
					autoplay1.GotoXY(autoplay1.GetXpos() - strelka.length() - 1, autoplay1.GetYpos() + 1);
					for (int i = 0; i < strelka.length(); i++)
					{
						cout << " ";
					}
					autoplay1.GotoXY(autoplay1.GetXpos() + autoplay1.GetLength() + 1, autoplay1.GetYpos() + 1);
					for (int i = 0; i < strelka2.length(); i++)
					{
						cout << " ";
					}
				}


	cin.clear();
}

void Menu::CleArea()
{
	for (int i = 0; i < 40; i++)
	{
		for (int c = 0; c < 50; c++)
		{
			cout << " ";
		}
		cout << endl;
	}
	first = false;
}

void Menu::Show()
{

	menu.ShowButton();
	if (first)
	{
		CleArea();
		menu.ShowButton();
		newgame.ShowButton();
		autoplay1.ShowButton();
		exit.ShowButton();
	}
	if (current_pos == 1)
	{
		menu.GotoXY(menu.GetXpos() - strelka.length() - 1, menu.GetYpos() + 1);
		SetColor(rand() % 14, 0);
		cout << strelka;
		menu.GotoXY(menu.GetXpos() + menu.GetLength() + 1, menu.GetYpos() + 1);
		SetColor(rand() % 14, 0);
		cout << strelka2;
	}
	else
		if (current_pos == 2)
		{
			newgame.GotoXY(newgame.GetXpos() - strelka.length() - 1, newgame.GetYpos() + 1);
			SetColor(rand() % 14, 0);
			cout << strelka;
			newgame.GotoXY(newgame.GetXpos() + newgame.GetLength() + 1, newgame.GetYpos() + 1);
			SetColor(rand() % 14, 0);
			cout << strelka2;
		}
		else
			if (current_pos == 4)
			{
				exit.GotoXY(exit.GetXpos() - strelka.length() - 1, exit.GetYpos() + 1);
				SetColor(rand() % 14, 0);
				cout << strelka;
				exit.GotoXY(exit.GetXpos() + exit.GetLength() + 1, exit.GetYpos() + 1);
				SetColor(rand() % 14, 0);
				cout << strelka2;
			}
			else
				if (current_pos == 3)
				{
					autoplay1.GotoXY(autoplay1.GetXpos() - strelka.length() - 1, autoplay1.GetYpos() + 1);
					SetColor(rand() % 14, 0);
					cout << strelka;
					autoplay1.GotoXY(autoplay1.GetXpos() + exit.GetLength() + 1, autoplay1.GetYpos() + 1);
					SetColor(rand() % 14, 0);
					cout << strelka2;
				}
	cin.clear();
}
Menu::Menu()
{
	//текс, хпос, упос, отсуп_х, отступ_н, ширина, длина, текст цвет, цвет бек
	menu = { "Menu", '#', 10,1, 4,1, 3, 12, 11,5 };
	newgame = { "New Game", '#', 10,4, 2,1, 3, 12, 10,4 };
	exit = { "Exit", '#', 10,10, 4,1, 3, 12, 11,8 };
	autoplay1 = {"Autoplay", '#', 10,7, 2,1, 3, 12, 7,12 };
	current_pos = 1;
	strelka = "WA--->>>>";
	strelka2 = "<<<<---SD";
	first = false;
	user = "";
	speed = 60;
}
