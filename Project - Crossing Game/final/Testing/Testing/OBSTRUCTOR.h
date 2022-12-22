#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class OBSTRUCTOR
{
protected:

	int x, y, h, w;
	int type;
	int distance;

public:
	OBSTRUCTOR();
	virtual void setShape(string temp[4]) = 0;
	virtual string* getShape(string temp[4]) = 0;
	virtual int MaxW() = 0;

	virtual void init(int type, int posX, int posY) = 0;
	virtual int getType() = 0;
	virtual void setType(int data) = 0;

	virtual void move() = 0;

	virtual OBSTRUCTOR *getClone() = 0;

	int getX() { int temp = x; return temp; };
	int getY() { int temp = y; return temp; };
	int getH() { int temp = h; return temp; };
	int getW() { int temp = w; return temp; };
	int getDistance() { int temp = distance; return temp; }

	void setX(int data) { this->x = data; };
	void setY(int data) { this->y = data; };
	void setDistance(int data) { this->distance = data; };
	void GoToXY(SHORT posX, SHORT posY)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}
};




