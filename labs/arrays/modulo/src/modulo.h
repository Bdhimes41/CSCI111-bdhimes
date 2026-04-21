#pragma once

#include <cstddef>
// Function prototypes for modulo lab
using namespace std;

void read_data(unsigned int *, size_t);
unsigned int get_modulo_42(const unsigned int);
void update_flags(const unsigned int *, bool *, size_t);
size_t count_flags(const bool[], size_t);
void init_flags(bool *, size_t);