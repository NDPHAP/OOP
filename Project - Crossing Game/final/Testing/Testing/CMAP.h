#pragma once
#include <iostream>
#include "Console.h"

using namespace std;

const char gocduoitrai_ = 200;
const char canhdung_ = 186;
const char canhngang_ = 205;
const char gocduoiphai_ = 188;
const char goctrentrai_ = 201;
const char goctrenphai_ = 187;

class CMAP : Console
{
private:
    POINT wall[30];
    string shape[30];
    string book[100] = {
        "      ______ ______",
        "    _/      Y      \\_",
        "   // ~~ ~~ | ~~ ~  \\\\",
        "  // ~ ~ ~~ | ~~~ ~~ \\\\",
        " //________.|.________\\\\",
        "`----------`-'----------'",
    };
    int i;
public:
    CMAP();
    void setwall();
    bool isCollision(CPEOPLE peo);
    void draw();
    void drawBoard(int x, int y, int w, int h);
    void Word();
    void init_icon()
    {
        setwall();
    }
};
 