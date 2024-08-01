#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n {}, m {}, d {}, s {};
    cin >> n >> m >> d >> s;

    vector<array<int, 3>> drinks (d);
    for (int i {0}; i < d; ++i) {cin >> drinks[i][0]; cin >> drinks[i][1]; cin >> drinks[i][2];}

    vector<pair<int, int>> sickness (s, {0, 0});
    for (int i {0}; i < s; ++i) {cin >> sickness[i].first; cin >> sickness[i].second;}

    vector<vector<int>> badmilks {};
    for (pair<int, int> sick : sickness) {badmilks.emplace_back(); for (array<int, 3> drink : drinks) {if (sick.first == drink[0] && drink[2] < sick.second) {badmilks[badmilks.size() - 1].push_back(drink[1]);}}}

    vector<int> badmilk {};
    for (int milk {1}; milk <= m; ++milk) {bool i {true}; for (vector<int> flavors : badmilks) {if (find(flavors.begin(), flavors.end(), milk) == flavors.end()) {i = {false}; break;}} if (i) {badmilk.push_back(milk);}}

    int doses {0};

    for (int milk : badmilk) {int dose {0}; for (int person {1}; person <= n; ++person) {for (array<int, 3> drink : drinks) {if (drink[0] == person && drink[1] == milk) {++dose; break;}}} doses = {max(doses, dose)};}

    cout << doses;
}