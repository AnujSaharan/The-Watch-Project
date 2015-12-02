//The Watch Project v0.5
//CountDown Module

using namespace std;

extern void Main_Watch(); //To access Main Watch from this file
extern void StopWatch(); //To access StopWatch from this file


void CountDown()
{
system("cls"); //Clears the console screen

int CountDown_Hours=-1,CountDown_Minutes=-1,CountDown_Seconds=-1;

string Hour_Text[]={"zero hours","one hour","two hours","three hours","four hours","five hours","six hours","seven hours","eight hours","nine hours","ten hours","eleven hours","twelve hours",
                    "thirteen hours","fourteen hours","fifteen hours","sixteen hours","seventeen hours","eighteen hours","nineteen hours","twenty hours","twenty one hours","twenty two hours",
                    "twenty three hours","twenty four hours"};

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

//Code to initialise the CountDown
unsigned int Selection_Index=0; //Index to change the Hour/Minute/Second during CountDown Selection
unsigned int Hour_Entry=0,Minute_Entry=0; //Flags to check if the CountDown_Hour or Countdown_Minute has been entered by the user

while(Hour_Entry==0) //Loop to initialise the number of Hours for the CountDown
    {
    cout<<"\t CountDown\n\n\n\n\n";

    cout<<Hour_Text[Selection_Index];

    if(GetAsyncKeyState(VK_RIGHT)) {Selection_Index++; if(Selection_Index==25) {Selection_Index=0;}} //Displays the next string if the "Right Arrow Key" is pressed
    if(GetAsyncKeyState(VK_LEFT)) {Selection_Index--; if(Selection_Index==0) {Selection_Index=25;}} //Displays the previous string if the "Left Arrow Key" is pressed

    if(GetAsyncKeyState(VK_RETURN)) {CountDown_Hours=Selection_Index; Hour_Entry=1; Selection_Index=0; cout<<endl;} //Stores the displayed string in CountDown_Hours if "Return" is pressed

    else {Sleep(130);} //Freezes the console for 130 milliseconds
    system("cls"); //Clears the console screen

    if(GetAsyncKeyState(VK_UP)) {StopWatch();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
    if(GetAsyncKeyState(VK_DOWN)) {Main_Watch();} //Changes over to Main Watch Mode if "Down Arrow Key" is pressed
    }

Sleep(100); //Freezes the console for 100 milliseconds

while((Hour_Entry==1)&&(Minute_Entry==0)) //Loop to initialise the number of Minutes for the CountDown
    {
    cout<<"\t CountDown\n\n\n\n\n";
    cout<<Hour_Text[CountDown_Hours]<<endl;

    cout<<Minute_Text[Selection_Index];
    if(GetAsyncKeyState(VK_RIGHT)) {Selection_Index++; if(Selection_Index==60) {Selection_Index=0;}} //Displays the next string if the "Right Arrow Key" is pressed
    if(GetAsyncKeyState(VK_LEFT)) {Selection_Index--; if(Selection_Index==0) {Selection_Index=60;}} //Displays the previous string if the "Left Arrow Key" is pressed

    if(GetAsyncKeyState(VK_RETURN)) {CountDown_Minutes=Selection_Index; Minute_Entry=1; Selection_Index=0; cout<<endl;} //Stores the displayed string in CountDown_Minutes

    else {Sleep(130);} //Freezes the console for 130 milliseconds
    system("cls"); //Clears the console screen

    if(GetAsyncKeyState(VK_UP)) {StopWatch();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
    if(GetAsyncKeyState(VK_DOWN)) {Main_Watch();} //Changes over to Main Watch Mode if "Down Arrow Key" is pressed
    }

Sleep(100); //Freezes the console for 100 milliseconds

while((Minute_Entry==1)&&(Hour_Entry==1)) //Loop to initialise the number of Seconds for the CountDown
    {
    cout<<"\t CountDown\n\n\n\n\n";
    cout<<Hour_Text[CountDown_Hours]<<endl<<Minute_Text[CountDown_Minutes]<<endl;
    cout<<Second_Text[Selection_Index];

    if(GetAsyncKeyState(VK_RIGHT)) {if(Selection_Index==60) {Selection_Index=0;} Selection_Index++;} //Displays the next string if the "Right Arrow Key" is pressed
    if(GetAsyncKeyState(VK_LEFT)) {Selection_Index--; if(Selection_Index==0) {Selection_Index=60;}} //Displays the previous string if the "Left Arrow Key" is pressed

    if(GetAsyncKeyState(VK_RETURN)) {CountDown_Seconds=Selection_Index; cout<<endl;} //Stores the displayed string in CountDown_Minutes if "Return" is pressed

    if(CountDown_Seconds!=-1) {break;} //Stops taking input if CountDown_Seconds has an actual usable value

    else {Sleep(130);} //Freezes the console for 130 milliseconds
    system("cls"); //Clears the console screen

    if(GetAsyncKeyState(VK_UP)) {StopWatch();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
    if(GetAsyncKeyState(VK_DOWN)) {Main_Watch();} //Changes over to Main Watch Mode if "Down Arrow Key" is pressed
    }

//Loop to display the CountDown
for(;;)
    {
    system("cls"); //Clears the console
    cout<<"\t CountDown\n";

    cout<<"\n\n\n\n"<<CountDown_Hours[Hour_Text]<<"\n"<<CountDown_Minutes[Minute_Text]<<"\n"<<CountDown_Seconds[Second_Text]; //Displays the CountDown Output

    if(CountDown_Seconds==0) {CountDown_Minutes--; CountDown_Seconds=59;}
    if((CountDown_Minutes==0)&&(CountDown_Hours>0)) {CountDown_Hours--; CountDown_Minutes=59;}

    CountDown_Seconds--;

    Sleep(1000); //Freezes the console for a second

    system("cls"); //Clears the console
    cout<<"\t CountDown\n";

    if((CountDown_Hours==0)&&(CountDown_Minutes==0)&&(CountDown_Seconds==0)) {break;} //Stops the countdown when it has ended

    if(GetAsyncKeyState(VK_UP)) {StopWatch();} //Changes over to CountDown Mode if "Up Arrow Key" is pressed
    if(GetAsyncKeyState(VK_DOWN)) {Main_Watch();} //Changes over to Main Watch Mode if "Down Arrow Key" is pressed
    }
}
