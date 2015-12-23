//The Watch Project v0.6
//CountDown Module

#include <iostream>
#include <unistd.h>
#include <windows.h>

extern void Main_Watch(); //To access Main Watch from this file
extern void StopWatch(); //To access StopWatch from this file
extern std::string Numbers_Text[]; //To access Numbers in Words from this file

unsigned int CountDown_Hours=0,CountDown_Minutes=0,CountDown_Seconds=0;

inline void CountDown_Mode_Changer()
{
if(GetAsyncKeyState(VK_UP)) {StopWatch();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
if(GetAsyncKeyState(VK_DOWN)) {Main_Watch();} //Changes over to Main Watch Mode if "Down Arrow Key" is pressed
}

void Scroll_Selector(int Number_of_Elements,unsigned int &Entry_Variable,std::string Number_Suffix,unsigned int &Entry_Checker) //Function to scroll through a list of options
{
int Selection_Index=0; //Index to scroll through the elements during Selection

while(Entry_Checker!=1)
    {
    std::cout<<"\t CountDown\n\n\n\n\n";
    std::cout<<Numbers_Text[Selection_Index]<<Number_Suffix;
    Suffix_s(Selection_Index,Number_of_Elements-1);

    if(GetAsyncKeyState(VK_RIGHT)) //Displays the next string if the "Right Arrow Key" is pressed
        {
        Selection_Index++;

        if(Selection_Index==Number_of_Elements)
            {
            Selection_Index=0;
            }
        }

    if(GetAsyncKeyState(VK_LEFT)) //Displays the previous string if the "Left Arrow Key" is pressed
        {
        Selection_Index--;

        if(Selection_Index==-1)
            {
            Selection_Index=Number_of_Elements-1;
            }
        }

    if(GetAsyncKeyState(VK_RETURN)) //Stores the currently displayed variable if "Return" is pressed
        {
        Entry_Variable=Selection_Index;
        Entry_Checker=1;
        Selection_Index=0;

        Sleep(100);
        system("cls");
        break;
        }

    else
        {
        Sleep(130);
        }
    system("cls");

    CountDown_Mode_Changer();
    }
}

void CountDown()
{
system("cls"); //Clears the console screen

unsigned int Hour_Entry=0,Minute_Entry=0,Second_Entry=0; //Flags to check if the CountDown_Hour,CountDown_Minute or CountDown_Second has been entered by the user

if(Hour_Entry==0)
    {
    Scroll_Selector(25,CountDown_Hours," hour",Hour_Entry);
    }

if((Hour_Entry==1)&&(Minute_Entry==0))
    {
    Scroll_Selector(60,CountDown_Minutes," minute",Minute_Entry);
    }

if((Minute_Entry==1)&&(Hour_Entry==1))
    {
    Scroll_Selector(60,CountDown_Seconds," second",Second_Entry);
    }

if((Hour_Entry==1)&&(Minute_Entry==1)&&(Second_Entry==1))
    {
    while((CountDown_Hours>=0)||(CountDown_Minutes>=0)||(CountDown_Seconds>0)) //Loop to display the CountDown
        {
        system("cls");

        std::cout<<"\t CountDown\n";

        std::cout<<"\n\n\n\n"<<Numbers_Text[CountDown_Hours]<<" hour";
        Suffix_s(CountDown_Hours,24);

        std::cout<<Numbers_Text[CountDown_Minutes]<<" minute";
        Suffix_s(CountDown_Minutes,60);

        std::cout<<Numbers_Text[CountDown_Seconds]<<" second";
        Suffix_s(CountDown_Seconds,60);

        if(CountDown_Seconds==0)
            {
            CountDown_Minutes--;
            CountDown_Seconds=60;
            }

        if((CountDown_Minutes==0)&&(CountDown_Hours>0))
            {
            CountDown_Hours--;
            CountDown_Minutes=60;
            }

        CountDown_Seconds--;

        Sleep(1000);

        CountDown_Mode_Changer();
        }
    }
}