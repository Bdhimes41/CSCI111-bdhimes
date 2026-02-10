/*Circle Lab 
By: Ben Himes
CSCI111
Date: 2/9/2026
 This program prompts the user to enter the radius of a circle.
 It then calculates and displays its area and circumference.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const double PI = 3.14159; // Define a constant for pi
    double radius=0, area=0, circumference=0; // Declare variables for radius, area, and circumference
    string name="anonymous";
    cout << "What is your name? ";
    getline(cin, name); // Get the user's name
    cout << "Hello, " << name << "! Welcome to the Circle Lab." << endl; // Greet the user
    cout <<"\nThis program calculates the area and circumference of a circle based on the radius you provide." << endl; // Explain the program
    cout << string(75, '=') << endl; // Print a separator line
    cout << name << ", please enter the radius of the circle: "; // Prompt the user for the radius
    cin >> radius;
    area = PI * pow(radius, 2); // Calculate the area of the circle
    circumference = 2 * PI * radius; // Calculate the circumference of the circle
    cout << "your circle has radius: " << fixed << setprecision(6) << radius << endl; // Display the radius with 6 decimal places
    cout << "the area of your circle is: " << fixed << setprecision(6) << area << endl; // Display the area with 6 decimal places
    cout << "the circumference of your circle is: " << fixed << setprecision(6) << circumference << endl; // Display the circumference with 6 decimal places
    cout << "Good bye...\nHit enter to exit the program!" << '\n';
	cin.ignore(1000, '\n'); 
	cin.get();
	return 0;
}
