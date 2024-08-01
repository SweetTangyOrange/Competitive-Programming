#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a {}, b {}, c {}, d {};
    cin >> a >> b >> c >> d;

    cout << b - a + d - c - max(min(b, d) - max(a, c), 0);
}