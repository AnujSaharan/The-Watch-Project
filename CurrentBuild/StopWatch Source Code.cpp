//The Watch Project v0.5
//StopWatch Module

using namespace std;

extern void Main_Watch(); //To access Main_Watch from this file
extern void CountDown(); //To access CountDown from this file

void StopWatch()
{
int StopWatch_Hour=0,StopWatch_Minute=0,StopWatch_Second=0;

string Hour_Text[]={"zero hours","one hour","two hours","three hours","four hours","five hours","six hours","seven hours","eight hours","nine hours","ten hours","eleven hours","twelve hours"};

string Minute_Text[]={"zero minutes","one minute","two minutes","three minutes","four minutes","five minutes","six minutes","seven minutes","eight minutes","nine minutes","ten minutes",
                      "eleven minutes","twelve minutes","thirteen minutes","fourteen minutes","fifteen minutes","sixteen minutes","seventeen minutes","eighteen minutes","nineteen minutes",
                      "twenty minutes","twenty one minutes","twenty two minutes","twenty three minutes","twenty four minutes","twenty five minutes","twenty six minutes","twenty seven minutes",
                      "twenty eight minutes","twenty nine minutes","thirty minutes","thirty one minutes","thirty two minutes","thirty three minutes","thirty four minutes","thirty five minutes",
                      "thirty six minutes","thirty seven minutes","thirty eight minutes","thirty nine minutes","forty minutes","forty one minutes","forty two minutes","forty three minutes",
                      "forty four minutes","forty five minutes","forty six minutes","forty seven minutes","forty eight minutes","forty nine minutes","fifty minutes","fifty one minutes",
                      "fifty two minutes","fifty three minutes","fifty four minutes","fifty five minutes","fifty six minutes","fifty eight minutes","fifty nine minutes"};

string Second_Text[]={"zero seconds","one second","two seconds","three seconds","four seconds","five seconds","six seconds","seven seconds","eight seconds","nine seconds","ten seconds","eleven seconds",
                      "twelve seconds","thirteen seconds","fourteen seconds","fifteen seconds","sixteen seconds","seventeen seconds","eighteen seconds","nineteen seconds","twenty seconds",
                      "twenty one seconds","twenty two seconds","twenty three seconds","twenty four seconds","twenty five seconds","twenty six seconds","twenty seven seconds",
                      "twenty eight seconds","twenty nine seconds","thirty seconds","thirty one seconds","thirty two seconds","thirty three seconds","thirty four seconds","thirty five seconds",
                      "thirty six seconds","thirty seven seconds","thirty eight seconds","thirty nine seconds","forty seconds","forty one seconds","forty two seconds","forty three seconds",
                      "forty four seconds","forty five seconds","forty six seconds","forty seven seconds","forty eight seconds","forty nine seconds","fifty seconds","fifty one seconds",
                      "fifty two seconds","fifty three seconds","fifty four seconds","fifty five seconds","fifty six seconds","fifty seven seconds","fifty eight seconds","fifty nine seconds"};

for(;;)
    {
    system("cls"); //Clears the console screen

    cout<<"\t StopWatch\n";

    cout<<"\n\n\n\n"<<Hour_Text[StopWatch_Hour]<<"\n"<<Minute_Text[StopWatch_Minute]<<"\n"<<Second_Text[StopWatch_Second]; //Displays the StopWatch Output

    if(StopWatch_Hour==24) {StopWatch_Hour=0;}
    if(StopWatch_Minute==59) {StopWatch_Hour++; StopWatch_Minute=0;}
    if(StopWatch_Second==59) {StopWatch_Minute++; StopWatch_Second=0;}

    StopWatch_Second++;

    Sleep(1000); //Freezes the console for a second
    system("cls"); //Clears the console screen every second to update the stopwatch

    if(GetAsyncKeyState(VK_UP)) {Main_Watch();} //Changes over to Main Watch Mode if "Up Arrow Key" is pressed
    if(GetAsyncKeyState(VK_DOWN)) {CountDown();} //Changes over to CountDown Mode if "Down Arrow Key" is pressed
    }
}
