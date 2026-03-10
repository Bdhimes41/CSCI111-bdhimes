#pragma once
#include <string>
using namespace std;

// declare alias pos_short of type "unsigned int"
using pos_short = unsigned short;

// Function taken an integer n and returns
// spell: n Abracadabra
string cast_spell(const pos_short);

// function to print the final answer
void print_answer(const pos_short *);

// function to read N
pos_short read_number();