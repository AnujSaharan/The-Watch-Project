//The Watch Project v0.2

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <windows.h>
#include "config.cpp"
using namespace std;

int Hour,Minute,Second;
int Date,Month,Year,Day_Of_Week;
char AM_or_PM;

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

void Time_Output() //Date and Time Output in Words
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

string Day_Text[]={"sunday","monday","tuesday","wednesday","thursday","saturday"};

string Month_Text[]={"january","february","march","april","may","june","july","august","september","october","november","december"};

string Date_Text[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
                    "twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","thirty","thirty one"};

string Year_Prefix_Text[]={"one thousand and","two thousand and","three thousand and","four thousand and","five thousand and","six thousand and","seven thousand and","eight thousand and","nine thousand and"};
string Year_Suffix_Text[]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
                           "twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","thirty"};

for(;;)
    {
    Time_Input();

    if(Minute==60) {Hour++;}
    if(Second==60) {Minute++;}
    if((Hour==12)&&(AM_or_PM='A')) {Date++;}

    cout<<Day_Text[Day_Of_Week]<<"\n\n"; //Displays the Day of the Week

    if(Minute==0) {cout<<Hour_Text[Hour-1]<<" o' clock and\n"<<Second_Text[Second-1]<<"\n\n";} //Displays the time, "twelve o' clock and thirty seconds"

    if(((Minute>0)&&(Minute<=30))&&(Second==0)) {cout<<Minute_Text[Minute-1]<<"\npast\n"<<Hour_Text[Hour-1]<<"\n\n";} //Displays the time, "twenty minutes past twelve"
    if(((Minute>0)&&(Minute<=30))&&(Second>0)) {cout<<Minute_Text[Minute-1]<<"\nand "<<Second_Text[Second]<<"\npast "<<Hour_Text[Hour-1]<<"\n\n";} //Displays the time, "twenty minutes and one second past two

    if(((Minute>30)&&(Minute<=60))&&(Second==0)) {cout<<Minute_Text[59-Minute]<<"\nto\n"<<Hour_Text[Hour]<<"\n\n";} //Displays the time, "forty minutes to twelve"
    if(((Minute>30)&&(Minute<=60))&&(Second>0)) {cout<<Minute_Text[59-Minute]<<"\nand "<<Second_Text[60-Second]<<"\nto "<<Hour_Text[Hour]<<"\n\n";} //Displays the time, "forty minutes and one second to six"

    if(AM_or_PM=='A') {cout<<"ante meridiem";} //Displays AM or PM depending upon the time of the day
    else {cout<<"post meridiem";} //Displays AM or PM depending upon the time of the day

    cout<<"\n\n"<<Date[Date_Text-1]<<endl<<Month_Text[Month]<<endl<<Year_Prefix_Text[(Year/1000)-1]<<" "<<Year_Suffix_Text[(Year%100)-1]; //Displays the Date, "twenty two november 2015"

    sleep(1); //Freezes the console for a second
    system("cls"); //Clears the screen to update the time
    }
}

int main() //Main Function
{
Time_Input();
Time_Output();

return 0;
}
