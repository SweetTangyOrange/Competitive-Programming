#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;



int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x {}, y {}; // farmer, cow
    cin >> x >> y;
    
    int d {0}, j {x}, i {0};
    bool k {x < y};

    while (j != y) {
        const int f {j};

        if (i % 2 == 0) { // positive
            j = {x + static_cast<int>(pow(2, i))};
            ++i;

            if (k && j > y) {
                j = {y};
                d += abs(j - f);
            } else {
                d += abs(j - f);
            }
        } else { // negative
            j = {x - static_cast<int>(pow(2, i))};
            ++i;

            if (!k && j < y) {
                j = {y};
                d += abs(j - f);
            } else {
                d += abs(j - f);
            }
        }
    }

    cout << d;

    return 0;
}
