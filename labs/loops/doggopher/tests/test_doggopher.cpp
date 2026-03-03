#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../doggopher.h"

TEST_CASE("Testing distance function")
{
    SUBCASE("Sub Case 1")
    {
        CHECK(distance(0, 0, 0, 0) == 0);
    }
    SUBCASE("Sub Case 2")
    {
        CHECK(distance(0, 0, 3, 4) == 5);
    }
    // FIXME35: Write 2 more test sub cases for distance function with at least 2 subcases
    SUBCASE("Sub Case 3")
    {
        CHECK(distance(1, 1, 4, 5) == 5);
    }
    SUBCASE("Sub Case 4")
    {
        CHECK(distance(2, 2, 2, 2) == 0);
    }
}