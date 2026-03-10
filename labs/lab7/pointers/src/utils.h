#pragma once

// macro function
#ifdef _WIN32
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

// user-defined enumerated type: OPERATION
enum OPERATION
{
    ADD,
    MULTIPLY,
    SUBTRACT,
    LARGER,
    QUIT
};

// C++ way of defining type alias
using big_int = long long int;

// C way of defining type alias
typedef long long int large_int;
// both large_int and big_int are alias to "long long int" type

// declare my_space namespace
namespace my_space
{
    // function prototypes defined within the namespace
    big_int find_sum(const big_int *, const big_int *);
    big_int find_larger(const big_int *, const big_int *);
    large_int find_product(const large_int &, const large_int &);
    large_int find_difference(const large_int &, const large_int &);
}

void show_menu(void);
OPERATION get_operation(char);