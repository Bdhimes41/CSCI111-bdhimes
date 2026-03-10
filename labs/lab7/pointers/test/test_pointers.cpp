#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/utils.h"

TEST_CASE("Testing find_sum function")
{
    SUBCASE("Two positive numbers")
    {
        CHECK(my_space::find_sum(new big_int(10), new big_int(4)) == 14);
    }
    SUBCASE("One negative and one positive number")
    {
        big_int *pos = new big_int(4);
        big_int *neg = new big_int(-5);
        CHECK(my_space::find_sum(neg, pos) == -1);
        delete pos;
        delete neg;
    }
    SUBCASE("Two negative numbers")
    {
        big_int *n1 = new big_int(-3);
        big_int *n2 = new big_int(-7);
        CHECK(my_space::find_sum(n1, n2) == -10);
        delete n1;
        delete n2;
    }
    SUBCASE("Adding zero")
    {
        big_int *n1 = new big_int(5);
        big_int *n2 = new big_int(0);
        CHECK(my_space::find_sum(n1, n2) == 5);
        delete n1;
        delete n2;
    }
    // FIXME8: Add 2 more test cases to cover edge cases
}
TEST_CASE("Testing find_product function")
{
    SUBCASE("Two positive numbers")
    {
        large_int a = 6;
        large_int b = 7;
        CHECK(my_space::find_product(a, b) == 42);
    }
    SUBCASE("One negative and one positive number")
    {
        large_int *n1 = new large_int(10);
        large_int *n2 = new large_int(-5);
        CHECK(my_space::find_product(*n1, *n2) == -50);
        delete n1;
        delete n2;
    }
    SUBCASE("Two negative numbers")
    {
        large_int *n1 = new large_int(-3);
        large_int *n2 = new large_int(-7);
        CHECK(my_space::find_product(*n1, *n2) == 21);
        delete n1;
        delete n2;
    }
    SUBCASE("Multiplying by zero")
    {
        large_int *n1 = new large_int(5);
        large_int *n2 = new large_int(0);
        CHECK(my_space::find_product(*n1, *n2) == 0);
        delete n1;
        delete n2;
    }
    // FIXME9: Add 2 more test cases to cover edge cases
}

// FIXME10: Write test cases (with at least 2 subcases) for find_difference function declared in utils.h
TEST_CASE("Testing find_difference function")
{
    SUBCASE("Two positive numbers")
    {
        large_int a = 10;
        large_int b = 4;
        CHECK(my_space::find_difference(a, b) == 6);
    }
    SUBCASE("One negative and one positive number")
    {
        large_int *n1 = new large_int(4);
        large_int *n2 = new large_int(-5);
        CHECK(my_space::find_difference(*n1, *n2) == 9);
        delete n1;
        delete n2;
    }
    SUBCASE("Two negative numbers")
    {
        large_int *n1 = new large_int(-3);
        large_int *n2 = new large_int(-7);
        CHECK(my_space::find_difference(*n1, *n2) == 4);
        delete n1;
        delete n2;
    }
    SUBCASE("Subtracting zero")
    {
        large_int *n1 = new large_int(5);
        large_int *n2 = new large_int(0);
        CHECK(my_space::find_difference(*n1, *n2) == 5);
        delete n1;
        delete n2;
    }
    
}
// FIXME11: Write test cases (with at least 2 subcases) for find_larger function declared in utils.h
TEST_CASE("Testing find_larger function")
{
    SUBCASE("Two positive numbers")
    {
        big_int *n1 = new big_int(10);
        big_int *n2 = new big_int(4);
        CHECK(my_space::find_larger(n1, n2) == 10);
        delete n1;
        delete n2;
    }
    SUBCASE("One negative and one positive number")
    {
        big_int *n1 = new big_int(4);
        big_int *n2 = new big_int(-5);
        CHECK(my_space::find_larger(n1, n2) == 4);
        delete n1;
        delete n2;
    }
    SUBCASE("Two negative numbers")
    {
        big_int *n1 = new big_int(-3);
        big_int *n2 = new big_int(-7);
        CHECK(my_space::find_larger(n1, n2) == -3);
        delete n1;
        delete n2;
    }
    SUBCASE("Comparing equal numbers")
    {
        big_int *n1 = new big_int(5);
        big_int *n2 = new big_int(5);
        CHECK(my_space::find_larger(n1, n2) == 5);
        delete n1;
        delete n2;
    }
}
