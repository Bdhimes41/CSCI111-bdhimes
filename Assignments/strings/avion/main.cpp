/*
Programmer: Ben Himes
Course: CSCI 111
Assignment: Kattis - Avion

Problem:
Read 5 blimp registration codes. Output the line numbers (1-based)
of all lines containing the substring "FBI". If none contain "FBI",
output "HE GOT AWAY!".

Algorithm Steps:
1. Read 5 strings from input.
2. For each string, call a function to check whether it contains "FBI".
3. Store the 1-based line numbers of matches.
4. If the program is run with argument "test", run unit tests instead.
5. Otherwise:
   a. If matches exist, print them separated by spaces.
   b. If no matches exist, print "HE GOT AWAY!".

Kattis link:
https://open.kattis.com/problems/avion
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Returns true if the code contains "FBI"
bool containsFBI(const string& code)
{
    return code.find("FBI") != string::npos;
}

// Unit tests for containsFBI
void testContainsFBI()
{
    assert(containsFBI("N-FBI1") == true);
    assert(containsFBI("9A-USKOK") == false);
    assert(containsFBI("47-FBI") == true);
    assert(containsFBI("13A-FBILL") == true);
    assert(containsFBI("F-BI-12") == false);

    cout << "All unit tests passed!" << endl;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc == 2 && string(argv[1]) == "test")
    {
        testContainsFBI();
        return 0;
    }

    vector<int> matches;
    string code;

    for (int i = 1; i <= 5; i++)
    {
        cin >> code;
        if (containsFBI(code))
        {
            matches.push_back(i);
        }
    }

    if (matches.empty())
    {
        cout << "HE GOT AWAY!" << endl;
    }
    else
    {
        for (size_t i = 0; i < matches.size(); i++)
        {
            cout << matches[i];
            if (i + 1 < matches.size())
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}