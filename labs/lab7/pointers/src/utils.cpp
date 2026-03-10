#include <iostream>
#include "utils.h"
using namespace std;

// Menu options
void show_menu(void)
{
    cout << "Enter one of the following menu options:\n";
    cout << "[1] Add two integers\n";
    cout << "[2] Multiply two integers\n";
    cout << "[3] Subtract one integer from another\n";
    cout << "[4] Find the larger of two integers\n";
    cout << "[5] Quit the program\n";
    cout << "Enter your choice [1-5]: ";
}

// function returns OPERATION type given character choice
OPERATION get_operation(char choice)
{
    OPERATION op;
    switch (choice)
    {
    case '1':
        op = ADD;
        break;
    case '2':
        op = MULTIPLY;
        break;
    case '3':
        op = SUBTRACT;
        break;
    case '4':
        op = LARGER;
        break;
    default:
        op = QUIT;
    }
    return op;
}

// must use my_space namespace to resolve findSum function
big_int my_space::find_sum(const big_int *n1, const big_int *n2)
{
    // dereference pointers n1 and n2 before adding their values
    return (*n1) + (*n2);
}

// FIXME7: define find_larger function declared inside my_space namespace
// function returns the larger of the two given numbers
// use conditional (ternary) operator
big_int my_space::find_larger(const big_int *n1, const big_int *n2)
{
    return (*n1 > *n2) ? *n1 : *n2;
}
// find Product function definition
large_int my_space::find_product(const large_int &n1, const large_int &n2)
{
    return n1 * n2;
}

// FIXME8: define find_difference function declared inside my_space namespace
large_int my_space::find_difference(const large_int &n1, const large_int &n2)
{
    return n1 - n2;
}
// return the value of second big_int subtracted from the first