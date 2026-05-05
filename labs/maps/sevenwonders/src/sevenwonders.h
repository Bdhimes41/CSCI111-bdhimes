#pragma once
#include <string>
#include <unordered_map>

using pos_int = unsigned int; // create type alias

// function prototypes
std::unordered_map<char, pos_int> count_cards(const std::string &);
pos_int count_points(const std::unordered_map<char, pos_int> &);
pos_int count_bonus(const std::unordered_map<char, pos_int> &);
void solve();