//The Watch Project v0.6
//Main Source Code

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <windows.h>

#include "stopwatch.cpp"
#include "countdown.cpp"
#include "consoleformat.cpp"

int Hour,Minute,Second;
int Date,Month,Year,Day_Of_Week;
char AM_or_PM;

std::string Numbers_Text[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
                       "twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","thirty","thirty one","thirty two",
                       "thirty three","thirty four","thirty five","thirty six","thirty seven","thirty eight","thirty nine","forty","forty one","forty two","forty three","forty four","forty five",
                       "forty six","forty seven","forty eight","forty nine","fifty","fifty one","fifty two","fifty three","fifty four","fifty five","fifty six","fifty seven","fifty eight",
                       "fifty nine","sixty"};

void Time_Input() //Date and Time Input using CTime
{
time_t Current_Time;
struct tm *Local_Time;

time(&Current_Time);
Local_Time=localtime(&Current_Time); //Gets the Local Time

Hour=(Local_Time->tm_hour); //Hour is 24 hour format to get AM or PM
if(Hour<12) {AM_or_PM='A';} else {AM_or_PM='P';} //A=AM and P=PM

Hour=(Local_Time->tm_hour)%12; //Gets the Hour of the Day, %12 is for 12 Hour Format
Minute=(Local_Time->tm_min); //Gets the Minute of the Hour
Second=(Local_Time->tm_sec); //Gets the Second of the Minute

Day_Of_Week=(Local_Time->tm_wday);  //Gets the Day of the Week
Date=(Local_Time->tm_mday); //Gets the Day of the Month
Month=(Local_Time->tm_mon+1); //Gets the Month of the Year
Year=(Local_Time->tm_year+1900); //Gets the Year
}

inline void MainWatch_Mode_Switcher()
{
if(GetAsyncKeyState(VK_UP)) {CountDown();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
if(GetAsyncKeyState(VK_DOWN)) {StopWatch();} //Changes over to StopWatch Mode if "Down Arrow Key" is pressed
}

inline void Suffix_s(int Time_Entity,unsigned int Max_Value) //Adds an "s" to end the of hour,minute or second if they are not 1
{
if((Time_Entity%Max_Value)!=1) {std::cout<<"s";}
std::cout<<"\n";
}

void Time_Output() //Date and Time Output in Words
{
std::string Day_Text[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
std::string Month_Text[]={"january","february","march","april","may","june","july","august","september","october","november","december"};

for(;;)
    {
    system("cls"); //Clears the console screen

    Time_Input();

    if(Minute==60) {Hour++;}
    if(Second==60) {Minute++;}
    if((Hour==12)&&(AM_or_PM='A')) {Date++;}

    std::cout<<Day_Text[Day_Of_Week]<<"\n\n"; //Displays the Day of the Week

    if(Minute==0) //"twelve o' clock and thirty seconds"
        {
        std::cout<<Numbers_Text[Hour]<<" o' clock and\n"<<Numbers_Text[Second]<<" second\n";
        Suffix_s(Second,60);
        }

    if(((Minute>0)&&(Minute<=30))&&(Second==0)) //"twenty minutes past twelve"
        {
        std::cout<<Numbers_Text[Minute]<<" minute";
        Suffix_s(Minute,60);
        std::cout<<"\npast\n"<<Numbers_Text[Hour];
        }

    if(((Minute>0)&&(Minute<=30))&&(Second>0)) //"twenty minutes and thirty seconds past twelve"
        {
        std::cout<<Numbers_Text[Minute]<<" minute";
        Suffix_s(Minute,60);

        std::cout<<"and "<<Numbers_Text[Second]<<" second";
        Suffix_s(Second,60);

        std::cout<<"past "<<Numbers_Text[Hour]<<"\n";
        }

    if(((Minute>30)&&(Minute<=60))&&(Second==0)) //"forty minutes to twelve"
        {
        std::cout<<Numbers_Text[60-Minute]<<" minute";
        Suffix_s(60-Minute,60);
        std::cout<<"to\n"<<Numbers_Text[Hour+1]<<"\n";
        }

    if(((Minute>30)&&(Minute<=60))&&(Second>0)) //"forty minutes and one second to six"
        {
        std::cout<<Numbers_Text[60-Minute]<<" minute";
        Suffix_s(60-Minute,60);

        std::cout<<"and "<<Numbers_Text[60-Second]<<" second";
        Suffix_s(60-Second,60);
        std::cout<<"to "<<Numbers_Text[Hour+1]<<"\n";
        }

    if(AM_or_PM=='A') {std::cout<<"\nante meridiem\n";} //Displays AM or PM depending upon the time of the day
    else {std::cout<<"\npost meridiem\n";}

    std::cout<<"\n"<<Numbers_Text[Date]<<"\n"<<Month_Text[Month-1]<<"\n"<<Numbers_Text[(Year/1000)]<<" thousand and "<<Numbers_Text[(Year%100)]; //"twenty two november two thousand fifteen"

    Sleep(1000);

    MainWatch_Mode_Switcher();
    }
}

void Main_Watch() //Displays the Day, Time and Date
{
Time_Input();
Time_Output();
}

int main()
{
Console_Formatting();
Main_Watch(); //All other watch modes are accessed from the Main Watch
return 0;
}