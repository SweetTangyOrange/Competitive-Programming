#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n; // sessions, cows
    cin >> k >> n;

    vector<vector<int>> rankings(k, vector<int>(n));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> rankings[i][j];
        }
    }

    int c = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool p = true; // greater
            bool q = true; // lesser

            for (int s = 0; s < k; ++s) {
                if (find(rankings[s].begin(), rankings[s].end(), i + 1) - rankings[s].begin() > find(rankings[s].begin(), rankings[s].end(), j + 1) - rankings[s].begin()) {
                    p = false;
                } else if (find(rankings[s].begin(), rankings[s].end(), i + 1) - rankings[s].begin() < find(rankings[s].begin(), rankings[s].end(), j + 1) - rankings[s].begin()) {
                    q = false;
                }
            }

            if (p || q) {
                ++c;
            }
        }
    }

    cout << c;

    return 0;
}
