/*
Pointers Lab

Updated By: Ben Himes
CSCI 111
Date: 3/9/26
Instructor: Professor James

Read and solve the Kattis problem Stuck in a Timeloop: https://open.kattis.com/problems/timeloop

Algorithm Steps:
  1. Using a function, read and return N
  2. Declare a dynamic variable to store, N returned by function in 1.
  3. Define a function to get the necessary spell given N
  4. Define a function to print answer
	- the function will use a loop to call cast_spell function to print spell N times:
	  1 Abracadabra
	  2 Abracadabra
	  ...
	  N Abracadabra
*/

#include <iostream>
#include <string>
#include "timeloop.h"

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Your solution here
	// declare a dynamic variable to store N
	pos_short *N = new pos_short;

	// FIXME1: Call read_number function and assign the returned value to N;
    *N = read_number();
	// FIXME2: Call print_answer function passing proper argument
	print_answer(N);
    delete N;

	return 0;
}