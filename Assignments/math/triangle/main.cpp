//Ben Himes. Freshman Year. CSCI 111. This program calculates the area of a triangle given the lengths of its three sides using Heron's formula.//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, s, area;
    cout << "Enter the lengths of the three sides of the triangle: "; //Step 1: Gather the lengths of the three sides of the triangle from the user//
    cin >> a >> b >> c;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;;
    //Step 2: Validate the input to ensure that the lengths can form a triangle. The sum of any two sides must be greater than the third side.//
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        cout << "Invalid triangle sides. The sum of any two sides must be greater than the third side." << endl;
        return 1; // Exit with an error code
    }
    double perimeter = a + b + c; //Step 3: Calculate the perimeter of the triangle by summing the lengths of its sides (a + b + c).//
    s = perimeter / 2; //Step 4: Calculate the semi-perimeter (s) of the triangle using the formula s = (a + b + c) / 2.//
    area = sqrt(s * (s - a) * (s - b) * (s - c)); //Step 5: Calculate the area of the triangle using Heron's formula: Area = sqrt(s * (s - a) * (s - b) * (s - c)).//
    cout << fixed << setprecision(2) << "The area of the triangle is: " << area << endl;
    cout << "The perimeter of the triangle is: " << perimeter << endl; //Step 6: Output the calculated area and perimeter of the triangle to the user.//
    return 0;

}
