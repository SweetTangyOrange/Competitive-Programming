#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    array<int, 4> a {};
    array<int, 4> b {};

    for (int i {0}; i < 4; ++i) {
        int j {};
        cin >> j;

        a[i] = j;
    }

    for (int i {0}; i < 4; ++i) {
        int j {};
        cin >> j;

        b[i] = j;
    }

    const int k {max(max(a[3], b[3]) - min(a[1], b[1]), max(a[2], b[2]) - min(a[0], b[0]))};
    cout << k * k;
}