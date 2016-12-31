// The Watch Project v1.0
// Countdown Mode

#include "countdown.h"

// Constructor
Countdown::Countdown()
{
    CountDown_Hours = 0, CountDown_Minutes = 0, CountDown_Seconds = 0;
    Hour_Entry = 0, Minute_Entry = 0, Second_Entry = 0;
}

// Start countdown
void Countdown::Start()
{
    system("cls"); // Clears the console screen

    if (Hour_Entry == 0) {
        Scroll_Selector(25, CountDown_Hours, " hour", Hour_Entry);
    }

    if ((Hour_Entry == 1) && (Minute_Entry == 0)) {
        Scroll_Selector(60, CountDown_Minutes, " minute", Minute_Entry);
    }

    if ((Minute_Entry == 1) && (Hour_Entry == 1)) {
        Scroll_Selector(60, CountDown_Seconds, " second", Second_Entry);
    }

    if ((Hour_Entry == 1) && (Minute_Entry == 1) && (Second_Entry == 1)) {

        while ((CountDown_Hours >= 0) || (CountDown_Minutes >= 0) || (CountDown_Seconds >= 0)) // Loop to display the CountDown
        {
            system("cls");

            std::cout << "\t CountDown\n";

            std::cout << "\n\n\n\n" << Helper::Numbers_Text[CountDown_Hours] << " hour";
            Helper::Suffix_s(CountDown_Hours, 24);

            std::cout << Helper::Numbers_Text[CountDown_Minutes] << " minute";
            Helper::Suffix_s(CountDown_Minutes, 60);

            std::cout << Helper::Numbers_Text[CountDown_Seconds] << " second";
            Helper::Suffix_s(CountDown_Seconds, 60);

            if ((CountDown_Seconds == 0) && (CountDown_Minutes > 0)) {
                CountDown_Minutes--;
                CountDown_Seconds = 60;
            }

            if ((CountDown_Minutes == 0) && (CountDown_Hours > 0)) {
                CountDown_Hours--;
                CountDown_Minutes = 60;
            }

            if (CountDown_Seconds != 0) {
                CountDown_Seconds--;
            }

            else {
                std::cout << "\nCountdown Finished." << std::endl;
                Sleep(3000);
                break;
            };

            Sleep(1000);
        }
    }
}

// Function to scroll through a list of options
void Countdown::Scroll_Selector(int Number_of_Elements, unsigned int& Entry_Variable,
    std::string Number_Suffix, unsigned int& Entry_Checker)
{
    int Selection_Index = 0; // Index to scroll through the elements during Selection

    while (Entry_Checker != 1) {
        std::cout << "\t CountDown\n\n\n\n\n";
        std::cout << Helper::Numbers_Text[Selection_Index] << Number_Suffix;
        Helper::Suffix_s(Selection_Index, (unsigned int)(Number_of_Elements - 1));

        if (GetAsyncKeyState(VK_RIGHT)) // Displays the next string if the "Right Arrow Key" is pressed
        {
            Selection_Index++;

            if (Selection_Index == Number_of_Elements) {
                Selection_Index = 0;
            }
        }

        if (GetAsyncKeyState(VK_LEFT)) // Displays the previous string if the "Left Arrow Key" is pressed
        {
            Selection_Index--;

            if (Selection_Index == -1) {
                Selection_Index = Number_of_Elements - 1;
            }
        }

        if (GetAsyncKeyState(VK_RETURN)) // Stores the currently displayed variable if "Return" is pressed
        {
            Entry_Variable = (unsigned int)Selection_Index;
            Entry_Checker = 1;
            Selection_Index = 0;

            Sleep(100);
            system("cls");
            break;
        }

        else {
            Sleep(130);
        }
        system("cls");
    }
}
