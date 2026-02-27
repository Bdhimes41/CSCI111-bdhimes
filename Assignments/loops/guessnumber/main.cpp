//Ben Himes//
//CSCI 111 - Spring 2026//
//This program is a number guessing game. //
//The user will be prompted to guess a number between 1 and 20, and the program will provide feedback on whether the guess is too low, too high, or correct.//
//The game continues until the user guesses the correct number.//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    srand(time(0));
    int randomnumber = rand() % 20 + 1;
    int userguess = 0;
    cout << "Welcome to the number guessing game! I have selected a number between 1 and 20. Can you guess it?" << endl;
    while (userguess != randomnumber) {
        cout << "Enter your guess: ";
        cin >> userguess;
        if (userguess < randomnumber) {
            cout << "Too low! Try again." << endl;
        } else if (userguess > randomnumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
        }
    }

}