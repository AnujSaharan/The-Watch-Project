// The Watch Project v1.0
// Helper Module (helper.h)
// Functions common to all modes are stored in helper

#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

// Included Dependencies
#include <iostream>
#include <windows.h>

class Helper {

private:
    static void Show_Console_Cursor(HANDLE, bool);

public:
    static std::string Numbers_Text[];
    static void Suffix_s(int, unsigned int);
    static void Console_Formatting();
};

#endif // HELPER_H_INCLUDED
