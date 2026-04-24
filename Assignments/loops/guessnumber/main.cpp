// Ben Himes
// CSCI 111 - Spring 2026
// Guess the Number Game
//
// Description:
// This program asks the user for their name, then plays a guessing game.
// The computer selects a random number between 1 and 20.
// The player has 6 tries to guess the number.
// The program tells the player if the guess is too low or too high.
// At the end, the program reveals the secret number.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

// Function prototypes
int randomNumber();
int readNumber();
int checkGuess(int guess, int secret);
void testCheckGuess();
void game();

// Step 6
int randomNumber() {
    return rand() % 20 + 1;
}

// Step 7
int readNumber() {
    int guess;

    while (true) {
        cout << "Enter your guess (1-20): ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (guess < 1 || guess > 20) {
            cout << "Number must be between 1 and 20.\n";
            continue;
        }

        return guess;
    }
}

// Step 8
// returns 0 if equal
// returns -1 if guess < secret
// returns 2 if guess > secret
int checkGuess(int guess, int secret) {
    if (guess == secret) return 0;
    if (guess < secret) return -1;
    return 2;
}

// Step 9
void testCheckGuess() {
    assert(checkGuess(10, 10) == 0);
    assert(checkGuess(5, 10) == -1);
    assert(checkGuess(15, 10) == 2);
}

// Step 10
void game() {
    int secret = randomNumber();
    const int MAX_TRIES = 6;

    for (int i = 1; i <= MAX_TRIES; i++) {
        cout << "\nAttempt " << i << " of " << MAX_TRIES << endl;

        int guess = readNumber();
        int result = checkGuess(guess, secret);

        if (result == 0) {
            cout << "Congratulations! You guessed the correct number!" << endl;
            cout << "The secret number was: " << secret << endl;
            return;
        }
        else if (result == -1) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Too high! Try again." << endl;
        }
    }

    cout << "\nSorry, you ran out of tries." << endl;
    cout << "The secret number was: " << secret << endl;
}

int main() {
    srand(time(0));

    // Step 9 tests
    testCheckGuess();

    // Step 5: Ask for name
    string name;
    cout << "What is your name? ";
    getline(cin, name);

    cout << "Hello " << name << "! Let's play Guess the Number.\n";

    game();

    return 0;
}