#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k {}, n {};
    cin >> k >> n;
    
    vector<vector<int>> rankings (k, vector<int> (n, 0));

    for (int l {0}; l < k; ++l) {for (int m {0}; m < n; ++m) {int o {}; cin >> o; rankings[l][m] = {o};}}

    int c {0};

    for (int l {1}; l <= n; ++l) {
        for (int m {l + 1}; m <= n; ++m) {
            int o {};

            vector<pair<int, int>> p (k, {0, 0});

            for (int i {0}; i < k; ++i) {
                for (int j {0}; j < n; ++j) {if (rankings[i][j] == l) {p[i].first = {j};} if (rankings[i][j] == m) {p[i].second = {j};}}
            }

            for (int i {0}; i < k; ++i) {if (p[i].first > p[i].second) {++o;}}

            if (o == k || o == 0) {++c;}
        }
    }

    cout << c;
}
