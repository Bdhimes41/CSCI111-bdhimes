// Ben Himes
// CSCI 111 - Spring 2026
// FizzBuzz - Kattis Problem
//
// Description:
// This program solves the Kattis FizzBuzz problem.
// It reads three integers x, y, and n.
// For each number from 1 to n:
//  - Print "FizzBuzz" if divisible by both x and y
//  - Print "Fizz" if divisible by x
//  - Print "Buzz" if divisible by y
//  - Otherwise print the number.
//
// Algorithm:
// 1. Read integers x, y, n from input.
// 2. For i from 1 to n:
//      a. Determine output using fizzbuzzValue(i, x, y).
//      b. Print result.
// 3. If program is run with argument "test",
//      call unit test function instead of normal execution.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Function prototype
string fizzbuzzValue(int number, int x, int y);
void runUnitTests();

// Function that solves the logic (UNIT TESTABLE)
string fizzbuzzValue(int number, int x, int y) {
    if (number % x == 0 && number % y == 0)
        return "FizzBuzz";
    if (number % x == 0)
        return "Fizz";
    if (number % y == 0)
        return "Buzz";
    return to_string(number);
}

// Unit tests (Step 5)
void runUnitTests() {
    assert(fizzbuzzValue(3, 3, 5) == "Fizz");
    assert(fizzbuzzValue(5, 3, 5) == "Buzz");
    assert(fizzbuzzValue(15, 3, 5) == "FizzBuzz");
    assert(fizzbuzzValue(7, 3, 5) == "7");

    cout << "All unit tests passed.\n";
}

int main(int argc, char* argv[]) {

    // Step 7: Run tests if "test" argument provided
    if (argc == 2 && string(argv[1]) == "test") {
        runUnitTests();
        return 0;
    }

    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; i++) {
        cout << fizzbuzzValue(i, x, y) << endl;
    }

    return 0;
}