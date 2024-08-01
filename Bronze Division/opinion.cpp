#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t {};
    cin >> t;

    for (int i {0}; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> hays (n, 0); // input
        set<int> favorites {}; // output

        if (n == 2) {
            cin >> hays[0] >> hays[1]; if (hays[0] == hays[1]) {favorites.insert(hays[0]);}
        } else {
            for (int j {0}; j < n; ++j) {cin >> hays[j];}
            for (int j {2}; j < n; ++j) {
                if (hays[j - 2] == hays[j]) {favorites.insert(hays[j]);}
                if (hays[j - 1] == hays[j]) {favorites.insert(hays[j]);}
            }

            if (hays[0] == hays[1]) {favorites.insert(hays[1]);}
        }

        if (favorites.empty()) {
            cout << -1 << "\n";
        } else {
            int k{*(--favorites.end())};
            favorites.erase((--favorites.end()));

            for (auto favorite: favorites) {cout << favorite << " ";}
            cout << k << "\n";
        }
    }
}