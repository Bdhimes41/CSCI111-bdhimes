/*
Library Functions Lab
Updated By: Ben Himes
CSCI 111
Date: 2/11/2026

Program prompts user to enter a decimal number. It then finds various trig and mathematical values
of the number using library functions and prints the results using cstdio's printf function.

Algorithm:
    1. Prompt user to enter a decmial number
    2. Store the number into a variable
    3. Find and print various results form the number
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath> // various math functions: https://cplusplus.com/reference/cmath
#include "my_math.h"

using namespace std;

int main()
{
    double number, result;

    cout << "Program calculates various results from a given number" << endl;
    cout << "Enter a decimal number: ";
    cin >> number;
    // Find ceiling of the number
    result = ceil(number);
    printf("ceiling(%f) = %.1f\n", number, result);
    // Find floor of the number
    result = floor(number);
    printf("Floor(%f) = %.1f\n", number, result);
    
    result = sqrt(number);
    printf("Square root of %f = %.4f\n", number, result);
  
    result = log2(number);
    printf("Log base 2 of %f = %.3f\n", number, result);
    
    result = degree_to_radian(number);
    printf("%f degree = %.5f radian\n", number, result);

    result = sine_of_radian(result);
    printf("Sine of %f radian = %.5f\n", result, result);

    result = cosine_of_radian(result);
    printf("Cosine of %f radian = %.5f\n", result, result);
   
    result = power_of_ten(number);
    printf("Power of ten of %f = %.0f\n", number, result);
    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;
}