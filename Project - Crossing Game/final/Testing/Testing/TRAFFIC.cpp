#include "TRAFFIC.h"
#include <time.h>
int pause_time = 3000;

void TRAFFIC::draw(int a)
{
    if (a != pause_key)
    {
        pause_key = a;
        SetColor(4, 4);
        if (a == 2)
        {
            SetColor(4, 4);
            GoToXY(144, 7);
            cout << " ";
            GoToXY(144, 16);
            cout << " ";
            SetColor(2, 2);
            GoToXY(144, 25);
            cout << " ";
            GoToXY(144, 34);
            cout << " ";
            SetColor(15, 0);
        }
        else
        {
            SetColor(4, 4);
            GoToXY(144, 25);
            cout << " ";
            GoToXY(144, 34);
            cout << " ";
            SetColor(2, 2);
            GoToXY(144, 7);
            cout << " ";
            GoToXY(144, 16);
            cout << " ";
        }
        SetColor(15, 0);
    }
}
int TRAFFIC::getPausekey()
{
    clock_t time;
    time = clock();
    if ((time / pause_time) % 2 == 0)
    {
        return  1;
    }
    else
    {
        return 2;
    }
}