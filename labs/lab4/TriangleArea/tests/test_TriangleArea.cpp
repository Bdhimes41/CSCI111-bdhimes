#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "C:/users/benhi/CSCI111-bdhimes/labs/lab4/TriangleArea/triarea.h"


TEST_CASE("Testing area_of_triangle function")
{
    SUBCASE("Test Case 1")
    {
        unsigned height = 10;
        unsigned base = 5;
        float expected = 25.0;
        float result = area_of_triangle(height, base);
        CHECK(result == doctest::Approx(expected).epsilon(MAX_ERROR));
    }
    SUBCASE("Test Case 2")
    {
        unsigned height = 6;
        unsigned base = 4;
        float expected = 12.0;
        float result = area_of_triangle(height, base);
        CHECK(result == doctest::Approx(expected).epsilon(MAX_ERROR));
    }
}

TEST_CASE("Additional tests for area_of_triangle")
{
    SUBCASE("Zero height")
    {
        unsigned height = 0;
        unsigned base = 10;
        float expected = 0.0;
        float result = area_of_triangle(height, base);
        CHECK(result == doctest::Approx(expected).epsilon(MAX_ERROR));
    }

    SUBCASE("Zero base")
    {
        unsigned height = 8;
        unsigned base = 0;
        float expected = 0.0;
        float result = area_of_triangle(height, base);
        CHECK(result == doctest::Approx(expected).epsilon(MAX_ERROR));
    }
}


