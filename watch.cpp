// The Watch Project v1.0
// Watch Mode

#include "watch.h"

void Watch::Time_Input()
{
    time_t Current_Time;
    struct tm* Local_Time;

    time(&Current_Time);
    Local_Time = localtime(&Current_Time);

    Hour = (Local_Time->tm_hour);
    if (Hour < 12) {
        AM_or_PM = 'A';
    }
    else {
        AM_or_PM = 'P';
    } // A=AM and P=PM

    Hour = (Local_Time->tm_hour) % 12;
    Minute = (Local_Time->tm_min);
    Second = (Local_Time->tm_sec);

    Day_Of_Week = (Local_Time->tm_wday);
    Date = (Local_Time->tm_mday);
    Month = (Local_Time->tm_mon + 1);
    Year = (Local_Time->tm_year + 1900);
}

void Watch::Time_Output()
{
    std::string Day_Text[] = { "sunday", "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday", "sunday" };

    std::string Month_Text[] = { "january", "february", "march", "april",
        "may", "june", "july", "august",
        "september", "october", "november", "december" };

    while (!GetAsyncKeyState(VK_ESCAPE)) {
        system("cls"); // Clears the console screen

        Time_Input();

        if (Minute == 60) {
            Hour++;
        }
        if (Second == 60) {
            Minute++;
        }
        if ((Hour == 12) && (AM_or_PM = 'A')) {
            Date++;
        }

        std::cout << Day_Text[Day_Of_Week] << "\n\n";

        if (Minute == 0) //"twelve o' clock and thirty seconds"
        {
            std::cout << Helper::Numbers_Text[Hour] << " o' clock and\n"
                      << Helper::Numbers_Text[Second] << " second";
            Helper::Suffix_s(Second, 60);
        }

        if (((Minute > 0) && (Minute <= 30)) && (Second == 0)) //"twenty minutes past twelve"
        {
            std::cout << Helper::Numbers_Text[Minute] << " minute";
            Helper::Suffix_s(Minute, 60);
            std::cout << "\npast\n" << Helper::Numbers_Text[Hour];
        }

        if (((Minute > 0) && (Minute <= 30)) && (Second > 0)) //"twenty minutes and thirty seconds past twelve"
        {
            std::cout << Helper::Numbers_Text[Minute] << " minute";
            Helper::Suffix_s(Minute, 60);

            std::cout << "and " << Helper::Numbers_Text[Second] << " second";
            Helper::Suffix_s(Second, 60);

            std::cout << "past " << Helper::Numbers_Text[Hour];
        }

        if (((Minute > 30) && (Minute <= 60)) && (Second == 0)) //"forty minutes to twelve"
        {
            std::cout << Helper::Numbers_Text[60 - Minute] << " minute";
            Helper::Suffix_s(60 - Minute, 60);
            std::cout << "to\n" << Helper::Numbers_Text[Hour + 1] << "\n";
        }

        if (((Minute > 30) && (Minute <= 60)) && (Second > 0)) //"forty minutes and one second to six"
        {
            std::cout << Helper::Numbers_Text[60 - Minute] << " minute";
            Helper::Suffix_s(60 - Minute, 60);

            std::cout << "and " << Helper::Numbers_Text[60 - Second] << " second";
            Helper::Suffix_s(60 - Second, 60);
            std::cout << "to " << Helper::Numbers_Text[Hour + 1] << "\n";
        }

        if (AM_or_PM == 'A') {
            std::cout << "\nante meridiem\n";
        }
        else {
            std::cout << "\npost meridiem\n";
        }

        std::cout << "\n" << Helper::Numbers_Text[Date] << "\n" << Month_Text[Month - 1]
                  << "\n" << Helper::Numbers_Text[(Year / 1000)] << " thousand and "
                  << Helper::Numbers_Text[(
                         Year % 100)]; //"twenty two november two thousand fifteen"

        Sleep(1000);

        MainWatch_Mode_Switcher();
    }
}
