/*
Programmer: Ben Himes
Course: CSCI 111
Assignment: Kattis - Apaxiaaaaaaaaaaaans!

Problem:
Read a string and compress it by removing consecutive duplicate letters.

Algorithm Steps:
1. Read the input string.
2. Pass the string to a function that removes consecutive duplicate characters.
3. Return the compressed result.
4. If the program is run with argument "test", run unit tests instead of normal program logic.
5. Otherwise, print the final compressed string.

Kattis link:
https://open.kattis.com/problems/apaxiaaans
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Returns a new string with consecutive duplicate letters removed
string compressName(const string& name)
{
    if (name.empty())
    {
        return "";
    }

    string result;
    result += name[0];

    for (size_t i = 1; i < name.size(); i++)
    {
        if (name[i] != name[i - 1])
        {
            result += name[i];
        }
    }

    return result;
}

// Unit tests for compressName
void testCompressName()
{
    assert(compressName("robert") == "robert");
    assert(compressName("aabbbcccaaa") == "abca");
    assert(compressName("apaxiaaans") == "apaxians");
    assert(compressName("xxxxx") == "x");
    assert(compressName("") == "");

    cout << "All unit tests passed!" << endl;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc == 2 && string(argv[1]) == "test")
    {
        testCompressName();
        return 0;
    }

    string name;
    cin >> name;

    cout << compressName(name) << endl;

    return 0;
}