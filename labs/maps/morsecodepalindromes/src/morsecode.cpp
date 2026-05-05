#include <iostream>
#include <string>
#include <cctype>
#include "morsecode.h"

using namespace std;

// solving the problem for kattis
void solve()
{
    string phrase, morse;

    // read the whole English phrase, including spaces
    getline(cin, phrase);

    // convert phrase to morse code
    morse = convert_to_morse(phrase);

    // check if morse code is a palindrome
    bool is_pal = is_palindrome(morse);

    // print 1 if it is a palindrome, 0 otherwise
    cout << (is_pal ? 1 : 0) << endl;
}

// function definitions
string convert_to_morse(const string &phrase)
{
    string morse = "";

    // for each char in phrase, convert char to uppercase,
    // find its morse code in morse_code map,
    // and append it to morse string if found
    for (char c : phrase)
    {
        c = char(toupper(c));

        auto it = morse_code.find(c);
        if (it != morse_code.end())
        {
            morse += it->second;
        }
    }

    return morse;
}

bool is_palindrome(const string &morse)
{
    // empty morse code is not a palindrome
    if (morse.empty())
    {
        return false;
    }

    int left = 0;
    int right = morse.length() - 1;

    while (left < right)
    {
        if (morse[left] != morse[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}