// The Watch Project v1.0
// Stopwatch Mode

#include "stopwatch.h"

Stopwatch::Stopwatch()
{
    StopWatch_Hour = 0, StopWatch_Minute = 0, StopWatch_Second = 0;
    Lap_Time_Counter = 1;
}

// Adds an 's' to end the of hour,minute or second if they are not 1
char Stopwatch::Suffix_s_to_file(int Time_Entity, unsigned int Max_Value)
{
    if ((Time_Entity % Max_Value) != 1) {
        return 's';
    }

    return 0;
}

void Stopwatch::Lap_Time_1() //Saves the lap time in numerics
{
    std::ofstream file("StopWatch Lap Times.txt", std::ios::app);

    file << Lap_Time_Counter << ". ";

    file << StopWatch_Hour << ":";
    file << StopWatch_Minute << ":";
    file << StopWatch_Second;

    file << "\n";
    Lap_Time_Counter++;
}

void Stopwatch::Lap_Time_2() //Saves the lap time in words
{
    std::ofstream file("StopWatch Lap Times.txt", std::ios::app);

    file << Lap_Time_Counter << ". ";

    file << Helper::Numbers_Text[StopWatch_Hour % 24] << " hour";
    file << Suffix_s_to_file(StopWatch_Hour, 24) << " ";

    file << Helper::Numbers_Text[StopWatch_Minute % 60] << " minute";
    file << Suffix_s_to_file(StopWatch_Minute, 60) << " and ";

    file << Helper::Numbers_Text[StopWatch_Second % 60] << " second";
    file << Suffix_s_to_file(StopWatch_Second, 60);

    file << "\n";
    Lap_Time_Counter++;
}

void Stopwatch::Start()
{
    while (!GetAsyncKeyState(VK_UP)) {
        system("cls"); // Clears the console screen

        std::cout << "\t StopWatch\n";

        std::cout << "\n\n\n\n" << Helper::Numbers_Text[StopWatch_Hour % 24]
                  << " hour"; // Displays the hour
        Helper::Suffix_s(StopWatch_Hour, 24);

        std::cout << Helper::Numbers_Text[StopWatch_Minute % 60] << " minute";
        Helper::Suffix_s(StopWatch_Minute, 60);

        std::cout << Helper::Numbers_Text[StopWatch_Second % 60]
                  << " second"; // Displays the StopWatch Output
        Helper::Suffix_s(StopWatch_Second, 60);

        if ((StopWatch_Minute % 60) == 59) {
            StopWatch_Hour++;
        }
        if ((StopWatch_Second % 60) == 59) {
            StopWatch_Minute++;
        }
        if ((StopWatch_Second % 60) == 59) {
            StopWatch_Second = 0;
        }

        StopWatch_Second++;

        Sleep(1000);

        Save_To_File();
    }
}
