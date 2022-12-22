#pragma once
#include<string>
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
class CPEOPLE
{
private:
	int x, y;
	string shape[3] =
	{
		" o ",
		"/|\\",
		"/ \\",
	};

public:
	bool isAlive;
	CPEOPLE();
	void setPos(int x, int y) { this->x = x; this->y = y; };
	void setState(bool data) { isAlive = data; };
	int getX() { int temp = x; return temp; };
	int getY() { int temp = y; return temp; };
	bool getState() { bool temp = isAlive; return temp;  };
	void init();
	bool checkDead();
	string getShape(int key) { return shape[key]; };

	void move(char movekey);

	void GoToXY(SHORT posX, SHORT posY)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}
};



