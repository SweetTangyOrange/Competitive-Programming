#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    int n {}, k {};
    cin >> n >> k;
    
    vector<int> d (n, 0);
    
    for (int i {0}; i < n; ++i) {int j {}; cin >> j; d[i] = {j};}
    sort(d.begin(), d.end());

    int m {0};
    
    for (int i {0}; i < n; ++i) {
        int l {1};
        
        for (int j {i + 1}; j < n; ++j) {if (d[j] <= d[i] + k) {l++;} else {break;}}
        
        if (l > m) {m = {l};}
    }
    
    cout << m;
}
