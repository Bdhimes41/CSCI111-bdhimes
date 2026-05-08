#include <iostream>
#include <fstream>
#include "restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
    // Each number represents the seating capacity of one table.
    table_capacities = {2, 2, 4, 4, 6, 6, 8, 8};
}

bool Restaurant::add_reservation(string name, int party_size)
{
    int table_number = find_available_table(party_size);

    if (table_number == -1)
    {
        return false;
    }

    Reservation new_reservation;
    new_reservation.customer_name = name;
    new_reservation.party_size = party_size;
    new_reservation.table_number = table_number;

    reservations.push_back(new_reservation);
    return true;
}

bool Restaurant::cancel_reservation(string name)
{
    for (size_t i = 0; i < reservations.size(); i++)
    {
        if (reservations[i].customer_name == name)
        {
            reservations.erase(reservations.begin() + i);
            return true;
        }
    }

    return false;
}

int Restaurant::search_reservation(string name) const
{
    for (size_t i = 0; i < reservations.size(); i++)
    {
        if (reservations[i].customer_name == name)
        {
            return i;
        }
    }

    return -1;
}

vector<Reservation> Restaurant::get_reservations() const
{
    return reservations;
}

int Restaurant::find_available_table(int party_size) const
{
    for (size_t i = 0; i < table_capacities.size(); i++)
    {
        int table_number = static_cast<int>(i) + 1;

        if (table_capacities[i] >= party_size && !is_table_reserved(table_number))
        {
            return table_number;
        }
    }

    return -1;
}

bool Restaurant::is_table_reserved(int table_number) const
{
    for (const Reservation &reservation : reservations)
    {
        if (reservation.table_number == table_number)
        {
            return true;
        }
    }

    return false;
}

void Restaurant::view_reservations() const
{
    if (reservations.empty())
    {
        cout << "No reservations found." << endl;
        return;
    }

    cout << "\nCurrent Reservations\n";
    cout << "--------------------\n";

    for (const Reservation &reservation : reservations)
    {
        cout << "Customer Name: " << reservation.customer_name << endl;
        cout << "Party Size: " << reservation.party_size << endl;
        cout << "Table Number: " << reservation.table_number << endl;
        cout << "--------------------\n";
    }
}

bool Restaurant::save_to_file(string filename) const
{
    ofstream fout(filename);

    if (!fout)
    {
        return false;
    }

    for (const Reservation &reservation : reservations)
    {
        fout << reservation.customer_name << endl;
        fout << reservation.party_size << endl;
        fout << reservation.table_number << endl;
    }

    fout.close();
    return true;
}

bool Restaurant::load_from_file(string filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        return false;
    }

    reservations.clear();

    Reservation reservation;

    while (getline(fin, reservation.customer_name))
    {
        fin >> reservation.party_size;
        fin >> reservation.table_number;
        fin.ignore();

        reservations.push_back(reservation);
    }

    fin.close();
    return true;
}