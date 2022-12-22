#include "EFFECT.h"
#include "Header.h"
void EFFECT::deathEffect(CGAME main)
{
	string dead[4] = {
		"...",
		" 0 ",
		"(|)",
		"/ \\",
	};
	for (int i = 0; i < 4; i++)
	{
		main.GoToXY(main.people.getX(), main.people.getY() + i);
		cout << dead[i];
	}
	while (main.people.getY() > -2)
	{
		main.people.setPos(main.people.getX(), main.people.getY() - 1);
		main.GoToXY(main.people.getX(), main.people.getY() + 4);
		cout << "   ";
		for (int i = 0; i < 4; i++)
		{
			if (main.people.getY() + i > 0)
			{
				main.GoToXY(main.people.getX(), main.people.getY() + i);
				cout << dead[i];
			}
		}
		Sleep(100);
	}
	main.clear_maingame();
	main.getMap().drawBoard(65, 15, 23, 4);
	main.GoToXY(67, 16);
	cout << "You lose";
	main.GoToXY(67, 17);
	cout << "Press enter to back";
	while (true)
	{
		if (_getch() == 13)
		{
			break;
		}
	}
}
int EFFECT::saveEffect(CGAME &main)
{
	bool check_;
	main.clear_maingame();
	do
	{
		string computer[] = {
	"            _________________________________________________",
	"           /    _________________________________________    \\",
	"           |   |                                         |   |",
	"           |   |  Enter your name:\\ >                    |   |",
	"           |   |    ( Not over 7 words )                 |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |                                         |   |",
	"           |   |_________________________________________|   |",
	"           \\_________________________________________________/",
	"    	          \\____________________________________/",
	"                ___________________________________________",
	"       	     _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_",
	"          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_",
	"       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_",
	"    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_",
	" _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_",
	":-------------------------------------------------------------------------:",
	"---._.---------------------------------------------------------------._.---",
		};
		main.SetColor(15, 9);
		for (int i = 0; i < 27; i++)
		{
			main.GoToXY(40, 6 + i);
			cout << computer[i];
		}
		main.SetColor(15, 0);

		main.GoToXY(40 + 38, 6 + 3);
		main.name = NhapChuoi(7);
		check_ = main.SaveGame(main.name + ".txt");
		if (check_ == false)
		{
			main.GoToXY(40 + 18, 6 + 6);
			cout << "C:\\ Project_gameOOP\\ Crossing road\\";
			main.GoToXY(40 + 18, 6 + 7);
			main.SetColor(15, 4);
			cout << "\\> " << main.name << ": existing name";
			main.GoToXY(40 + 18, 6 + 8);
			main.SetColor(15, 4);
			cout << "\\> " << main.name << ": Tap to again";
			_getch();
		}
	} while (check_ == false);

	main.GoToXY(40 + 18, 6 + 6);
	cout << "C:\\ Project_gameOOP\\ Crossing road\\";
	main.GoToXY(40 + 18, 6 + 7);
	main.SetColor(15, 4);
	cout << "\\> " << main.name << ": save success";
	main.SetColor(15, 2);
	main.GoToXY(40 + 18, 6 + 8);
	main.SetColor(15, 0);
	cout << "C:\\ Are you exit? ( Enter Y to exit";
	main.GoToXY(40 + 18, 6 + 9);
	cout << " or other word to continue )";
	char a = toupper(_getch());
	if (a == 89)
	{
		return 0;
	}
	return 1;
}
char* EFFECT::NhapChuoi(const int k)
{
	char* kq = new char[k + 1]; // tạo mảng
	int n = 0, index = 0;
	do
	{
		if (_kbhit()) {
		loop:	n = _getch(); // lay ma ASCII
			if (((n >= '0' && n <= '9') || (n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z') || n == ' ' || n == '.') && index < k) // Neu thuoc 0-9, A-Z, a-z hoặc dấu . hoặc khoảng trắng && chuỗi đang có ít hơn k ký tự thì cho phép
			{
				cout << char(n); // xuất ký tự đó ra màn hình
				kq[index++] = n; // Lưu vào mảng
			}
			else if (n == '\b' && index > 0) // Nếu nhấn dấu BackSpace mà chuỗi không rỗng
			{
				cout << "\b \b"; // Xóa 1 ký tự trên màn hình
				kq[--index] = 0; // Xóa 1 ký tự trong chuỗi kq
			}
			if (n == 13 && index == 0)
				goto loop; // Nếu nhấn Enter mà chưa nhập gì thì k cho phép
		}
	} while (n != 13); // Cứ lặp lại trong khi chưa nhập Enter

	kq[index] = 0; // Kết thúc chuỗi
	return kq;

}
int EFFECT::loadEffect(CGAME &main)
{
	main.SetColor(15, 0);
	main.clear_maingame();
	string word[] = {
"    __      _____   ____   ____      __      __   _____   ______ ",
"   |  |    /     \\ /  _ \\ |    \\    |  |    |  | /  ___> |_    _| ",
"   |  |__  |  |  | |  _ | |  |  |   || |__  |  | \\___  \\   |  | ",
"   |_____| \\_____/ \\_/\\_/ |____/    |_____| |__| <_____/   |__| ",
"                                         press 'B' to back Menu "
	};
	main.SetColor(15, 9);
	//drawBoard(40, 5,88, 30);
	for (int i = 0; i < 5; i++)
	{
		main.GoToXY(50, 6 + i);
		cout << word[i];
	}
	main.SetColor(15, 0);
	main.getConsole()->Nocursortype(false);

	fstream a("Name_.txt"); string name;
	int line = 1;
	getline(a, name);
	while (!a.eof())
	{
		getline(a, name, '\n');
		main.GoToXY(75 + 2, 11 + line);
		cout << name;
		if (line == 10)
		{
			break;
		}
		line++;
	}
	string name_;
	main.getMap().drawBoard(75, 11, 15, line + 1);
	do
	{
		main.GoToXY(70, 11 + line + 2); cout << "                                       ";
		main.GoToXY(65, 11 + line + 2);
		main.getConsole()->Nocursortype(false);
		cout << "Input your choose: "; name_ = NhapChuoi(8);
		if (name_ == "B")
		{
			main.getConsole()->Nocursortype(true);
			return 1;
		}
		main.getConsole()->Nocursortype(true);
	} while (main.LoadGame(name_ + ".txt") == false);

	return 0;
}
bool EFFECT::Backeffect(CGAME main) {
	main.SetColor(15, 4);
	main.getMap().drawBoard(65, 15, 40, 4);
	main.GoToXY(67, 16);
	cout << "Do you want save your name ?";
	main.GoToXY(67, 17);
	cout << "Press enter to save or other to Back";
	while (true)
	{
		if (_kbhit)
		{
			if (_getch() == 13)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	main.SetColor(15, 0);
}
