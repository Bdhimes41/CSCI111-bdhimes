#include <iostream>
#include <string>
int main() {
std::string input;
std::cout << "What is your name? ";
std:: getline(std::cin, input);
std::cout << "What is your year? ";
std::string year;
std:: getline(std::cin, year);
std::cout << "    |\\_/|    *****************************      (\\_/)\n";
std::cout << "   / @ @ \\   *        ASCII Lab          *     (='.'=)\n";
std::cout << "  ( > 0 < )  *        " <<  input << "          *     (\")_(\")\n";
std::cout << "    >>x<<    *        " <<  year << "           *\n";
std::cout << "    / O \\    *****************************\n";
return 0;
}

//The program alignment only works correctly when the input for name and year are specific to me. I implemented the inputs to get more practice with strings.//
//The correct alignments come from "Ben Himes" as the first input and "Freshman" as the second input.//
