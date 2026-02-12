#include <cmath>
#include "my_math.h"
using namespace std;

float square_root(float x)
{
    return sqrt(x);
}

float cube_root(float x)
{
    return cbrt(x);
}

float power_of_ten(float x)
{
    return pow(10, x);
}

float log_base_2(float x)
{
    return log2(x);
}

float log_base_10(float x)
{
    return log10(x);
}

float degree_to_radian(float degree)
{
    #define M_PI 3.14159265358979323846
    return degree * (M_PI / 180.0);
}

float sine_of_radian(float radian)
{
    return sin(radian);
}

float cosine_of_radian(float radian)
{
    return cos(radian);
}