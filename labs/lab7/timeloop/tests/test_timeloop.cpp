#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <sstream>
#include <streambuf>

#include "../../../doctest/doctest.h" // FIXME: adjust the path as needed
#include "../src/timeloop.h"

TEST_CASE("Testing read_number function")
{
    SUBCASE("Typical case")
    {
        std::istringstream input("5\n");
        std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
        std::cin.rdbuf(input.rdbuf());             // redirect std::cin to input

        pos_short result = read_number();
        CHECK(result == 5);

        std::cin.rdbuf(cinbuf); // restore old buf
    }
    SUBCASE("Edge case: minimum value")
    {
        std::istringstream input("1\n");
        std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
        std::cin.rdbuf(input.rdbuf());             // redirect std::cin to input

        pos_short result = read_number();
        CHECK(result == 1);

        std::cin.rdbuf(cinbuf); // restore old buf
    }
    SUBCASE("Edge case: maximum value")
    {
        std::istringstream input("65535\n");
        std::streambuf *cinbuf = std::cin.rdbuf(); // save old buf
        std::cin.rdbuf(input.rdbuf());             // redirect std::cin to input

        pos_short result = read_number();
        CHECK(result == 65535);

        std::cin.rdbuf(cinbuf); // restore old buf
    }
    // FIXME5: Add 2 more test cases to cover edge cases
}

TEST_CASE("Testing cast_spell function")
{
    SUBCASE("Typical case")
    {
        pos_short n = 3;
        std::string result = cast_spell(n);
        CHECK(result == "3 Abracadabra");
    }
    // FIXME6: Add 2 more test cases to cover edge cases
    SUBCASE("Edge case: n = 1")
    {
        pos_short n = 1;
        std::string result = cast_spell(n);
        CHECK(result == "1 Abracadabra");
    }
    SUBCASE("Edge case: n = 65535")
    {
        pos_short n = 65535;
        std::string result = cast_spell(n);
        CHECK(result == "65535 Abracadabra");
    }
}

TEST_CASE("Testing print_answer function")
{
    SUBCASE("Typical case upto 3 spells")
    {
        std::ostringstream output;
        std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
        std::cout.rdbuf(output.rdbuf());             // redirect std::cout to output

        pos_short *N = new pos_short(3);
        print_answer(N);

        std::string expected =
            "1 Abracadabra\n"
            "2 Abracadabra\n"
            "3 Abracadabra\n";
        string captured_output = output.str();

        std::cout.rdbuf(coutbuf); // restore old buf
        CHECK(captured_output == expected);
    }
    // FIXME7: Add 2 more test cases to cover edge cases
    SUBCASE("Edge case: N = 1")
    {
        std::ostringstream output;
        std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
        std::cout.rdbuf(output.rdbuf());             // redirect std::cout to output

        pos_short *N = new pos_short(1);
        print_answer(N);

        std::string expected = "1 Abracadabra\n";
        string captured_output = output.str();

        std::cout.rdbuf(coutbuf); // restore old buf
        CHECK(captured_output == expected);
    }
    SUBCASE("Edge case: N = 5")
    {
        std::ostringstream output;
        std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
        std::cout.rdbuf(output.rdbuf());             // redirect std::cout to output

        pos_short *N = new pos_short(5);
        print_answer(N);

        std::string expected =
            "1 Abracadabra\n"
            "2 Abracadabra\n"
            "3 Abracadabra\n"
            "4 Abracadabra\n"
            "5 Abracadabra\n";
        string captured_output = output.str();

        std::cout.rdbuf(coutbuf); // restore old buf
        CHECK(captured_output == expected);
    }
}