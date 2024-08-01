#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n {}; cin >> n;
    
    string mailboxes {};
    cin >> mailboxes;

    int o {};

    for (int k {1}; k <= n; ++k) {
        set<string> l {};

        for (int i {0}; i <= (n - k); ++i) {
            string m {};

            for (int j {i}; j < i + k; ++j) {m += mailboxes[j];}

            l.insert(m);
        }

        if (l.size() == n - k + 1) {o = k; break;}
    }

    cout << o;
}
