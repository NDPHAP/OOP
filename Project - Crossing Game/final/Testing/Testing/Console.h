#pragma once
#include <Windows.h>
#include"CPEOPLE.h"
#include <iostream>
using namespace std;
class Console
{
protected:
    SHORT height, width;
    HANDLE hConsoleOutput;
    HANDLE hConsoleInput;
public:
    Console();
    SHORT getHeight() { SHORT temp = height; return temp; };
    SHORT getWidth() { SHORT temp = width; return temp; };
    void SetWindowSize();
    void SetScreenBufferSize();
    void SetColor(int backgound_color, int text_color);
    void GoToXY(SHORT posX, SHORT posY);
    void setBackgroundColor(WORD color);
    void Nocursortype(bool a);

    //void draw();
};



