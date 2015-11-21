#include <iostream>
#include <ctime>
#include <unistd.h>
#include <windows.h>
using namespace std;

int Hour,Minute,Second;
int Day,Month,Year;

void Time_Input() //Date and Time Input using CTime
{
time_t currentTime;
struct tm *localTime;

time(&currentTime);
localTime=localtime(&currentTime);

Hour=(localTime->tm_hour)%12; //%12 is for 12 Hour Format
Minute=(localTime->tm_min);
Second=(localTime->tm_sec);

Day=(localTime->tm_mday);
Month=(localTime->tm_mon+1);
Year=(localTime->tm_year+1900);
}

void Time_Output() //Time Output in Words
{
string Hour_Text[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};

string Minute_Text[]={"one minute","two minutes","three minutes","four minutes","five minutes","six minutes","seven minutes","eight minutes","nine minutes","ten minutes","eleven minutes",
                      "twelve minutes","thirteen minutes","fourteen minutes","quarter","sixteen minutes","seventeen minutes","eighteen minutes","nineteen minutes","twenty minutes",
                      "twenty one minutes","twenty two minutes","twenty three minutes","twenty four minutes","twenty five minutes","twenty six minutes","twenty seven minutes",
                      "twenty eight minutes","twenty nine minutes","half"};

string Second_Text[]={"zero seconds","one second","two seconds","three seconds","four seconds","five seconds","six seconds","seven seconds","eight seconds","nine seconds","ten seconds","eleven seconds",
                      "twelve seconds","thirteen seconds","fourteen seconds","fifteen seconds","sixteen seconds","seventeen seconds","eighteen seconds","nineteen seconds","twenty seconds",
                      "twenty one seconds","twenty two seconds","twenty three seconds","twenty four seconds","twenty five seconds","twenty six seconds","twenty seven seconds",
                      "twenty eight seconds","twenty nine seconds","thirty seconds","thirty one seconds","thirty two seconds","thirty three seconds","thirty four seconds","thirty five seconds",
                      "thirty six seconds","thirty seven seconds","thirty eight seconds","thirty nine seconds","forty seconds","forty one seconds","forty two seconds","forty three seconds",
                      "forty four seconds","forty five seconds","forty six seconds","forty seven seconds","forty eight seconds","forty nine seconds","fifty seconds","fifty one seconds",
                      "fifty two seconds","fifty three seconds","fifty four seconds","fifty five seconds","fifty six seconds","fifty seven seconds","fifty eight seconds","fifty nine seconds"};

for(;;)
    {
    Time_Input();

    if(Minute==60) {Hour++;}
    if(Second==60) {Minute++;}

    if(Minute==0) {cout<<Hour_Text[Hour-1]<<" o' clock and\n"<<Second_Text[Second-1];}

    if(((Minute>0)&&(Minute<=30))&&(Second==0)) {cout<<Minute_Text[Minute-1]<<"\npast\n"<<Hour_Text[Hour-1];}
    if(((Minute>0)&&(Minute<=30))&&(Second>0)) {cout<<Minute_Text[Minute-1]<<"\nand "<<Second_Text[Second]<<"\npast "<<Hour_Text[Hour-1];}

    if(((Minute>30)&&(Minute<=60))&&(Second==0)) {cout<<Minute_Text[59-Minute]<<"\nto\n"<<Hour_Text[Hour];}
    if(((Minute>30)&&(Minute<=60))&&(Second>0)) {cout<<Minute_Text[59-Minute]<<"\nand "<<Second_Text[60-Second]<<"\nto "<<Hour_Text[Hour];}

    sleep(1); //Freezes the console for 1 second
    system("cls"); //Clears the screen to update the time
    }
}

void Date_Output() //Date Output in Numericals
{
Time_Input();
cout<<Day<<" "<<Month<<" "<<Year<<endl;
}

int main() //Main Function
{
Time_Input();
Time_Output();

return 0;
}
