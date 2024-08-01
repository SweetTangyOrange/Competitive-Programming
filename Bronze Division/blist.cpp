#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n {};
    cin >> n;

    array<int, 999> milking {};

    for (int i {0}; i < n; ++i) {
        int s {}, t {}, b {};
        cin >> s >> t >> b;

        s; t;

        while (s < t) {
            milking[s - 1] += b;
            ++s;
        }
    }

    sort(milking.begin(), milking.end());
    cout << *(milking.end() - 1);
}
