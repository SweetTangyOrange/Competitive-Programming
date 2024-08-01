#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

int main() {
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);

    int n {};
    cin >> n;

    array<int, 10> cross = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int c {0}; 

    for (int i {0}; i < n; ++i) {
        int a {}, b {};
        cin >> a >> b;

        if (cross[a - 1] == 9) {
            cross[a - 1] = b;
        } else if (cross[a - 1] != b) {
            cross[a - 1] = b;
            ++c;
        }
    }

    cout << c;
}
