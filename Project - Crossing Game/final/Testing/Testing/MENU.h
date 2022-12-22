#pragma once
#include "Header.h"
#include "CMAP.h"
class MENU:public CMAP
{
private:
	int x; int y;
public:
	MENU(int x,int y){ this->x = x; this->y = y; };
	int show_Menu(const char* name, const char* menu1, const char* menu2,
		const char* menu3, const char* menu4);
	void PrintLogo(int x,int y); // 30,5
	void printObj1(int x, int y);
	void printOption(int x, int y, int option, const char* name, const char* menu1, const char* menu2,
		const char* menu3, const char* menu4);
	void clear(int time);
	void GoToXY(SHORT posX, SHORT posY)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}
	void SetColor(int backgound_color, int text_color)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		int color_code = backgound_color * 16 + text_color;
		SetConsoleTextAttribute(hStdout, color_code);
	}

	void aboutUs();
};

