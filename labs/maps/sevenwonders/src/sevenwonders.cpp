#include <iostream>
#include <unordered_map>
#include <string>
#include "sevenwonders.h"

using namespace std;

// solving the problem for kattis
void solve()
{
    string cards;
    pos_int points = 0;
    // string consists of only uppercase letters (no spaces) upto 50 chars
    // FIXME1
    // read played cards into cards variable
    cin >> cards;
    // FIXME2
    // count cards - call count_cards function passing cards and card_count
    auto card_count = count_cards(cards);
    // FIXME3
    // count points - call count_points function and update points
    points = count_points(card_count);
    // FIXME4
    // add bonus points - call count_bonus function and update points
    points += count_bonus(card_count);
    cout << points << endl;
}

unordered_map<char, pos_int> count_cards(const string &cards)
{

    unordered_map<char, pos_int> card_count;
    // step 2: update card_count map with count of each card played
    // for each card in cards
    for (char card : cards)
    {
        // check if a card is already in wonders map
        auto find = card_count.find(card);
        if (find == card_count.end()) // card not found
            // add it to the wonders map
            card_count[card] = 1;
        else
        {
            // FIXME5: update value/count of card
            card_count[card]++;
            cerr << "FIXME\n";
        }
    }
    return card_count;
}

pos_int count_points(const unordered_map<char, pos_int> &card_count)
{
    // algorithm step 3 - calculate regular points
    pos_int points = 0;
    for (auto pair : card_count)
    { // pair = <card, count>
        // FIXME6 - Update the points by adding count^2
        points += pair.second * pair.second;
        cerr << "FIXME\n";
    }
    return points;
}

pos_int count_bonus(const unordered_map<char, pos_int> &card_count)
{
    // algorithm step 4 - calculate bonus points
    // find # of sets of three different cards and mulitiply it by 7
    // and add it to the total bonus
    pos_int bonus = 0;
    pos_int min_card_count = 999999;
    pos_int unique_cards = card_count.size();
    if (unique_cards == 3)
    {
        for (auto pair : card_count)
        {
            min_card_count = pair.second < min_card_count ? pair.second : min_card_count;
        }
        // FIXME7: set bonus to min_card_count x 7
        bonus = min_card_count * 7;
    }
    return bonus;
}