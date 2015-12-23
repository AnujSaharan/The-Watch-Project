//The Watch Project v0.6
//StopWatch Module

#include <iostream>
#include <unistd.h>
#include <windows.h>

extern void Main_Watch(); //To access Main_Watch from this file
extern void CountDown(); //To access CountDown from this file
extern inline void Suffix_s(int Time_Entity,unsigned int Max_Value);

extern std::string Numbers_Text[];

void StopWatch_Mode_Switcher()
{
if(GetAsyncKeyState(VK_UP)) {Main_Watch();} //Changes over to Main Watch Mode if "Up Arrow Key" is pressed
if(GetAsyncKeyState(VK_DOWN)) {CountDown();} //Changes over to CountDown Mode if "Down Arrow Key" is pressed
}

void StopWatch()
{
int StopWatch_Hour=0,StopWatch_Minute=0,StopWatch_Second=0;

for(;;)
    {
    system("cls"); //Clears the console screen

    std::cout<<"\t StopWatch\n";

    std::cout<<"\n\n\n\n"<<Numbers_Text[StopWatch_Hour%24]<<" hour"; //Displays the hour
    Suffix_s(StopWatch_Hour,24);

    std::cout<<Numbers_Text[StopWatch_Minute%60]<<" minute";
    Suffix_s(StopWatch_Minute,60);

    std::cout<<Numbers_Text[StopWatch_Second%60]<<" second"; //Displays the StopWatch Output
    Suffix_s(StopWatch_Second,60);

    if((StopWatch_Minute%60)==59) {StopWatch_Hour++;}
    if((StopWatch_Second%60)==59) {StopWatch_Minute++;}

    StopWatch_Second++;

    Sleep(1000);

    StopWatch_Mode_Switcher();
    }
}