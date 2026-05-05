/*
Map Lab
Kattis - Morse Code Palindromes

Updated By: Ben Himes
Date: 5/4/2026

Solution to Morse Code Palindromes Problem: https://open.kattis.com/problems/morsecodepalindromes
Algorithm steps:
1. Creae a map of char to morse code
2. Read in a string
3. Convert the string to morse code
   i. for each char in string, find its morse code in map
   ii. append morse code to a string if char key is found
4. Check if morse code is a palindrome
  i. compare first and last char
  ii. if they are the same, compare second and second last char
  iii. if they are the same, compare third and third last char
  iv. repeat until all chars are compared until mid index or a mismatch is found
5. Print 1 if morse code is a palindrome, 0 otherwise
*/

#include <iostream>
#include "morsecode.h"

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}