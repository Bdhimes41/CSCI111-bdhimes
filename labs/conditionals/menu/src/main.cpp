/*
Conditional Lab

Programmer: Ben Himes
Date: 2/23/26

Program finds statistical values of two given numbers using user-defined functions.

A menu-driven program that demonstrates user-defined functions, automated testing conditional statements and loop.
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 2 && string(argv[1]) == string("test"))
    {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
    else
    {
        // this loop will keep the program running until user wants to quit
        while (true)
        {
            if (!program()) // call program
                break;      // break loop if program returned false
            cin.ignore(100, '\n');
            cout << "Enter to continue...";
            cin.get();
            clear_screen();
        }
    }
    cin.ignore(100, '\n');
    cout << "Good bye..." << endl;
    cout << "Enter to quit the program.\n";
    cin.get();
    return 0;
}