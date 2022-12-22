#include "CGAME.h"
#include "VEHICLE.h"
#include <time.h>
int num_inlane = 4;
int speed = 100;
int pause_key = 1;

CGAME::CGAME()
{
	int distance = 35;
	level = 0;
	name = "";
	state = 0;
}
void CGAME::initGame()
{
	people.setPos(3, 2);
	int distance = 35;
	clearData();
	if (level % 2 == 0)
	{
		for (int i = 0; i < num_inlane; i++)
		{
			OBSTRUCTOR* temp = new ANIMAL(1, 3 + distance * i, 7);
			lane1.push_back(temp);
			lane1[i]->setDistance(distance);
			temp = new ANIMAL(0, 30 + distance * i, 16);
			lane2.push_back(temp);
			lane2[i]->setDistance(distance);
			temp = new ANIMAL(2, 18 + distance * i, 25);
			lane3.push_back(temp);
			lane3[i]->setDistance(distance);
			temp = new ANIMAL(3, 3 + distance * i, 34);
			lane4.push_back(temp);
			lane4[i]->setDistance(distance);
		}
	}
	else
	{
		for (int i = 0; i < num_inlane; i++)
		{
			VEHICLE* temp = new VEHICLE(1, 3 + distance * i, 7);
			temp->setDistance(35);
			lane1.push_back(temp);
			temp = new VEHICLE(0, 30 + distance * i, 16);
			lane2.push_back(temp);
			temp = new VEHICLE(2, 18 + distance * i, 25);
			lane3.push_back(temp);
			temp = new VEHICLE(3, 3 + distance * i, 34);
			lane4.push_back(temp);
		}
	}
	people.init();
}
void CGAME::drawObs()
{
	string temp[4];
	for (int i = 0; i < num_inlane; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < lane1[i]->getShape(temp)[j].length(); f++)
			{
				if (lane1[i]->getX() + f < 144 && lane1[i]->getX() + f > 0)
				{
					GoToXY(lane1[i]->getX() + f, lane1[i]->getY() + j);
					cout << lane1[i]->getShape(temp)[j][f];
				}
			}
		}
	}
	for (int i = 0; i < num_inlane; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < lane2[i]->getShape(temp)[j].length(); f++)
			{
				if (lane2[i]->getX() + f < 144 && lane2[i]->getX() + f > 0)
				{
					GoToXY(lane2[i]->getX() + f, lane2[i]->getY() + j);
					cout << lane2[i]->getShape(temp)[j][f];
				}
			}
		}
	}
	for (int i = 0; i < num_inlane; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < lane3[i]->getShape(temp)[j].length(); f++)
			{
				if (lane3[i]->getX() + f < 144 && lane3[i]->getX() + f > 0)
				{
					GoToXY(lane3[i]->getX() + f, lane3[i]->getY() + j);
					cout << lane3[i]->getShape(temp)[j][f];
				}
			}
		}
	}
	for (int i = 0; i < num_inlane; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int f = 0; f < lane4[i]->getShape(temp)[j].length(); f++)
			{
				if (lane4[i]->getX() + f < 144 && lane4[i]->getX() + f > 0)
				{
					GoToXY(lane4[i]->getX() + f, lane4[i]->getY() + j);
					cout << lane4[i]->getShape(temp)[j][f];
				}
			}
		}
	}
	
}
void CGAME::drawPeople()
{
	SetColor(15, 0);
	for (int i = 0; i < 3; i++)
	{
		GoToXY(people.getX(), people.getY() + i);
		std::cout << people.getShape(i);
	}
	SetColor(15, 0);
}
void CGAME::ControlPeople(char key)
{
	CPEOPLE temp(people);
	if (key == 'A' || key == 'D' || key == 'S' || key == 'W')
	{
		people.move(key);
		if (map.isCollision(people) == false)
		{
			people.setPos(temp.getX(), temp.getY());
		}
	}
	drawPeople();
}
bool CGAME::isCollision(OBSTRUCTOR *obs, CPEOPLE peole)
{
	string tmp_shape[4];
	obs->getShape(tmp_shape);
	for (int i = 0; i < obs->getH(); i++)
	{
		int tempX = obs->getX();
		int tempY = obs->getY() + i;

		int tempW = tmp_shape[i].length();
		int tempH = 1;

		int sizePeo = 3;

		if ((people.getX() + 2 >= tempX) && (tempX + tempW - 1 >= people.getX())
			&& (people.getY() + 2 >= tempY) && (tempY + tempH - 1 >= people.getY()))
		{
			return true;
		}
	}
	return false;
}
bool CGAME::isWin(){
	GoToXY(140, 40);
	cout << ">";
	if (people.getX() == 140
		&& people.getY() == 40)
	{
		return true;
	}
	return false;
}
bool CGAME::isDead()
{
	for (int i = 0; i < 4; i++)
	{
		if (isCollision(lane1[i], people) == true || (isCollision(lane2[i], people) == true)
			|| (isCollision(lane3[i], people) == true) || (isCollision(lane4[i], people) == true))
		{
			people.setState(false);
			return true;
		}
	}
	return false;
}
void CGAME::ControlObs(TRAFFIC traffic)
{
	if (traffic.pause_key == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			lane1[i]->move();
			lane2[i]->move();
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			lane3[i]->move();
			lane4[i]->move();
		}
	}
	drawObs();
}
bool CGAME::ControlGame(char key)
{
	return true;
}
void CGAME::clear_maingame()
{
	for (int i = 1; i < 144; i++)
	{
		for (int j = 1; j < 44; j++)
		{
			GoToXY(i, j);
			cout << " ";
		}
		//Sleep(0);
	}
}
#include <io.h>
#include <fstream>
#include <conio.h>
bool CGAME::SaveGame(string filename)
{
	fstream file;
	fstream fname("Name_.txt");
	string temp;
	int num = 0;
	fname >> num;
	vector<string> list;
	name = filename;
	for (int i = 0; i < 4; i++)
	{
		name.pop_back();
	}

	file.open("SaveGame/" + filename);
	if (file.fail() == true)
	{
		for (int i = 0; i <= num; i++)
		{
			getline(fname, temp);
			if (temp != "")
				list.push_back(temp);
		}
		list.push_back(name);
		fname.close();


		fname.open("Name_.txt", ios::out);
		fname << num + 1 << endl;
		for (int i = 0; i < num + 1; i++)
		{
			fname << list[i] << endl;
		}
		fname.close();

		file.open("SaveGame/" + filename, ios::out);

	DATA:
		file << name << endl;
		file << state << " " << people.getX() << " " << people.getY() << endl;
		file << level << endl;
		for (int i = 0; i < 4; i++)
		{
			file << lane1[i]->getType()<< " " << lane1[i]->getX() << " " << lane1[i]->getY() << " " << lane1[i]->getDistance() << endl;
			//file << lane1_.getType() << " " << lane1[i].getX() << " " << lane1_.obs[i].getY() << " " << lane1_.getDistance() << endl;

			file << lane2[i]->getType() << " " << lane2[i]->getX() << " " << lane2[i]->getY() << " " << lane2[i]->getDistance() << endl;
			//file << lane2_.getType() << " " << lane2_.obs[i].getX() << " " << lane2_.obs[i].getY() << " " << lane2_.getDistance() << endl;

			file << lane3[i]->getType() << " " << lane3[i]->getX() << " " << lane3[i]->getY() << " " << lane3[i]->getDistance() << endl;
			//file << lane3_.getType() << " " << lane3_.obs[i].getX() << " " << lne3_.obs[i].getY() << " " << lane3_.getDistance() << endl;
		
			file << lane4[i]->getType() << " " << lane4[i]->getX() << " " << lane4[i]->getY() << " " << lane4[i]->getDistance() << endl;
			//file << lane4_.getType() << " " << lane4_.obs[i].getX() << " " << lane4_.obs[i].getY() << " " << lane4_.getDistance() << endl;
		}
	}
	else
	{
		goto DATA;
	}
	return true;
}
bool CGAME::LoadGame(string filename)
{
	//initGame();
	clearData();
	fstream file;
	file.open("SaveGame/" + filename);
	if (file.fail())
	{
		return false;
	}
	else
	{
		string temp;
		string temp2;

		int type, x, y, dis;
		while (!file.eof())
		{
			getline(file, temp);
			name = temp;
			temp = temp + ".txt";
			if (temp.compare(filename) == 0)
			{
				getline(file, temp, ' ');
				state = (stoi(temp));

				getline(file, temp, ' ');
				getline(file, temp2);
				people.setPos(stoi(temp), stoi(temp2));
				getline(file, temp2,'\n');
				level = stoi(temp2);
				if (state == 0) {
					for (int i = 0; i < 4; i++)
					{
						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data = new ANIMAL(type, x, y);
						data->setDistance(dis);
						lane1.push_back(data);

						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data2 = new ANIMAL(type, x, y);
						data2->setDistance(dis);
						lane2.push_back(data2);

						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data3 = new ANIMAL(type, x, y);
						data3->setDistance(dis);
						lane3.push_back(data3);

						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data4 = new ANIMAL(type, x, y);
						data4->setDistance(dis);
						lane4.push_back(data4);
					}
				}
				else {
					for (int i = 0; i < 4; i++)
					{
						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data = new VEHICLE(1, 3 + dis * i, 7);
						data->setDistance(dis);
						lane1.push_back(data);


						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data2 = new VEHICLE(1, 3 + dis * i, 7);
						data2->setDistance(dis);
						lane2.push_back(data2);

						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data3 = new VEHICLE(1, 3 + dis * i, 7);
						data3->setDistance(dis);
						lane3.push_back(data3);

						getline(file, temp, ' ');
						type = stoi(temp);
						getline(file, temp, ' ');
						x = stoi(temp);
						getline(file, temp, ' ');
						y = stoi(temp);
						getline(file, temp, '\n');
						dis = stoi(temp);
						OBSTRUCTOR* data4 = new VEHICLE(1, 3 + dis * i, 7);
						data4->setDistance(dis);
						lane4.push_back(data4);
					}
				}
				break;
			}
		}

	}
	return true;
}
using namespace std;
#include "EFFECT.h"
CMAP CGAME::map;
TRAFFIC CGAME::traffic;
bool CGAME::startgame(CGAME *load_data)
{
	EFFECT effect;
	char movekey = ' ';
	if (load_data == NULL)
	{
	UP_level:
		level++;
		initGame();
	}
	else
	{
		*this = load_data[0];
	}
	map.init_icon();
	map.draw();
	drawObs();
	drawPeople();
	GoToXY(149, 34);
	SetColor(15, 3);
	std::cout << " Your name : " << name;
	GoToXY(149, 35);
	cout << " Level : " << level;
	SetColor(15, 0);
	while (true)
	{
		pause_key = traffic.getPausekey();
		traffic.draw(pause_key);

		if (_kbhit() && movekey == ' ')
		{
			movekey = toupper(_getch());
			ControlPeople(movekey);
			ControlGame(movekey);
				if (movekey == 'L')
				{
					if (name == "")
					{
					SAVE:
						if (effect.saveEffect(*this) == 0)
						{
							cons->Nocursortype(true);
							return true;
						}
						else
						{
							clear_maingame();
							SetColor(15, 3);
							GoToXY(149, 34);
							std::cout << " Your name : " << name;
							SetColor(15, 0);
							cons->Nocursortype(true);
							drawPeople();
							drawObs();
							map.draw();
						}
					}
					else
					{
						SaveGame(name + ".txt");
						GoToXY(149, 36);
						SetColor(15, 4);
						std::cout << "   Your data have updated !";
						SetColor(15, 0);
						movekey = ' ';
						continue;
						//return true;
					}
				}
				else if (movekey == 'B')
				{
					if (name == "")
					{
						if (effect.Backeffect(*this) == true)
						{
							goto SAVE;
						}
						else
						{
							return true;
						}
					}
					else
					{
						SaveGame(name + ".txt");
						return true;
					}
				}
				else if(movekey == 'T')
				{
					effect.loadEffect(*this);
					clear_maingame();
					cons->Nocursortype(true);
					drawPeople();
					drawObs();
					map.draw();
				}
				GoToXY(149, 36);
				cout << "                           ";
			movekey = ' ';
		}
		else{ ControlObs(traffic);}

		if (isDead() == true)
		{
			effect.deathEffect(*this);
			return false;
		}

		if (isWin() == true)
		{
			clearData();
			clear_maingame();
			goto UP_level;
		}
		
	}
	return true;
}