#include <string>
#include <iostream>
#include "timeloop.h"

using namespace std;

pos_short read_number()
{
    // FIXME3: Declare a dynamic variable to read and store N and return it
    pos_short *N = new pos_short;
    cin >> *N;
    return *N;
}

string cast_spell(pos_short n)
{
    // FIXME4: return the single spell string as per the format "n Abracadabra"
    return to_string(n) + " Abracadabra";
}

void print_answer(const pos_short *N)
{
    for (pos_short i = 1; i <= *N; i++)
    {
        cout << cast_spell(i) << endl;
    }
}