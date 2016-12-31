// The Watch Project v1.0
// Watch Mode

#ifndef WATCH_H_INCLUDED
#define WATCH_H_INCLUDED

// Included Dependencies
#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>
#include "stopwatch.h"
#include "countdown.h"

// Watch Class
class Watch {
private:
    char AM_or_PM;
    int Hour, Minute, Second;
    int Date, Month, Year, Day_Of_Week;

public:
    void Time_Input();
    void Time_Output();
    void MainWatch_Mode_Switcher();
};

inline void Watch::MainWatch_Mode_Switcher()
{
    if (GetAsyncKeyState(VK_UP)) {
        Countdown().Start();
    }

    if (GetAsyncKeyState(VK_DOWN)) {
        Stopwatch().Start();
    }
}

#endif // WATCH_H_INCLUDED
