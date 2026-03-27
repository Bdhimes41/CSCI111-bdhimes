/*
Line Them Up
Updated By: Ben Himes
CSCI 111
Date: 3/26/2026
Instructor: Professor James

Kattis Problem:
https://open.kattis.com/problems/lineup

Problem Summary:
Given a list of names, determine whether the names are in strictly increasing
alphabetical order, strictly decreasing alphabetical order, or neither.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


string solve_lineup(const vector<string>& names)
{
    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < names.size(); i++)
    {
        if (!(names[i - 1] < names[i]))
        {
            increasing = false;
        }

        if (!(names[i - 1] > names[i]))
        {
            decreasing = false;
        }
    }

    if (increasing)
    {
        return "INCREASING";
    }
    if (decreasing)
    {
        return "DECREASING";
    }
    return "NEITHER";
}


void run_unit_tests()
{
    int passed = 0;
    int total = 4;

    {
        vector<string> names = {"Alice", "Bob", "Charlie"};
        string expected = "INCREASING";
        string actual = solve_lineup(names);
        if (actual == expected)
        {
            cout << "Test 1 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 1 failed: expected " << expected
                 << ", got " << actual << '\n';
        }
    }

    {
        vector<string> names = {"Charlie", "Bob", "Alice"};
        string expected = "DECREASING";
        string actual = solve_lineup(names);
        if (actual == expected)
        {
            cout << "Test 2 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 2 failed: expected " << expected
                 << ", got " << actual << '\n';
        }
    }

    {
        vector<string> names = {"Alice", "Charlie", "Bob"};
        string expected = "NEITHER";
        string actual = solve_lineup(names);
        if (actual == expected)
        {
            cout << "Test 3 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 3 failed: expected " << expected
                 << ", got " << actual << '\n';
        }
    }

    {
        vector<string> names = {"Zoe"};
        string expected = "INCREASING";
        string actual = solve_lineup(names);
        if (actual == expected)
        {
            cout << "Test 4 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 4 failed: expected " << expected
                 << ", got " << actual << '\n';
        }
    }

    cout << "\nPassed " << passed << " out of " << total << " tests.\n";

    if (passed != total)
    {
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc > 1 && string(argv[1]) == "test")
    {
        run_unit_tests();
        return 0;
    }

    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    cout << solve_lineup(names) << '\n';

    return 0;
}