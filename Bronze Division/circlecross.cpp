#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);


    vector<char> road {};
    for (int i {0}; i < 52; ++i) {char j {}; cin >> j; road.push_back(j);}

    int l {0};

    for (char i {65}; i < 91; ++i) {
        for (char j {static_cast<char>(i + 1)}; j < 91; ++j) {
            vector<int> a {};
            for (int k{0}; k < 52; ++k) { if (road[k] == i) { a.push_back(k); }}
            sort(a.begin(), a.end());

            vector<int> b {};
            for (int k{0}; k < 52; ++k) { if (road[k] == j) { b.push_back(k); }}
            sort(b.begin(), b.end());

            if ((a[0] < b[0] && a[1] < b[1] && b[0] < a[1]) || b[0] < a[0] && b[1] < a[1] && a[0] < b[1]) {++l;}
        }
    }

    cout << l;
}