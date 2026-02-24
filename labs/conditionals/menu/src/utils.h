#pragma once

#define MAX_ERROR 0.01f

// function prototypes

// function clears the screen using system call
void clear_screen();

// function prints menu options
void print_menu(void);

// function prompts user to enter two numbers
// the numbers are stored in the parameters provided
void get_two_numbers(double &, double &);

// function takes two numbers; finds and returns the sum of the two
double find_sum(const double &, const double &);

// function takes two numbers; finds and returns the 2nd subtracted from the first
double find_difference(const double &, const double &);

// function takes two numbers; finds and returns the product of them
double find_product(const double &, const double &);

// function takes two numbers; finds; returns the quotient of first divided by the second
double find_quotient(const double &, const double &);

// function takes two numbers; finds and returns the average of the two
void find_average(const double &, const double &, double &);

// function takes two numbers; finds and returns the larger of the two
double find_larger(const double &, const double &);

// function takes two numbers; finds and returns the smaller of the two
double find_smaller(const double &, const double &);

void test();

bool program();