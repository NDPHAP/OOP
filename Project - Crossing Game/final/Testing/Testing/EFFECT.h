#pragma once
#include"CGAME.h"
class EFFECT
{
public:
	char* NhapChuoi(const int k);
	void deathEffect(CGAME main);
	int saveEffect(CGAME &main);
	int loadEffect(CGAME &main);
	bool Backeffect(CGAME main);
};

