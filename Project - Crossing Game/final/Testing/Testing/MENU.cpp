#include "MENU.h"

int MENU::show_Menu(const char* name, const char* menu1, const char* menu2,
	const char* menu3, const char* menu4)
{
	clear(0);
	SetColor(15, 3);
	PrintLogo(30, 5);
	printObj1(50, 29);
	char move = 0;
	int option = 1;
	printOption(80, 18, 1, name, menu1, menu2, menu3, menu4);
	int color = 3;
	while (true)
	{
		if (_kbhit())
		{
			move = toupper(_getch());
			if (move == 13)
			{
				break;
			}
			else if (move == 'W')
			{
				if (option - 1 < 1)
				{
					option = 4;
				}
				else { option--; }
			}
			else if (move == 'S')
			{
				if (option + 1 > 4)
				{
					option = 1;
				}
				else { option++; }
			}
			printOption(80, 18, option, name, menu1, menu2, menu3, menu4);
			if (color == 3)
			{
				color = 5;
			}
			else { color = 3; }
			SetColor(15, color);
			PrintLogo(30, 5);
			printObj1(50, 29);
			SetColor(15, 3);
		}
	}
	return option;
}
char gocduoitrai = 200;
char canhdung = 186;
char canhngang = 205;
char gocduoiphai = 188;
char goctrentrai = 201;
char goctrenphai = 187;
void MENU::printOption(int x, int y, int option, const char* name, const char* menu1, const char* menu2,
	const char* menu3, const char* menu4)
{
	SetColor(15, 3);
	char temp = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0 && j == 0)
			{
				temp = goctrentrai;
			}
			else if(i == 0 && j == 8)
			{
				temp = gocduoitrai;
			}
			else if (i == 19 && j == 0)
			{
				temp = goctrenphai;
			}
			else if (i == 19 && j == 8)
			{
				temp = gocduoiphai;
			}
			else if(i == 0 || i == 19)
			{
				temp = canhdung;
			}
			else if(j == 0 || j == 8)
			{
				temp = canhngang;
			}
			if (temp != 0)
			{
				GoToXY(i + x, j + y);
				cout << temp;
				temp = 0;
			}
		}
	}
	GoToXY(x + 4, y + 1);
	cout << menu1;
	GoToXY(x + 4, y + 3);
	cout << menu2;
	GoToXY(x + 4, y + 5);
	cout << menu3;
	GoToXY(x + 4, y + 7);
	cout << menu4;

	switch (option)
	{
	case 1:
		SetColor(15, 4);
		GoToXY(x + 4, y + 1);
		cout << menu1;
		SetColor(15, 3);
		break;
	case 2:
		SetColor(15, 4);
		GoToXY(x + 4, y + 3);
		cout << menu2;
		SetColor(15, 3);
		break;
	case 3:
		SetColor(15, 4);
		GoToXY(x + 4, y + 5);
		cout << menu3;
		SetColor(15, 3);
		break;
	case 4:
		SetColor(15, 4);
		GoToXY(x + 4, y + 7);
		cout << menu4;
		SetColor(15, 3);
		break;
	}
}
void MENU::printObj1(int x,int y)
{
	string obj1[] =
	{
"                                                     _________________________",
"                  /\\\\      _____          _____      |   |     |     |    | | \\",
"    ,-----,      /  \\\\____/__|__\\__   ___/__|__\\___  |___|_____|_____|____|_|__\\",
",--'---:---`--, /    |  _     |    | |      |     `| |                    | |   \\",
"==(o)-----(o)==J    `(o)-------(o)=  (o)------(o)'= `--(o)(o)--------------(o)--'",
"`````````````````````````````````````````````````````````````````````````````````````",
	};
	for (int i = 0; i < 6; i++)
	{
		GoToXY(x, y + i);
		cout << obj1[i];
	}
}
void MENU::PrintLogo(int x,int y)
{
	string logo[] = {
		" --------------------------------------------------------------------------------------------------------------------- ",
		"|                                                                                                                     |",
		"|    ######   #########     ########   #######    #######          #########     ########       #####     ########    |",
		"|   ##        ##      ##   ##      ## ##         ##                ##      ##   ##      ##     ##   ##    ##     ##   |",
		"|   ##        ##      ##   ##      ## ##         ##                ##      ##   ##      ##     ##   ##    ##     ##   |",
		"|   ##        ##      ##   ##      ## ##         ##                ##      ##   ##      ##    ##     ##   ##     ##   |",
		"|   ##        ########     ##      ##  #######    #######          ########     ##      ##   ###########  ##     ##   |",
		"|   ##        ##      ##   ##      ##        ##         ##         ##      ##   ##      ##   ##       ##  ##     ##   |",
		"|   ##        ##       ##  ##      ##        ##         ##         ##       ##  ##      ##   ##       ##  ##     ##   |",
		"|   #######   ##        ##  ########   #######    #######          ##        ##  ########    ##       ##  ########    |",
		"|                                                                                                                     |",
		" --------------------------------------------------------------------------------------------------------------------- ",
	};
	for (int i = 0; i < 12; i++)
	{
		GoToXY(x, y + i);
		cout << logo[i];
	}
}
void MENU::clear(int time)
{
	SetColor(15, 3);
	for (int i = 0; i < 180; i++)
	{
		for (int j = 0;j < 45; j++)
		{
			GoToXY(i, j);
			cout << " ";
		}
		//Sleep(time);
	}
	SetColor(15, 0);
}
#include <iostream>

void MENU::aboutUs()
{
	drawBoard(75, 11, 30, 8);
	GoToXY(84, 12);
	cout << "Member list: ";
	GoToXY(80, 14);
	cout << "1. Nguyen Duy Dang Khoa";
	GoToXY(80, 15);
	cout << "2. Mach Vi Kiet";
	GoToXY(80, 16);
	cout << "3. Tran Thai Toan";
	GoToXY(80, 17);
	cout << "4. Tran Dinh Phap";
	GoToXY(84, 19);
	SetColor(15, 4);
	cout << "      press B to back";
	SetColor(15, 0);
	while (true)
	{
		if (_kbhit())
		{
			char temp = toupper(_getch());
			if (temp == 'B')
			{
				return;
			}
		}
	}
}