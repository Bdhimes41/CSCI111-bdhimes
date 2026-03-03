#include <cmath>
// Function implementation
float distance(const float x1, const float y1, const float x2, const float y2)
{
    float dist = 0;
    // FIXME4: Find the Eucledian distance between two points on 2-d coordiantes.
    // store the distance into the `dist` variable and return it at the end of the function.
     dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}