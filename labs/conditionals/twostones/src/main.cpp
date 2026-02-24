#include <iostream>
#include <string>
#include "twostones.h"

using namespace std;

/*
Kattis - Take Two Stones
Conditional Logic Lab
Updated By: Ben Himes
CSCI 111
Date: 2/23/26

Read and solve the Kattis problem: https://open.kattis.com/problems/twostones

Algorithm Steps:
  1. Read the number of stones
  2. Check if the number of stones is odd or even
  3.a. If the number is odd, Alice wins.
  3.b. Otherwise, Bob wins.
*/

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your solution here
    if (argc == 2 and string(argv[1]) == string("test"))
    {
        // FIXME1: call testOddOrEven function that unit tests oddOrEven function
        test_odd_or_even();
        // FIXME2: call the test function that unit tests answer function
        test_answer();

        exit(EXIT_SUCCESS); // exit the program
    }
    else
    {
        unsigned int stones = 0;
        // FIXME3: readin the stones
        cin >> stones;
        cout << answer(stones) << endl;
    }

    return 0;
}