//The Watch Project v0.6
//Console Formatting Module

#include <windows.h>

void Show_Console_Cursor(bool Show_Flag) //Controls the visibility of the console cursor
{
HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursorInfo;
GetConsoleCursorInfo(out,&cursorInfo);
cursorInfo.bVisible=Show_Flag; // Sets the cursor visibility
SetConsoleCursorInfo(out,&cursorInfo);
}

void Console_Formatting()
{
system("mode con:cols=28 lines=13"); //Resizes the console window
SetConsoleTitle("TWP v0.6"); //Changes text on the Title Bar of the Console Screen
Show_Console_Cursor(false); //Hides the blinking underscore in the Console
}