#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
     //freopen("herding.in", "r", stdin);
     //freopen("herding.out", "w", stdout);

    array<int, 3> cows {};
    for (int i {0}; i < 3; ++i) {cin >> cows[i];}
    sort(cows.begin(), cows.end());

    array<int, 2> spaces {};
    spaces[0] = {cows[1] - cows[0] - 1}; spaces[1] = {cows[2] - cows[1] - 1};
    sort(spaces.begin(), spaces.end());

    if (spaces[0] == 0 && spaces[1] == 0) {
        cout << 0 << "\n" << 0; return 0;
    } else if (spaces[0] == 1 || spaces[1] == 1) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

    if (spaces[0] == 1 && spaces[1] == 1) {cout << 1;} else {cout << spaces[1];}
}