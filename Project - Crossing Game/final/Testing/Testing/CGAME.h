#pragma once

#include "Console.h"
#include "CPEOPLE.h"
#include "OBSTRUCTOR.h"
#include"ANIMAL.h"
#include "VEHICLE.h"
#include "TRAFFIC.h"
#include "CMAP.h"
//#include "EFFECT.h"
#include <vector>
class CGAME 
{
private:
	Console *cons;
	static CMAP map;
public:
	int state;   // 1     2: animal 
	int level;
	string name;
	CPEOPLE people;

	vector<OBSTRUCTOR*> lane1;
	vector<OBSTRUCTOR*> lane2;
	vector<OBSTRUCTOR*> lane3;
	vector<OBSTRUCTOR*> lane4;

	static TRAFFIC traffic;
	CMAP getMap() { CMAP temp = map; return temp; };
	Console* getConsole() { Console* temp = cons; return temp; };
	CGAME();
	void clearData() {
		int size = lane1.size();
			for (int i = 0; i < size; i++)
			{
				lane1.pop_back();
				lane2.pop_back();
				lane3.pop_back();
				lane4.pop_back();
			}
	};
	~CGAME() {
		if (cons != NULL)
		{
			delete cons;
		}
	};
	void initGame();
	void drawPeople();

	//void movePeople(char movekey);
	//void drawMap();

	//////////////////////////////////////////////////////////////////////

	void drawObs();

	bool isCollision(OBSTRUCTOR *obs, CPEOPLE peole);
	bool isDead() ;

	/////////////////////////////////////////////////////////////////////

	bool startgame(CGAME *load_data);
	bool isWin();
	void clear_maingame();

	/////////////////////////////////////////////////////////////////////

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

	/////////////////////////////////////////////////////////////////////

	void ControlPeople(char key);
	void ControlObs(TRAFFIC traffic);
	bool ControlGame(char key);

	/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////

	bool SaveGame(string filename);
	bool LoadGame(string filename);

	/////////////////////////////////////////////////////////////////////

	//bool Backeffect();

};
