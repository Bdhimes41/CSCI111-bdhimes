#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cassert>
#include "utils.h"

using namespace std;

// function clears the screen using system call
// NOTE: system call is not a security best pracice!
void clear_screen()
{
// use "cls" in windows and "clear" command in Mac and Linux
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_menu(void)
{
    cout << "========= Menu options =================\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Subtract two numbers\n";
    cout << "[3] Multiply two numbers\n";
    cout << "[4] Divide two numbers\n";
    cout << "[5] Find larger of two numbers\n";
    cout << "[6] Find smaller of two numbers\n";
    cout << "[7] Find average of two numbers\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

void get_two_numbers(double &n1, double &n2)
{
    cout << "Enter two numbers separated by a space: ";
    cin >> n1 >> n2;
}

double find_sum(const double &n1, const double &n2)
{
    return (n1 + n2);
}

double find_difference(const double &n1, const double &n2)
{
    // FIXME1 - subtract n2 from n1 and return the difference
    return (n1 - n2);
}

double find_product(const double &n1, const double &n2)
{
    // FIXME2 - multiply n1 by n2 and return the product
    return (n1 * n2);
}

void find_average(const double &n1, const double &n2, double &avg)
{
    // FIXME3 - find the average of n1 and n2 and update avg
    // FIXME4 - Must call find_sum function to find the sum of n1 and n2
    //  Note: this void function doesn't return a value but
    //  the average will be stored in avg
    double sum = find_sum(n1, n2);
    avg = sum / 2;
}

double find_larger(const double &n1, const double &n2)
{
    // find the larger of n1 and n2 and return it
    double larger = (n1 >= n2) ? n1 : n2;
    return larger;
}

double find_smaller(const double &n1, const double &n2)
{
    // FIXME5 - find the smaller of n1 and n2 and return it
    double smaller = (n1 <= n2) ? n1 : n2;
    return smaller;
}

double find_quotient(const double &n1, const double &n2)
{
    // FIXME6 - divide n1 by n2 and return the quotient
    return (n2 != 0) ? n1 / n2 : 0;
}

// functions to run automated testing for various user-defined functions
void test()
{
    double answer = find_sum(10, 12.5);
    double expected = 22.5;
    assert(answer == expected);        // test case 1
    assert(find_sum(-5, 10.5) == 5.5); // test case 2

    // FIXME7 – Using assert function write at least 2 test cases for each of the following functions
    // find_difference(), find_product(), find_larger(),
    // find_smaller(), find_quotient(), find_average()
    assert(find_difference(10, 5) == 5);
    assert(find_difference(5, 10) == -5);
    assert(find_product(3, 4) == 12);
    assert(find_product(-3, 4) == -12);
    assert(find_larger(10, 5) == 10);
    assert(find_larger(5, 10) == 10);
    assert(find_smaller(10, 5) == 5);
    assert(find_smaller(5, 10) == 5);
    assert(find_quotient(10, 2) == 5);
    assert(find_quotient(10, 3) == (double)(10/3));
    double avg;
    find_average(4.5, 7.5, avg);
    assert(avg == (4.5 + 7.5)/2.0);

    cerr << "all test cases passed..." << endl;
}

// the crux of the program that uses all the defined functions
// the program is menu driven
bool program()
{
    int option = 1;            // variable to store user entered option
    double num1 = 0, num2 = 0; // variables to store two numbers entered by user
    // display menu options
    print_menu();
    // Input validation
    do
    {
        if (cin >> option && option >= 1 && option <= 8)
        {
            // input is valid, break loop
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 8" << endl;
        }
    } while (true);

    // Call the function(s) or perform some operations based on user input
    switch (option)
    {
    case 1:
    {
        // get two numbers and store them into num1 and num2 using function
        get_two_numbers(num1, num2);
        // call find_sum function; store the returned value in sum variable
        double sum = find_sum(num1, num2);
        // display the result with proper description
        printf("%.2f + %.2f = %.2f\n", num1, num2, sum);
        break;
    }
    case 2:
    {
        // FIXME8: call get_two_numbers function
        get_two_numbers(num1, num2);
        // FIXME9: call find_difference function and print the result
        double diff = find_difference(num1, num2);
        printf("%.2f - %.2f = %.2f\n", num1, num2, diff);
        break;
    }
    case 3:
    {
        // FIXME10: get two numbers and find their product using functions
        get_two_numbers(num1, num2);
        double product = find_product(num1, num2);
        printf("%.2f * %.2f = %.2f\n", num1, num2, product);
        break;
    }
    // FIXME11: complete the rest of the cases 4, 6, and 7
    case 4:
    {
        get_two_numbers(num1, num2);
        double quotient = find_quotient(num1, num2);
        if (num2 != 0)
            printf("%.2f / %.2f = %.2f\n", num1, num2, quotient);
        else
            printf("Error: Division by zero is not allowed.\n");
        break;
    }
    case 5:
    {
        // get two numbers
        get_two_numbers(num1, num2);
        // find the larger of the two numbers
        double max = find_larger(num1, num2);
        // print the result
        printf("larger between %.2f & %.2f is %.2f\n", num1, num2, max);
        break;
    }
    case 6:
    {
        get_two_numbers(num1, num2);
        double min = find_smaller(num1, num2);
        printf("smaller between %.2f & %.2f is %.2f\n", num1, num2, min);
        break;
    }
    case 7:
    {
        get_two_numbers(num1, num2);
        double avg;
        find_average(num1, num2, avg);
        printf("average of %.2f & %.2f is %.2f\n", num1, num2, avg);
        break;
    }
    
    case 8:
    default:          // must be option 8
        return false; // exit the program
    }
    return true;
}