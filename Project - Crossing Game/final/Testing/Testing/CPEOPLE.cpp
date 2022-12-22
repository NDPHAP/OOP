#include "CPEOPLE.h"
#include "Header.h"

int Y_game = 45;
int X_game = 144;
CPEOPLE::CPEOPLE()
{
	init();
}
void CPEOPLE::init()
{
	x = 3;
	y = 2;
	this->isAlive = true;
}
bool CPEOPLE::checkDead()
{
	return false;
}
void CPEOPLE::move(char movekey)
{
	if (movekey == 'A' && x - 1 > 0)
	{
		for (int i = 0; i < 3; i++)
		{
			GoToXY(x + 2, y + i);
			cout << " ";
		}
		x--;
	}
	else
	if (movekey == 'S' && y + 1 < Y_game - 3)
	{
		
			GoToXY(x, y);
			cout << "   ";
		
		y++;
	}
	else 
	if (movekey == 'D' && x + 1 < X_game - 2)
	{
				for (int i = 0; i < 3; i++)
				{
					GoToXY(x , y + i);
					cout << " ";
				}
			
		x++;
	}
	else 
	if (movekey == 'W' && y - 1 > 0)
	{
		GoToXY(x, y + 2);
		cout << "   ";
		y--;
	}
}

