#include <iostream>
#include <array>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n {};
    cin >> n;

    array<int, 7> milks {};
    map<string, int> cows {{"Bessie", 0}, {"Elsie", 1}, {"Daisy", 2}, {"Gertie", 3}, {"Annabelle", 4}, {"Maggie", 5}, {"Henrietta", 6}};

    for (int i {0}; i < n; ++i) {string cow {}; int milk {}; cin >> cow >> milk; milks[cows[cow]] += milk;}

    array<int, 7> bovines {milks};
    sort(bovines.begin(), bovines.end());

    pair<int, int> b {bovines[0], 0};
    for (int i {0}; i < 7; ++i) {if (bovines[i] == bovines[0]) {++b.second;} else {break;}}

    if (b.second == 7) {cout << "Tie"; return 0;}

    pair<int, int> d {bovines[b.second], 0};
    for (int i {b.second}; i < 7; ++i) {if (bovines[i] == bovines[b.second]) {++d.second;} else {break;}}

    if (d.second > 1) {cout << "Tie"; return 0;}

    for (int i {0}; i < 7; ++i) {if (d.first == milks[i]) {for (auto k : cows) {if (k.second == i) {cout << k.first; return 0;}}}}
}
