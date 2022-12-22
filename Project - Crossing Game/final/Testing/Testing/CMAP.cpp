#include "CMAP.h"
#include "Header.h"

CMAP::CMAP()
{
	
}
void CMAP::setwall()
{
	wall[0] = { 0,0 };
	this->i = 0;
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (x > 0 && x < 4 && y != 0)
			{

			}
			else
			{
				wall[i] = { 2 + y,1 + x };
				if (x > 0 && x < 4)
				{
					shape[i] = 179;
				}
				else if (x == 0 && y == 0)
				{
					shape[i] = 218;
				}
				else if (x == 4 && y == 0)
				{
					shape[i] = 192;
				}
				else
				{
					shape[i] = 196;
				}
				i++;
			}
		}
	}

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (x > 0 && x < 4 && y != 3)
			{

			}
			else
			{
				wall[i] = { 140 + y,39 + x };
				if (x > 0 && x < 4)
				{
					shape[i] = 179;
				}
				else if (x == 0 && y == 3)
				{
					shape[i] = 191;
				}
				else if (x == 4 && y == 3)
				{
					shape[i] = 217;
				}
				else
				{
					shape[i] = 196;
				}
				i++;
			}
		}
	}
}
void CMAP::draw()
{
	for (int f = 0; f < i; f++)
	{
		GoToXY(wall[f].x, wall[f].y);
		cout << shape[f];
	}
	drawBoard(0, 0, width, height);
	drawBoard(0, 0, width*4/5 + 1, height);
	Word();
}
void CMAP::drawBoard(int x, int y, int w, int h)
{
	char temp = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (i == 0 && j == 0)
			{
				temp = goctrentrai_;
			}
			else if (i == 0 && j == h - 1)
			{
				temp = gocduoitrai_;
			}
			else if (i == w - 1 && j == 0)
			{
				temp = goctrenphai_;
			}
			else if (i == w - 1 && j == h - 1)
			{
				temp = gocduoiphai_;
			}
			else if (i == 0 || i == w - 1)
			{
				temp = canhdung_;
			}
			else if (j == 0 || j == h - 1)
			{
				temp = canhngang_;
			}
			if (temp != 0)
			{
				GoToXY(i + x, j + y);
				cout << temp;
				temp = 0;
			}
		}
	}
}
bool CMAP::isCollision(CPEOPLE peo)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < this->i; k++)
			{
				if (peo.getX() + i == wall[k].x
					&& peo.getY() + j == wall[k].y)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void CMAP::Word()
{
	SetColor(15, 0);
	drawBoard(150, 10, 25, 8);
	GoToXY(151, 11);
	cout << "Press 'W' to move up";
	GoToXY(151, 12);
	cout << "Press 'S' to move down";
	GoToXY(151, 13);
	cout << "Press 'D' to move right";
	GoToXY(151, 14);
	cout << "Press 'A' to move left";
	GoToXY(151, 15);
	cout << "Press 'L' to Save";
	GoToXY(151, 16);
	cout << "Press 'B' to go to Menu";
	for (int i = 0; i <= 6; i++)
	{
		GoToXY(151, 18 + i);
		if (i == 6)
		{
			cout << "       Tutorial Book ";
		}
		else
			cout << book[i];

	}
	GoToXY(146, 26);
	cout << "    If you want to win, you must";
	GoToXY(146, 27);
	cout << "   come in '>'.";
	GoToXY(145, 29);
	cout << "    TIP: When the traffic light";
	GoToXY(145, 30);
	cout << "  turns red, all entities on the";
	GoToXY(145, 31);
	cout << "   corresponding lane will stop ";
	GoToXY(145, 32);
	cout << "             moving !";
	SetColor(15, 0);


}