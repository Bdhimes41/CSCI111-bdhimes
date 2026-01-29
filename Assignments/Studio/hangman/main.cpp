//Ben Himes, First Year, CSCI 111//
//This program is the beginning of a hangman game, set to print the first seven stages of the game using ASCII art.//

#include <iostream>
#include <string>
using namespace std;

int main() {
std::string name;
std::cout << "Welcome to Hangman! What is your name? ";
std::getline(std::cin, name);
std::cout << "Hello, " << name << "! Let's begin!" << std::endl;

string stage0 =
"  +---+\n"
"  |   |\n"
"      |\n"
"      |\n"
"      |\n"
"      |\n"
"=========\n";
string stage1 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
"      |\n"
"      |\n"
"      |\n"
"=========\n";
string stage2 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
"  |   |\n"
"      |\n"
"      |\n"
"=========\n";
string stage3 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|   |\n"
"      |\n"
"      |\n"
"=========\n";
string stage4 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\\  |\n"
"      |\n"
"      |\n"
"=========\n";
string stage5 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\\  |\n"
" /    |\n"
"      |\n"
"=========\n";
string stage6 =
"  +---+\n"
"  |   |\n"
"  O   |\n"
" /|\\  |\n"
" / \\  |\n"
"      |\n"
"=========\n";
std::cout << stage0 << std::endl;
std::cout << stage1 << std::endl;
std::cout << stage2 << std::endl;
std::cout << stage3 << std::endl;
std::cout << stage4 << std::endl;
std::cout << stage5 << std::endl;
std::cout << stage6 << std::endl;
return 0;
}