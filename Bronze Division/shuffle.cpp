#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n {};
    cin >> n;

    vector<int> shuffle {};
    for (int i {0}; i < n; ++i) {int j {}; cin >> j; shuffle.push_back(j);}

    vector<int> ids {};
    for (int i {0}; i < n; ++i) {int j {}; cin >> j; ids.push_back(j);}

    for (int i {0}; i < 3; ++i) {
        vector<int> k (n, 0);

        for (int j {0}; j < n; ++j) {k[j] = ids[shuffle[j] -1];}
        for (int j {0}; j < n; ++j) {ids[j] = k[j];}
    }

    for (int i : ids) {cout << i << "\n";}
}