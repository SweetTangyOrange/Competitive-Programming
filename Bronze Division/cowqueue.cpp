#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool sorter(pair<int, int>& a, pair<int, int>& b) {return b.first > a.first;}

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n {};
    cin >> n;

    vector<pair<int, int>> processing (n, {0, 0});

    for (int i {0}; i < n; ++i) {int l {}, m {}; cin >> l >> m; processing[i] = {l, m};}
    sort(processing.begin(), processing.end(), sorter);

    int line {0};

    for (auto i : processing) {const int j {line + 1}; if (j <= i.first) {line += (i.first - j);} line += i.second;}

    cout << line + 1;
}
