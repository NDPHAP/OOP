#include "Header.h"

int main()
{
	EFFECT effect;
	MENU menua(1, 1);
	CGAME main_game; 
	CGAME* load_data = NULL;
RETURN:
	if (load_data != NULL)
	{
		delete load_data;
		load_data = NULL;
	}
	switch (menua.show_Menu("********** MENU **********", "NEW GAME", "CONTINUE", "ABOUT US", "EXIT"))
	{
	case 1:
		menua.clear(0);
		main_game.name = "";
		main_game.level = 0;
		goto PLAY;
	case 2:
		menua.clear(0);
		load_data = new CGAME;
		if (effect.loadEffect(load_data[0]) == 1)
		{
			goto RETURN;
		}
		menua.clear(0);
		break;
	case 3:
		menua.clear(0);
		menua.aboutUs();
		goto RETURN;
		break;
	case 4:
		return 0;
	}

PLAY:
	if (main_game.startgame(load_data) == true)
	{
		goto RETURN;
	}
	menua.clear(0);
	goto RETURN;
	return 0;
}