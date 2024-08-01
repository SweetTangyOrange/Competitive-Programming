#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n {};
    cin >> n;

    vector<int> line (n, 0);

    for (int i {0}; i < n; ++i) {cin >> line[i];}

    for (int i {n - 1}; i > 0; --i) {if (line[i] < line[i - 1]) {cout << i; return 0;}}

    cout << 0; return 0;
}