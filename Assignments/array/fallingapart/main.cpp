/*
Falling Apart
Updated By: Ben Himes
CSCI 111
Date: 3/26/2026
Instructor: Professor James

Kattis Problem:
https://open.kattis.com/problems/fallingapart

Problem Summary:
Alice and Bob take turns choosing pieces from an array of integers.
They always choose the largest remaining piece first.
Alice goes first, then Bob, and so on.
The goal is to compute the total value collected by Alice and Bob.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;


pair<int, int> solve_falling_apart(vector<int> pieces)
{
    sort(pieces.begin(), pieces.end(), greater<int>());

    int alice = 0;
    int bob = 0;

    for (size_t i = 0; i < pieces.size(); i++)
    {
        if (i % 2 == 0)
        {
            alice += pieces[i];
        }
        else
        {
            bob += pieces[i];
        }
    }

    return {alice, bob};
}


void run_unit_tests()
{
    int passed = 0;
    int total = 4;

    {
        vector<int> pieces = {3, 1, 5, 2};
        pair<int, int> expected = {8, 3}; // sorted: 5,3,2,1
        pair<int, int> actual = solve_falling_apart(pieces);

        if (actual == expected)
        {
            cout << "Test 1 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 1 failed: expected "
                 << expected.first << " " << expected.second
                 << ", got "
                 << actual.first << " " << actual.second << '\n';
        }
    }

    {
        vector<int> pieces = {4, 4, 4, 4};
        pair<int, int> expected = {8, 8};
        pair<int, int> actual = solve_falling_apart(pieces);

        if (actual == expected)
        {
            cout << "Test 2 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 2 failed: expected "
                 << expected.first << " " << expected.second
                 << ", got "
                 << actual.first << " " << actual.second << '\n';
        }
    }

    {
        vector<int> pieces = {10};
        pair<int, int> expected = {10, 0};
        pair<int, int> actual = solve_falling_apart(pieces);

        if (actual == expected)
        {
            cout << "Test 3 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 3 failed: expected "
                 << expected.first << " " << expected.second
                 << ", got "
                 << actual.first << " " << actual.second << '\n';
        }
    }

    {
        vector<int> pieces = {8, 2, 9, 1, 7};
        pair<int, int> expected = {18, 9}; // sorted: 9,8,7,2,1
        pair<int, int> actual = solve_falling_apart(pieces);

        if (actual == expected)
        {
            cout << "Test 4 passed\n";
            passed++;
        }
        else
        {
            cout << "Test 4 failed: expected "
                 << expected.first << " " << expected.second
                 << ", got "
                 << actual.first << " " << actual.second << '\n';
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

    vector<int> pieces(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pieces[i];
    }

    pair<int, int> result = solve_falling_apart(pieces);
    cout << result.first << " " << result.second << '\n';

    return 0;
}