#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

struct Reservation
{
    string customer_name;
    int party_size;
    int table_number;
};

#endif