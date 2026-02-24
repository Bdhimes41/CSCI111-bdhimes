#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "C:/Users/benhi/CSCI111-bdhimes/labs/doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/twostones.h"

TEST_CASE("Testing odd_or_even function")
{
    SUBCASE("Sub Case 1: Odd number")
    {
        unsigned int number = 7;
        string expected = "odd";
        string result = odd_or_even(number);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 2: Even number")
    {
        unsigned int number = 10;
        string expected = "even";
        string result = odd_or_even(number);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 3: Zero")
    {
        unsigned int number = 0;
        string expected = "even";
        string result = odd_or_even(number);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 4: Large odd number")
    {
        unsigned int number = 99999;
        string expected = "odd";
        string result = odd_or_even(number);
        CHECK(result == expected);
    }
    // FIXME8: Write 3rd and 4th test cases for odd_or_even function
}

TEST_CASE("Testing answer function")
{
    SUBCASE("Sub Case 1: Odd number of stones")
    {
        unsigned int stones = 5;
        string expected = "Alice";
        string result = answer(stones);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 2: Even number of stones")
    {
        unsigned int stones = 8;
        string expected = "Bob";
        string result = answer(stones);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 3: Zero stones")
    {
        unsigned int stones = 0;
        string expected = "Bob";
        string result = answer(stones);
        CHECK(result == expected);
    }
    SUBCASE("Sub Case 4: Large odd number of stones")
    {
        unsigned int stones = 99999;
        string expected = "Alice";
        string result = answer(stones);
        CHECK(result == expected);
    }
    // FIXME9: Write 3rd and 4th test cases for answer function
}