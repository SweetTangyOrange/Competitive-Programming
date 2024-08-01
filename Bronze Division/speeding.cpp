#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n {}, m {}; // segments, bessie
    cin >> n >> m;

    array<int, 100> limits {};

    int f {0};

    for (int i {0}; i < n; ++i) {
        int j {}, k {}; // segment, limit
        cin >> j >> k;

        for (int e {f}; e < f + j; ++e) {
            limits[e] = {k};
        }

        f += j;
    }

    f = {0};
    int g {0};

    for (int i {0}; i < m; ++i) {
        int j {}, k {}; // segment, limit
        cin >> j >> k;

        for (int e {f}; e < f + j; ++e) {
            g = max(k - limits[e], g);
        }

        f += j;
    }

    cout << g;
}