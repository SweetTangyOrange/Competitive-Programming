#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n {}; cin >> n;

    vector<int> bessie {};
    for (int i {1}; i < n; ++i) {int j {}; cin >> j; bessie.push_back(j);}

    vector<int> photoshoot {};

    for (int i {1}; i < bessie[1]; ++i) {
        vector<int> john {i};
        set<int> sequence {i};

        for (int j : bessie) {const int k {j - john[john.size() - 1]}; if (!(1 <= k && k <= n)) {break;};if (sequence.find(k) == sequence.end()) {john.push_back(k); sequence.insert(k);} else {break;}}

        if (john.size() == n) {photoshoot = {john}; break;}
    }

    cout << photoshoot[0]; for (int i {1}; i < n; ++i) {cout << " " << photoshoot[i];}
}