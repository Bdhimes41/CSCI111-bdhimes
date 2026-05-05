#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/sevenwonders.h"
#include <string>
#include <unordered_map>

using namespace std;

TEST_CASE("Testing count_cards function")
{
    SUBCASE("Basic test")
    {
        string cards = "TTC";
        unordered_map<char, pos_int> card_count;
        card_count = count_cards(cards);

        unordered_map<char, pos_int> expected = {
            {'T', 2},
            {'C', 1}};

        CHECK(card_count == expected);
    }

    SUBCASE("All same cards")
    {
        string cards = "CCCCC";
        unordered_map<char, pos_int> card_count;
        card_count = count_cards(cards);

        unordered_map<char, pos_int> expected = {
            {'C', 5}};

        CHECK(card_count == expected);
    }
    // FIXME8: Add 2 more test cases to test count_cards function
    SUBCASE("Two different cards")
    {
        string cards = "GG";
        unordered_map<char, pos_int> card_count;
        card_count = count_cards(cards);

        unordered_map<char, pos_int> expected = {
            {'G', 2}};

        CHECK(card_count == expected);
    }
    SUBCASE("Empty string")
    {
        string cards = "";
        unordered_map<char, pos_int> card_count;
        card_count = count_cards(cards);

        unordered_map<char, pos_int> expected = {};

        CHECK(card_count == expected);
    }
}

TEST_CASE("Testing count_points function")
{
    SUBCASE("Basic test no bonus")
    {
        unordered_map<char, pos_int> card_count = {
            {'C', 2}, {'T', 1}};
        pos_int points = count_points(card_count);
        pos_int expected = 5; // 2^2 + 1^2 = 4 + 1 = 5
        CHECK(points == expected);
    }

    SUBCASE("Single card of each type + bonus")
    {
        unordered_map<char, pos_int> card_count = {
            {'C', 1}, {'T', 1}, {'G', 1}};
        pos_int points = count_points(card_count);
        points += count_bonus(card_count);
        pos_int expected = 10; // 1^2 + 1^2 + 1^2 + 7 = 1 + 1 + 1 + 7 = 10
        CHECK(points == expected);
    }
    // FIXME9: Add 2 more test cases to test count_points function
    SUBCASE("Multiple cards of each type + bonus")
    {
        unordered_map<char, pos_int> card_count = {
            {'C', 3}, {'T', 2}, {'G', 1}};
        pos_int points = count_points(card_count);
        points += count_bonus(card_count);
        pos_int expected = 23; // 3^2 + 2^2 + 1^2 + 7 = 9 + 4 + 1 + 7 = 21
        CHECK(points == expected);
    }
    SUBCASE("No cards")
    {
        unordered_map<char, pos_int> card_count = {};
        pos_int points = count_points(card_count);
        points += count_bonus(card_count);
        pos_int expected = 0; // 0 points + 0 bonus = 0
        CHECK(points == expected);
    }
}