#include "VEHICLE.h"
VEHICLE::VEHICLE(int type, int posX, int posY)
{
	init(type, posX, posY);
}
string* VEHICLE::getShape(string temp[4])
{
	for (int i = 0; i < 4; i++)
	{
		temp[i] = this->shape[i];
	}
	return temp;
}
void VEHICLE::setShape(string temp[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->shape[i] = temp[i];
	}
}
int VEHICLE::MaxW()
{
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (max < shape[i].length())
		{
			max = shape[i].length();
		}
	}
	return max;
}
void VEHICLE::init(int type, int posX, int posY)
{
	this->type = type;
	switch (type)
	{
	case 0:
		setShape(car);
		w = MaxW();
		x = posX;
		break;
	case 1:
		setShape(train);
		w = MaxW();
		x = posX;
		break;
	case 2:
		setShape(tank);
		w = MaxW();
		x = posX;
		break;
	case 3:
		setShape(bus);
		w = MaxW();
		x = posX;
		break;
	}
	y = posY;
	h = 4;
}
void VEHICLE::move()
{
	if (type == 2 || type == 3)  // move left
	{
		if (x < 145 && x > 1)
		{
			for (int j = 0; j < 4; j++)
			{
				GoToXY(x - 1, y + j);
				cout << " ";
			}
		}
		if (x - 1 < -w)
		{
			x = 144;
		}
		else
		{
			x--;
		}
	}
	else    // move right
	{
		if (x < 145 && x > 1)
		{
			for (int j = 0; j < 4; j++)
			{
				GoToXY(x - 1, y + j);
				cout << " ";
			}
		}
		if (x + 1 == 145)
		{
			x = 1 - w;
		}
		else
		{
			x++;
		}
	}
}

