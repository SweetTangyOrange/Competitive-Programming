#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n {};
    cin >> n;

    string a {}, b {};
    cin >> a >> b;

    bool k {false};

    int m {0};

    for (int i {0}; i < n; ++i) {
        if (a[i] != b[i] && k == false) {
            ++m;
            k = {true};
        } else if (a[i] == b[i]) {
            k = {false};
        }
    }

    cout << m;
}
