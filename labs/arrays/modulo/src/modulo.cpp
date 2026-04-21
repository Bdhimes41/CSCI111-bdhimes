#include <iostream>
#include "modulo.h"
using namespace std;

using ui = unsigned int;

// Function to get num modulo 42
unsigned int get_modulo_42(ui num)
{
    // FIXME4: return num modulo 42
    return num % 42;
    return 0;
}

// Function to read data into the array
void read_data(ui *data, size_t arr_len)
{
    for (int i = 0; i < arr_len; i++)
        cin >> data[i];
}

// Function to update flags array based on numbers modulo 42
void update_flags(const ui *numbers, bool *flags, size_t num_len)
{
    ui mod;
    for (int i = 0; i < num_len; i++)
    {
        mod = get_modulo_42(numbers[i]);
        cerr << "mod = " << mod << endl;
        flags[mod] = true;
    }
}

// Function to initialize flags array to false
void init_flags(bool *flags, size_t flags_len)
{
    for (int i = 0; i < flags_len; i++)
        flags[i] = false;
}

// Function to count the number of true flags
size_t count_flags(const bool flags[], size_t flags_len)
{
    size_t count = 0;
    for (int i = 0; i < flags_len; i++)
    {
        // FIXME5: if the flags at index i is set to true, increment count by 1
        if (flags[i] == true)
        {
            count++;
        }
    }
    return count;
}