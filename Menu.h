#pragma once
#include "GameButton.h"
#include <conio.h>


using namespace std;
class Menu
{

	GameButton newgame, menu, exit, autoplay1;
	int current_pos;
	string strelka;
	string strelka2;
	string user;
	int speed;
	bool first;
	///////////////////////////////////////////////////////////////
	

	//////////////////////////////////////////////////////////
public:
	Menu();

	void SetColor(int text, int background);
	void SetCurrentPos(int n);
	int GetCurrenPos() const;
	void SetStrelka1(const char* a);
	string GetStrelka1() const;
	void SetStrelka2(const char* a);
	string GetStrelka2() const;
	void SetFirstStart(bool first = false);
	bool GetFirstStartStatus() const;
	void SetUser(string str);
	string GetUser() const;
	int SwitchMenu();
	void ClearPosition();
	void CleArea();
	void Show();
	void GotoXy(int x, int y);
};

