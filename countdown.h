// The Watch Project v1.0
// Countdown Mode

#ifndef COUNTDOWN_H_INCLUDED
#define COUNTDOWN_H_INCLUDED

// Included Dependencies
#include <iostream>
#include <unistd.h>
#include <windows.h>
#include "helper.h"
#include "stopwatch.h"

// Countdown Class
class Countdown {
private:
    unsigned int CountDown_Hours, CountDown_Minutes, CountDown_Seconds;
    // Flags to check if the CountDown_Hour,CountDown_Minute
    // or CountDown_Second has been entered by the user
    unsigned int Hour_Entry, Minute_Entry, Second_Entry;

    void Scroll_Selector(int, unsigned int&, std::string, unsigned int&);

public:
    Countdown();
    void Start();
};

#endif // COUNTDOWN_H_INCLUDED
