#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../labs/doctest/doctest.h"
#include "../src/restaurant.h"


TEST_CASE("Testing add_reservation")
{
    Restaurant restaurant;

    CHECK(restaurant.add_reservation("Alice", 2) == true);
    CHECK(restaurant.get_reservations().size() == 1);
}

TEST_CASE("Testing search_reservation")
{
    Restaurant restaurant;

    restaurant.add_reservation("Bob", 4);

    CHECK(restaurant.search_reservation("Bob") != -1);
    CHECK(restaurant.search_reservation("Charlie") == -1);
}

TEST_CASE("Testing cancel_reservation")
{
    Restaurant restaurant;

    restaurant.add_reservation("David", 2);

    CHECK(restaurant.cancel_reservation("David") == true);
    CHECK(restaurant.search_reservation("David") == -1);
}

TEST_CASE("Testing find_available_table")
{
    Restaurant restaurant;

    CHECK(restaurant.find_available_table(2) != -1);
    CHECK(restaurant.find_available_table(100) == -1);
}

TEST_CASE("Testing is_table_reserved")
{
    Restaurant restaurant;

    restaurant.add_reservation("Emma", 2);

    CHECK(restaurant.is_table_reserved(1) == true);
    CHECK(restaurant.is_table_reserved(8) == false);
}