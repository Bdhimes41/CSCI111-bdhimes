/*
    CS1 - File IO Lab

    Updated by: Ben himes
    Date: 4/13/26

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application.
    Statistical value's definitions for mean, median, mode, etc. can be found here:
    https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <string>
#include <vector>
#include "fileio.hpp"
const int MAX_NUMBERS = 100; // assuming we will read at most 100 numbers from the file

using namespace std;

int main(int argc, char *argv[])
{
    int *numbers = new int[MAX_NUMBERS]; // assuming we will read at most 100 numbers from the file
    string input_file;
    cout << "Enter input file name: ";
    getline(cin, input_file);
    size_t array_len = read_data(numbers, input_file);
    write_data(numbers, array_len);
    cout << "All done. Enter to exit...";
    // FIXME - free memory allocated for numbers array
    delete[] numbers;
    cin.get();
    return 0;
}