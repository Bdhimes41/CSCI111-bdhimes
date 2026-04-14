#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iterator>
#include <algorithm>
#include "fileio.hpp"
using namespace std;

int read_data(int *numbers, const string input_file)
{
    // FIXME1 #fixed: Open input_file for reading data
    // read the data until eof marker and store each num into numbers array
    // return the number of integers read from the file or the first integer
    // in the file which represents the number of integers to read
    
    ifstream fin(input_file);

    if (!fin)
    {
        cout << "Error opening input file.\n";
        return 0;
    }

    int array_len;
    fin >> array_len;

    for (int i = 0; i < array_len; ++i)
    {
        fin >> numbers[i];
    }

    fin.close();
    return array_len;
}

void write_data(const int *numbers, size_t array_len)
{
    // FIXME2 #fixed
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
    string output_file;
    cout << "Enter output file name: ";
    cin >> output_file;

    ofstream fout(output_file);

    if (!fout)
    {
        cout << "Error opening output file.\n";
        return;
    }

    fout << fixed << setprecision(2);
    fout << "Count: " << array_len << endl;
    fout << "Minimum: " << find_min(numbers, array_len) << endl;
    fout << "Maximum: " << find_max(numbers, array_len) << endl;
    fout << "Mean: " << find_mean(numbers, array_len) << endl;
    fout << "Range: " << find_range(numbers, array_len) << endl;

    int *copy_nums = new int[array_len];
    for (size_t i = 0; i < array_len; ++i)
    {
        copy_nums[i] = numbers[i];
    }

    fout << "Median: " << find_median(copy_nums, array_len) << endl;

    delete[] copy_nums;
    fout.close();
}

int find_max(const int *nums, size_t array_len)
{
    // Implement function to find and return maximum value in nums array
    int max = nums[0];
    for (int i = 0; i < array_len; ++i)
        max = (nums[i] > max) ? nums[i] : max;
    return max;
}

int find_min(const int *nums, size_t array_len)
{
    // FIXME3 - implement function to find and return minimum value in nums array #fixed
    int min = nums[0];
    for (int i = 0; i < array_len; ++i)
        min = (nums[i] < min) ? nums[i] : min;
    return min;
}

float find_mean(const int *nums, size_t array_len)
{
    // same as average
    long long int sum = 0;
    for (int i = 0; i < array_len; ++i)
        sum += nums[i];
    return sum / float(array_len);
}

int find_range(const int *nums, size_t array_len)
{
    // FIXME6 - implement function that finds and returns the range of the numbers in nums array.
    // Range is defined as the difference between maximum and minimum values in the array. #fixed
    return find_max(nums, array_len) - find_min(nums, array_len);
}

float find_median(int *nums, size_t array_len)
{
    // Find the median of the numbers in nums array.
    // Median is defined as the middle value when the numbers are sorted in order.
    // If there is an even number of values, the median is the average of the two middle values.
    sort(nums, nums + array_len);
    float median;
    if (array_len % 2 == 0)
    { // even set of numbers
      // median = average of middle two numbers
        median = (nums[array_len / 2 - 1] + nums[array_len / 2]) / 2.0;
    }
    else
    { // odd set
        median = nums[array_len / 2];
    }
    return median;
}