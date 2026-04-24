/*
Program: Babelfish
Programmer: Ben Himes
Date: 4/23/26
*/

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

string translate_word(const map<string, string>& dictionary, const string& word)
{
    if (dictionary.count(word) > 0)
    {
        return dictionary.at(word);
    }

    return "eh";
}

void add_dictionary_entry(map<string, string>& dictionary, const string& line)
{
    string english;
    string foreign;

    stringstream ss(line);
    ss >> english >> foreign;

    dictionary[foreign] = english;
}

void run_unit_tests()
{
    map<string, string> dictionary;

    dictionary["ogday"] = "dog";
    dictionary["atcay"] = "cat";
    dictionary["igpay"] = "pig";
    dictionary["ousemay"] = "mouse";

    assert(translate_word(dictionary, "ogday") == "dog");
    assert(translate_word(dictionary, "atcay") == "cat");
    assert(translate_word(dictionary, "igpay") == "pig");
    assert(translate_word(dictionary, "ousemay") == "mouse");
    assert(translate_word(dictionary, "irdbay") == "eh");

    map<string, string> dictionary2;
    add_dictionary_entry(dictionary2, "hello hola");
    add_dictionary_entry(dictionary2, "goodbye adios");

    assert(translate_word(dictionary2, "hola") == "hello");
    assert(translate_word(dictionary2, "adios") == "goodbye");
    assert(translate_word(dictionary2, "bonjour") == "eh");

    cout << "All unit tests passed!" << endl;
}

int main(int argc, char* argv[])
{
    if (argc > 1 && string(argv[1]) == "test")
    {
        run_unit_tests();
        return 0;
    }

    map<string, string> dictionary;
    string line;

    while (getline(cin, line))
    {
        if (line == "")
        {
            break;
        }

        add_dictionary_entry(dictionary, line);
    }

    string word;

    while (cin >> word)
    {
        cout << translate_word(dictionary, word) << endl;
    }

    return 0;
}