#pragma once
#include "OBSTRUCTOR.h"

class VEHICLE:public OBSTRUCTOR
{
private:
	string shape[4];
	int type;

	string tank[4] = {
	"_____________/_____ ",
	"___________/______| ",
	"   __/_____\\______\\__ ",
	"   \\(o) (o) (o) (o) (o)| ",
	};
	string bus[4] = {
	"	  _____________ ",
	" _/_|[][][][][]| ",
	"(    City Bus  | ",
	" =--OO-------OO-- ",
	};
	string car[4] = {
	"  ______",
	" /|_||_\\`.__",
	"(   _    _ _\\",
	"=`-(_)--(_)-' ",
	};
	string train[4] = {
	" ,_____  ____  Oo",
	" | PMD \_|[]|_'__Y",
	" |_______|__|_|__}",
	"= oo--oo == oo--OOO\\",
	};

public:
	VEHICLE(int type, int posX, int posY);  // thể loại - vị trí ban đầu - khoảng cách 

	void setShape(string temp[4]);
	string* getShape(string temp[4]);
	int MaxW();

	OBSTRUCTOR* getClone()
	{
		return new VEHICLE(*this);
	}

	void move();

	void init(int type, int posX, int posY);
	int getType() { int temp = type; return temp; };
	void setType(int data) { this->type = data; };
};
