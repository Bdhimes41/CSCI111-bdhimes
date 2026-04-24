/*
Program: A New Alphabet
Programmer: Ben Himes
Date: 4/23/2026
*/

#include <iostream>
#include <map>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

map<char, string> create_alphabet_map()
{
    map<char, string> alphabet;

    alphabet['a'] = "@";
    alphabet['b'] = "8";
    alphabet['c'] = "(";
    alphabet['d'] = "|)";
    alphabet['e'] = "3";
    alphabet['f'] = "#";
    alphabet['g'] = "6";
    alphabet['h'] = "[-]";
    alphabet['i'] = "|";
    alphabet['j'] = "_|";
    alphabet['k'] = "|<";
    alphabet['l'] = "1";
    alphabet['m'] = "[]\\/[]";
    alphabet['n'] = "[]\\[]";
    alphabet['o'] = "0";
    alphabet['p'] = "|D";
    alphabet['q'] = "(,)";
    alphabet['r'] = "|Z";
    alphabet['s'] = "$";
    alphabet['t'] = "']['";
    alphabet['u'] = "|_|";
    alphabet['v'] = "\\/";
    alphabet['w'] = "\\/\\/";
    alphabet['x'] = "}{";
    alphabet['y'] = "`/";
    alphabet['z'] = "2";

    return alphabet;
}

string translate_to_new_alphabet(const string& text)
{
    map<char, string> alphabet = create_alphabet_map();
    string result = "";

    for (char ch : text)
    {
        char lower_ch = tolower(ch);

        if (alphabet.count(lower_ch) > 0)
        {
            result += alphabet[lower_ch];
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

void run_unit_tests()
{
    assert(translate_to_new_alphabet("a") == "@");
    assert(translate_to_new_alphabet("Hello") == "[-]3110");
    assert(translate_to_new_alphabet("cat") == "(@']['");
    assert(translate_to_new_alphabet("CSCI 111") == "($(| 111");
    assert(translate_to_new_alphabet("Wow!") == "\\/\\/0\\/!");
    assert(translate_to_new_alphabet("xyz") == "}{`/2");

    cout << "All unit tests passed!" << endl;
}

int main(int argc, char* argv[])
{
    if (argc > 1 && string(argv[1]) == "test")
    {
        run_unit_tests();
        return 0;
    }

    string line;
    getline(cin, line);

    cout << translate_to_new_alphabet(line) << endl;

    return 0;
}