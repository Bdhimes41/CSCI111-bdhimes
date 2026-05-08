#include <iostream>
#include <limits>
#include "restaurant.h"

using namespace std;

/*
Programmer: Ben Himes
Program: Restaurant Reservation System
Description:
This program allows a restaurant to manage reservations.
Users can add, view, search, cancel, save, and load reservations. -Asked ChatGPT to write this description for me.
*/

void print_menu();
int get_choice();
void handle_add_reservation(Restaurant &restaurant);
void handle_search_reservation(const Restaurant &restaurant);
void handle_cancel_reservation(Restaurant &restaurant);

int main()
{
    Restaurant restaurant;
    string filename = "data/reservations.txt";

    restaurant.load_from_file(filename);

    int choice;

    do
    {
        print_menu();
        choice = get_choice();

        if (choice == 1)
        {
            handle_add_reservation(restaurant);
        }
        else if (choice == 2)
        {
            restaurant.view_reservations();
        }
        else if (choice == 3)
        {
            handle_search_reservation(restaurant);
        }
        else if (choice == 4)
        {
            handle_cancel_reservation(restaurant);
        }
        else if (choice == 5)
        {
            if (restaurant.save_to_file(filename))
            {
                cout << "Reservations saved successfully." << endl;
            }
            else
            {
                cout << "Error saving reservations." << endl;
            }
        }
        else if (choice == 6)
        {
            if (restaurant.load_from_file(filename))
            {
                cout << "Reservations loaded successfully." << endl;
            }
            else
            {
                cout << "Error loading reservations." << endl;
            }
        }
        else if (choice == 7)
        {
            restaurant.save_to_file(filename);
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

void print_menu()
{
    cout << "\nRestaurant Reservation System\n";
    cout << "1. Add a reservation\n";
    cout << "2. View all reservations\n";
    cout << "3. Search for a reservation\n";
    cout << "4. Cancel a reservation\n";
    cout << "5. Save reservations to file\n";
    cout << "6. Load reservations from file\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int get_choice()
{
    int choice;
    cin >> choice;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number: ";
        cin >> choice;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void handle_add_reservation(Restaurant &restaurant)
{
    string name;
    int party_size;

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter party size: ";
    cin >> party_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (restaurant.add_reservation(name, party_size))
    {
        cout << "Reservation added successfully." << endl;
    }
    else
    {
        cout << "No available table for that party size." << endl;
    }
}

void handle_search_reservation(const Restaurant &restaurant)
{
    string name;

    cout << "Enter customer name to search: ";
    getline(cin, name);

    int index = restaurant.search_reservation(name);

    if (index == -1)
    {
        cout << "Reservation not found." << endl;
    }
    else
    {
        vector<Reservation> reservations = restaurant.get_reservations();

        cout << "Reservation found!" << endl;
        cout << "Customer Name: " << reservations[index].customer_name << endl;
        cout << "Party Size: " << reservations[index].party_size << endl;
        cout << "Table Number: " << reservations[index].table_number << endl;
    }
}

void handle_cancel_reservation(Restaurant &restaurant)
{
    string name;

    cout << "Enter customer name to cancel: ";
    getline(cin, name);

    if (restaurant.cancel_reservation(name))
    {
        cout << "Reservation canceled successfully." << endl;
    }
    else
    {
        cout << "Reservation not found." << endl;
    }
}