// The Watch Project v1.0
// Main Source Code

#include "helper.h"
#include "watch.h"

void display_info()
{
    while (!GetAsyncKeyState(VK_RETURN)) {
        std::cout << "" << std::endl;
        std::cout << "The Watch Project";
        std::cout << "" << std::endl;

        std::cout << "Main Screen Options:" << std::endl;
        std::cout << "UP      --> Countdown Timer" << std::endl;
        std::cout << "DOWN    --> Stopwatch" << std::endl;
        std::cout << "ESC     --> Exit" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Countdown Timer Options:" << std::endl;
        std::cout << "LEFT     --> Previous Value" << std::endl;
        std::cout << "RIGHT    --> Next Value" << std::endl;
        std::cout << "ENTER    --> Save Value" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Stopwatch Options:" << std::endl;
        std::cout << "UP       --> Main Screen" << std::endl;
        std::cout << "SPACEBAR --> Svae to file in Numerics" << std::endl;
        std::cout << "RIGHT CONTROL  --> Save to file in Words" << std::endl;
        std::cout << "" << std::endl;

        std::cout << "Press ENTER to continue" << std::endl;
        Sleep(1000);

        system("cls");
    }
}

int main()
{
    // Shows the help screen
    display_info();

    // Sets console size, console title and hides cursor
    Helper::Console_Formatting();

    // Starts the main watch
    Watch().Time_Output();

    return 0;
}
