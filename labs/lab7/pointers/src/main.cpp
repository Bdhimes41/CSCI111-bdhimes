//  Pointers, enum type and namespace lab
//  Updated by: Ben Himes
//  Date: 3/9/2026
//  Program demonstrates the use of pointers, preprocessor directive,
//  namespace, and enum type.

#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include "utils.h"

using namespace std;
using namespace my_space;

int main(int argc, char *argv[])
{
    char input;
    big_int *num1;
    num1 = new big_int;
    big_int *num2 = new big_int;
    large_int *sum = new large_int;
    large_int *prod = new large_int;
    large_int *diff = new large_int;
    big_int *larger = new big_int;

    OPERATION oper;

    do
    {
        clear();
        show_menu();
        cin >> input;
        oper = get_operation(input);

        switch (oper)
        {
        case ADD:
            cout << "Enter two whole numbers separated by space: ";
            cin >> *num1 >> *num2;
            *sum = find_sum(num1, num2);
            printf("%lld + %lld = %lld\n", *num1, *num2, *sum);
            break;

        case MULTIPLY:
            cout << "Enter two whole numbers separated by space: ";
            cin >> *num1 >> *num2;
            *prod = find_product(*num1, *num2);
            printf("%lld * %lld = %lld\n", *num1, *num2, *prod);
            break;

        case SUBTRACT:
            cout << "Enter two whole numbers separated by space: ";
            cin >> *num1 >> *num2;
            *diff = find_difference(*num1, *num2);
            printf("%lld - %lld = %lld\n", *num1, *num2, *diff);
            break;

        case LARGER:
            cout << "Enter two whole numbers separated by space: ";
            cin >> *num1 >> *num2;
            *larger = find_larger(num1, num2);
            printf("Larger value: %lld\n", *larger);
            break;

        case QUIT:
            break;

        default:
            cout << "Invalid choice.\n";
            break;
        }

        if (oper != QUIT)
        {
            cin.ignore(1000, '\n');
            cout << "Press Enter to continue...";
            cin.get();
        }

    } while (oper != QUIT);

    delete num1;
    delete num2;
    delete sum;
    delete prod;
    delete diff;
    delete larger;

    cout << "Good bye! Enter to exit the program...";
    cin.get();
    return 0;
}