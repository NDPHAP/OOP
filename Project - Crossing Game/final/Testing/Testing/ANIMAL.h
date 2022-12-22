#pragma once
#include "OBSTRUCTOR.h"
class ANIMAL : public OBSTRUCTOR
{
private:
	string shape[4];
	int type;

	string Dog[4] = {
	"  /-   __",
	" (___()'`;",
	"/ ,   /`",
	"||'--\\\\",
	};
	string Hedgehog[4] = {
	"  .::::::::..",
	":::::::::::::",
	":::::::::: :'.\\",
	"`::::::::::_,__o",
	};
	string Fox[4] = {
	"|\\_/|.._____ ",
	"(.'.)~~     )`~ ",
	" \\o/\\ /---~\\\\ ",
	"   _//    _// ",
	};
	string Mouse[4] = {
	 " (`-()_.-= . ",
	 " /66  ,  ,\\ ",
	 "(o_/=//_( / ",
	 "  ~' ~'~~` ",
	};

public:
	ANIMAL(int type, int posX, int posY);  // thể loại - vị trí ban đầu - khoảng cách 

	void setShape(string temp[4]);
	string* getShape(string temp[4]);
	int MaxW();

	OBSTRUCTOR* getClone()
	{
		return new ANIMAL(*this);
	}

	void move();

	void init(int type, int posX, int posY);
	int getType() { int temp = type; return temp; };
	void setType(int data) { this->type = data; };
};

