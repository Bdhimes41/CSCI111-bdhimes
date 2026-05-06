#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>
#include "reservation.h"

using namespace std;

class Restaurant
{
private:
    vector<int> table_capacities;
    vector<Reservation> reservations;

public:
    Restaurant();

    bool add_reservation(string name, int party_size);
    bool cancel_reservation(string name);
    int search_reservation(string name) const;

    vector<Reservation> get_reservations() const;
    int find_available_table(int party_size) const;
    bool is_table_reserved(int table_number) const;

    void view_reservations() const;
    bool save_to_file(string filename) const;
    bool load_from_file(string filename);
};

#endif