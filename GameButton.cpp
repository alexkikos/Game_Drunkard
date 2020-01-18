#include "GameButton.h"

void GameButton::GotoXY(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void GameButton::SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GameButton::SetXpos(int x)
{
	if (x >= 0) xpos = x;
}

int GameButton::GetXpos() const
{
	return xpos;
}

void GameButton::SetYpos(int y)
{
	if (y >= 0) ypos = y;
}

int GameButton::GetYpos() const
{
	return ypos;
}

void GameButton::SetWidth(int width)
{
	if (width >= 2) this->width = width;
}

int GameButton::GetWidth() const
{
	return width;
}

void GameButton::SetLength(int length)
{
	if (length >= 3) this->length = length;
}

int GameButton::GetLength() const
{
	return length;
}

void GameButton::SetText(string src)
{
	if (src.length() > 0) text = src;
}

string GameButton::Text() const
{
	return text;
}

void GameButton::SetColorText(int color)
{
	if (color >= 0 and color < 16) color_text = color;
}

int GameButton::GetColorText() const
{
	return color_text;
}

void GameButton::SetColorBackground(int back_color)
{
	if (back_color >= 0 and back_color < 16) color_background = back_color;
}

int GameButton::GetColorBackground() const
{
	return color_background;
}

void GameButton::SetXindent(int n)
{
if (n >= 0) text_x_indent = n;
}

int GameButton::GetXindent() const
{
	return  text_x_indent;
}

void GameButton::SetYindent(int n)
{
	if (n >= 0) text_y_indent = n;
}

int GameButton::GetYindent() const
{
	return text_y_indent;
}

void GameButton::SetButtonChar(char s)
{
	button_symvol = s;
}

void GameButton::ShowButton(bool check)
{
	GotoXY(xpos, ypos);
	int tempx = xpos;
	int tempy = ypos;
	for (int i = 0; i < width; i++)
	{
		for (int c = 0; c < length; c++)
		{

			if (i == 0 or i + 1 == width or c == 0 or c + 1 == length)
			{
				SetColor(color_text, 0);
				cout << button_symvol;
			}	
			else
				if (i == text_y_indent and c == text_x_indent)
				{
					SetColor(color_text, color_background);
					cout << text;
					int a = text.length()-1;
					c += a;				
				}
				else
				{
					SetColor(color_text, color_background);
					cout << " ";
				}
		}
		
		if (check == false)
		{
			cout << endl;
			GotoXY(xpos, tempy += 1);
		}
		else
		{
			cout << endl;
			GotoXY(xpos+=5, tempy);
		}
	}


}

GameButton::GameButton(string text, char button_symvol, int xpos, int ypos, int text_x_indent, int text_y_indent, int width, int length, int color_text, int color_background)
{
	this->text = text;
	this->button_symvol = button_symvol;
	this->xpos = xpos;
	this->ypos = ypos;
	this->width = width;
	this->length = length;
	this->color_text = color_text;
	this->color_background = color_background;
	this->text_x_indent = text_x_indent;
	this->text_y_indent = text_y_indent;

}
