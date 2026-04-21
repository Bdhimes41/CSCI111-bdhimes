#pragma once

using big_int = long long int;

// function that reads numbers
void read_data(int *, int);
// function that finds max & min numbers from given array of numbers
void find_max_min(int *, int, int &, int &);
// function that finds the sum of the numbers in a given array
big_int find_sum(int *, int);
// function that sorts the numbes into ascending order
void bubble_sort(int *, int);
// function that prints each element in the array
void print_array(int *, int);
// menu function to display menu and get user choice
int menu();