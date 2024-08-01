#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n {}, m {}; cin >> n >> m;

    vector<vector<int>> pastures (n);

    for (int i {0}; i < m; ++i) {int j {}, k {}; cin >> j >> k; pastures[j - 1].push_back(k - 1); pastures[k - 1].push_back(j - 1);}

    vector<int> grasses (n, 0);

    for (int i {0}; i < n; ++i) {
        vector<int> cows {pastures[i]};
        vector<int> seeds (4, true);

        for (int cow : cows) {if (grasses[cow] == 0) {continue;} else {seeds[grasses[cow] - 1] = false;}}
        for (int seed {0}; seed < 4; ++seed) {if (seeds[seed] == true) {grasses[i] = seed + 1; break;}}
    }

    for (int grass : grasses) {cout << grass;}
}