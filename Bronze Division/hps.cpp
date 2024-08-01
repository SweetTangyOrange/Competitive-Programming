#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n {};
    cin >> n;

    array<int, 6> a {0, 0, 0, 0, 0, 0};

    for (int i {0}; i < n; ++i) {
        int j {}, k {};
        cin >> j >> k;

        if ((j == 2 && k == 1) || (j == 3 && k == 2) ||(j == 1 && k == 3)) {
            a[0] += 1;
        }

        if ((j == 3 && k == 1) || (j == 2 && k == 3) ||(j == 1 && k == 2)) {
            a[1] += 1;
        }

        if ((j == 1 && k == 2) || (j == 3 && k == 1) ||(j == 2 && k == 3)) {
            a[2] += 1;
        }

        if ((j == 3 && k == 2) || (j == 1 && k == 3) ||(j == 2 && k == 1)) {
            a[3] += 1;
        }

        if ((j == 1 && k == 3) || (j == 2 && k == 1) ||(j == 3 && k == 2)) {
            a[4] += 1;
        }

        if ((j == 2 && k == 3) || (j == 1 && k == 2) ||(j == 3 && k == 1)) {
            a[5] += 1;
        }
    }

    sort(a.begin(), a.end());
    cout << a[5];
}