#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n {}; cin >> n;

    vector<int> log {};
    vector<int> saved {};
    
    for (int i {0}; i < n; ++i) {int k {}; cin >> k; if (k == -1) {log.push_back(k);} else {log.push_back(k); saved.push_back(i);}}

    for (int i {0}; i < saved.size(); ++i) {for (int k {0}, j {saved[i] - log[saved[i]]}; j < saved[i]; ++k, ++j) {if (log[j] == -1 || log[j] == k) {log[j] = k;} else {cout << -1; return 0;}}}
    if (log[0] == 0 || log[0] == -1) {log[0] = 0;} else {cout << -1; return 0;}

    int l {0};
    for (int i : log) {if (i == 0) {++l;}}

    int m {0};
    for (int i {0}; i < n; ++i) {if (log[i] == -1) {++m;}}

    cout << l << " " << m + l << "\n";
}
