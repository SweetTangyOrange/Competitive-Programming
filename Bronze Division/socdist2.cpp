#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);

    int n {};
    cin >> n;

    vector<int> sick {};
    vector<int> healthy {};

    for (int i {0}; i < n; ++i) {
        int l {}, k {};
        cin >> l >> k;

        if (k == 1) {sick.push_back(l);} else {healthy.push_back(l);}
    }

    sort(sick.begin(), sick.end());
    sort(healthy.begin(), healthy.end());

    if (healthy.size() == 0) {cout << 1; return 0;}

    int r {abs(healthy[0] - sick[0])};
    for (int i {0}; i < healthy.size(); ++i) {for (int j {0}; j < sick.size(); ++j) {r = min(r, abs(healthy[i] - sick[j]));}} --r;

    int m {0};

    for (int i {0}; i < sick.size(); ++i) {++m; for (int j {i + 1}; j < sick.size(); ++j) {if (abs(sick[i] - sick[j]) <= r) {++i; continue;}}}

    cout << m; return 0;
}
