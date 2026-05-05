/*
Map Lab
Kattis - Seven Wonders

Updated By: Ben Himes
Date: 5/4/2026

The solution to the Seven Wonders Problem: https://open.kattis.com/problems/sevenwonders
Algorithm steps:
1. Read cards into a string variable
2. use unordered_map<char, int> to keep track of count of each card played
  - update map: for each card, update its count
3. find regular points following the instruction
  - points = sum of (each card_count)^2
4. add bonus points if any
  - find # of sets of three cards and multiply it by 7
*/

#include <iostream>
#include "sevenwonders.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // FIXME0: Call the correct function to solve the problem
        solve();

    return 0;
}