#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r1, s;
    cin >> r1 >> s;

    int r2 = 2 * s - r1;
    cout << r2 << "\n";

    return 0;
}
