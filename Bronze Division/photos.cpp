#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n {};
    cin >> n;

    int odd {0}, even {0};

    for (int i {0}; i < n; ++i) {int j {}; cin >> j; if (j % 2 == 0) {++even;} else {++odd;}}

    vector<pair<int, int>> groups {};

    int i {1};

    while (true) {
        if (i == 1) {if (even >= 1) {even -= 1; groups.emplace_back(0, 1);} else if (odd >= 2) {odd -= 2; groups.emplace_back(2, 0);} else {break;}} else {if (odd >= 1) {odd -= 1; groups.emplace_back(1, 0);} else {break;}}
        if (i == 1) {i = {0};} else {i = {1};}
    }

    if (odd % 2 == 1) {cout << groups.size() - 1;} else {cout << groups.size();}
}