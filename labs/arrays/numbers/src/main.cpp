/*
Ben Himes 4/20/2026
The lab demostrates the use of array and some operations on array.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "utils.h"

using namespace std;

int main(int argc, char *argv[])
{
	size_t size;
	int *nums = nullptr; // pointer to hold the dynamic array
	do
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			cout << "How many numbers would you like to enter? ";
			cin >> size;
			nums = new int[size];  // declare a dynamic int array of size
			read_data(nums, size); // read the data into nums array
			printf("Done reading %zu data numbers.\n", size);
			break;
		case 2:
			int max, min;
			find_max_min(nums, size, max, min);
			printf("Max = %u\n", max);
			// FIXME1: print Min value
			printf("Min = %u\n", min);
			break;
		case 3:
			printf("Sum = %lld\n", find_sum(nums, size));
			break;
		case 4:
			// FIXME2: call bubble_sort to sort the array
            bubble_sort(nums, size);
			cout << "Array sorted successfully.\n";
			break;
		case 5:
			print_array(nums, size); // print the array to check if the values are there
			break;
		case 6:
			delete[] nums; // free the allocated memory
			cout << "Data deleted successfully.\n";
			break;
		case 7:
			cout << "Exiting program...\n";
			return 0;
		}
	} while (true);
	return 0;
}

int menu()
{
	cout << "===== Menu =====\n";
	cout << "1. Read data\n";
	cout << "2. Print max & min\n";
	cout << "3. Print sum\n";
	cout << "4. Sort data\n";
	cout << "5. Print all data\n";
	cout << "6. Delete data\n";
	cout << "7. Exit\n";
	int choice;
	cout << "Enter your choice: ";
	while (true)
	{
		cin >> choice;
		if (choice >= 1 && choice <= 7)
			break;
		cout << "Invalid choice. Enter again: ";
	}
	cin.clear();
	cin.ignore(1000, '\n');
	return choice;
}