// The Watch Project v1.0
// Stopwatch Mode

#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED

// Included Dependencies
#include <fstream>
#include <unistd.h>
#include <windows.h>
#include "helper.h"

// Stopwatch Class
class Stopwatch {
private:
    int StopWatch_Hour, StopWatch_Minute, StopWatch_Second;
    int Lap_Time_Counter;

    char Suffix_s_to_file(int, unsigned int);
    void Lap_Time_1();
    void Lap_Time_2();
    void Save_To_File();

public:
    Stopwatch();
    void Start();
};

inline void Stopwatch::Save_To_File()
{
    if (GetAsyncKeyState(VK_SPACE)) {
        Lap_Time_1();
    } // Saves current time to file if "Spacebar" is pressed
    if (GetAsyncKeyState(VK_RCONTROL)) {
        Lap_Time_2();
    } // Saves current time to file if "Right Control" is pressed
}

#endif // STOPWATCH_H_INCLUDED
