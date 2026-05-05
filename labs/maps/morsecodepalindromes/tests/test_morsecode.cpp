#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../doctest/doctest.h"
#include "../src/morsecode.h"

TEST_CASE("Testing convert_to_morse function")
{
    SUBCASE("Simple phrase")
    {
        string phrase = "SOS";
        string expected_morse = "...---...";
        CHECK(convert_to_morse(phrase) == expected_morse);
    }

    SUBCASE("Phrase with spaces and punctuation")
    {
        string phrase = "HELLO, WORLD!";
        string expected_morse = "......-...-..---.-----.-..-..-..";
        CHECK(convert_to_morse(phrase) == expected_morse);
    }

    // FIXME1: Add 2 more sub cases to test convert_to_morse function
    SUBCASE("Number phrase")
    {
        string phrase = "2024";
        string expected_morse = "..--- ----- ..--- ....-";
        CHECK(convert_to_morse(phrase) == expected_morse);
    }
    SUBCASE("Empty string")
    {
        string phrase = "";
        string expected_morse = "";
        CHECK(convert_to_morse(phrase) == expected_morse);
    }
}

TEST_CASE("Testing is_palindrome function")
{
    SUBCASE("Palindrome morse code")
    {
        string morse = "...---...";
        CHECK(is_palindrome(morse) == true);
    }

    SUBCASE("Non-palindrome morse code")
    {
        string morse = "...-.-";
        CHECK(is_palindrome(morse) == false);
    }

    // FIXME2: Add 2 more sub cases to test is_palindrome function
    SUBCASE("Empty string")
    {
        string morse = "";
        CHECK(is_palindrome(morse) == false);
    }
    SUBCASE("Single character")
    {
        string morse = ".";
        CHECK(is_palindrome(morse) == true);
    }
}