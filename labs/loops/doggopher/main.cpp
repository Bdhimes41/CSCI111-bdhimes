/*
Kattis - Dog & Gopher
Loop Lab
Updated By: Ben Himes
CSCI 111
Date: 3/2/26

Read and solve the Kattis problem: https://open.kattis.com/problems/doggopher

Algorithm Steps:
        1. Read gopher and dog's coordinates
        2. Define a function to find and return the Euclidean distance between the two points
    3. For each gopher hole coordinate:
      3.a find the distance between the gopher position and the hole
      3.b find the distance between the dog position and the hole
      4.c if the dog's distance is larger or equal to twice the distance of gopher,
          gopher can get away through that hole.
          4.c.1 Stop testing other holes.
    4. If no safe hole is found, the gopher cannot escape.
*/

#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "doggopher.h"

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float gopherX, gopherY;
    float x, y; // varibles to read gopher hole coordinates
    string answer = "The gopher cannot escape.";
    float gopher_dist, dog_dist = 0;
    // read gopher's coordinates
    cin >> gopherX >> gopherY;
    // FIXME1: read dog's coordinates
    float dogX, dogY;
    cin >> dogX >> dogY;
    while (cin >> x >> y)
    { // while there's hole coordinates to read
        // find gopher's distance from (x, y)
        gopher_dist = distance(gopherX, gopherY, x, y);
        // store the returned result into answer variable
        // FIXME2: find dog's distance from (x, y)
        dog_dist = distance(dogX, dogY, x, y);
        if (dog_dist >= 2 * gopher_dist)
        {
            ostringstream oss;
            oss << fixed << showpoint << setprecision(3);
            oss << "The gopher can escape through the hole at (" << x << "," << y << ").";
            answer = oss.str();
            break; // no need to test more holes; the first one will do!
        }
    }
    cout << answer << endl;

    return 0;
}