// Implements functions to print geometric shapes using loops
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "shapes.h"

using namespace std;

std::stringstream get_triangle(int height)
{
    /* Function takes height as an argument to print the triangle
     of that height with *, e.g., height = 4

    *
    * *
    * * *
    * * * *

    */

    int row = 1;
    std::stringstream ss;
    while (row <= height)
    {
        // column
        for (int col = 1; col <= row; col++)
            ss << "* ";
        row += 1;
        ss << endl;
    }
    return ss;
}

void print_shape(const string shape)
{
    std::cout << shape << std::endl;
}

std::stringstream get_flipped_triangle(int height)
{
    /*
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *

    */
    // FIXME1 ...
    int row = height;
    std::stringstream ss;
    while (row >= 1)
    {
        for (int col = 1; col <= row; col++)
            ss << "* ";
        row -= 1;
        ss << endl;
    }
    return ss;
}

/*
FIXME2
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *
*  *  *  *  *
*  *  *  *  *
*  *  *  *  *
*  *  *  *  *

*/
std::stringstream get_square(int height)
{
    std::stringstream ss;
    for (int row = 1; row <= height; row++)
    {
        for (int col = 1; col <= height; col++)
            ss << "* ";
        ss << endl;
    }
    return ss;
}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clear_screen()
{
// use "cls" in windows and "clear" command in Mac and Linux
#ifdef _WIN32
    system("clS");
#else
    system("clear");
#endif
}