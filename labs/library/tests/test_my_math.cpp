#include <iostream>
#include <cmath>
#include <cassert>
#include "../src/my_math.h"
using namespace std;

const float EPSILON = 1e-6; // accuracy upto 6 decimal points

void test_square_root()
{
    float num = 16.0;
    float expected = 4.0;
    float result = sqrt(num);
    assert(fabs(result - expected) <= EPSILON);
}

void test_log_base_2()
{
    float num = 1024;
    float expected = 10;
    float result = log2(num);
    assert(fabs(result - expected) <= EPSILON);
}

int main()
{
    cerr << "My Math Library Test Runner" << endl;
    test_square_root();
    test_log_base_2();

    cerr << "All test cases passed!" << endl;
    return 0;
}