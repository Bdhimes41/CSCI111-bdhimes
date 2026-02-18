#pragma once
#include <cassert>
#include <cmath>

#ifndef MAX_ERROR
#define MAX_ERROR 1e-6
#endif

inline float area_of_triangle(unsigned h, unsigned b)
{
    return (static_cast<float>(h) * static_cast<float>(b)) / 2.0f;
}

inline void test_area_with_assert()
{
    assert(std::fabs(area_of_triangle(10, 5) - 25.0f) < MAX_ERROR);
    assert(std::fabs(area_of_triangle(6, 4) - 12.0f) < MAX_ERROR);
    assert(std::fabs(area_of_triangle(0, 10) - 0.0f) < MAX_ERROR);
}
