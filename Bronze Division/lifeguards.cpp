#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n {};
    cin >> n;

    vector<int> hours (1000, 0);
    vector<pair<int, int>> shifts {};

    int k {0};

    for (int i {0}; i < n; ++i) {int a {}, b {}; cin >> a >> b; shifts.push_back({a, b}); while (a < b) {if (hours[a] == 0) {++k;} ++hours[a]; ++a;}}

    int j {10000};

    for (int i {0}; i < n; ++i) {
        int m {0};

        for (int l {shifts[i].first}; l < shifts[i].second; ++l) {if (hours[l] == 1) {++m;}}

        if (m < j) {j = {m};}
    }

    cout << k - j;
}