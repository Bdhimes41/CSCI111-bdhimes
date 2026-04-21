#include <iostream>
#include <cstdio>
#include "utils.h"
using namespace std;

// read data from a file and store it in into given nums array.
void read_data(int nums[], int size)
{
    cout << "You've asked to enter " << size << " integers.\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer: ";
        // FIXME3: read each integer from user and store it into nums array
        cin >> nums[i];
    }
}

void print_array(int nums[], int len)
{
    cout << "[ ";
    for (int i = 0; i < len; i++)
        cout << nums[i] << " ";
    cout << "]" << endl;
}

void find_max_min(int nums[], int len, int &max, int &min)
{
    max = nums[0]; // say, max is the first element
    min = nums[0]; // say, min is the first element
    for (int i = 0; i < len; i++)
    {
        if (max < nums[i]) // compare max with each element and update max if necessary
            max = nums[i];

        // FIXEME4: compare min with each element and update min
        if (min > nums[i])
            min = nums[i];
    }
}

// Implements bubble sort
void bubble_sort(int nums[], int len)
{
    int i, j, temp;
    bool sorted = false;
    for (i = 0; i < len; i++)
    {
        sorted = true;
        for (j = 0; j < len - i - 1; j++)
        {
            // if two adjacent numbers are not in order, swap 'em
            if (nums[j] > nums[j + 1])
            {
                // FIXME5: swap the values of nums[j] and nums[j+1]
                //  can use built-in swap or implement your own swap
                temp = nums[j];
                nums[j] = nums[j + 1];
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

big_int find_sum(int nums[], int len)
{
    big_int sum = 0;
    // FIXME6: iterate through nums array and add each element to sum
    for (int i = 0; i < len; i++)
        sum += nums[i];
    return sum;
}