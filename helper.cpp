// The Watch Project v1.0
// Helper Module (helper.h)
// Functions common to all modes are stored in helper

#include "helper.h"

// Adds an 's' to end the of hour,minute or second if they are not 1
void Helper::Suffix_s(int Time_Entity, unsigned int Max_Value)
{
    if ((Time_Entity % Max_Value) != 1) {
        std::cout << "s";
    }
    std::cout << "\n";
}

// Controls the visibility of the console cursor
void Helper::Show_Console_Cursor(HANDLE wHnd, bool Show_Flag)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(wHnd, &cursorInfo);
    cursorInfo.bVisible = Show_Flag; // Sets the cursor visibility
    SetConsoleCursorInfo(wHnd, &cursorInfo);
}

void Helper::Console_Formatting()
{
    // Handle to write to the console.
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    // Changes text on the Title Bar of the Console Screen
    SetConsoleTitle("TWP v1.0");

    // Set up the required window size
    SMALL_RECT windowSize = { 0, 0, 25, 10 };
    // Change the console window size
    SetConsoleWindowInfo(wHnd, 1, &windowSize);

    // Create a COORD to hold the buffer size
    COORD bufferSize = { 10, 10 };
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    // Hides the blinking underscore in the Console
    Show_Console_Cursor(wHnd, false);
}

std::string Helper::Numbers_Text[] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
    "twenty", "twenty one", "twenty two", "twenty three", "twenty four",
    "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine",
    "thirty", "thirty one", "thirty two", "thirty three", "thirty four",
    "thirty five", "thirty six", "thirty seven", "thirty eight", "thirty nine",
    "forty", "forty one", "forty two", "forty three", "forty four",
    "forty five", "forty six", "forty seven", "forty eight", "forty nine",
    "fifty", "fifty one", "fifty two", "fifty three", "fifty four",
    "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine",
    "sixty"
};
