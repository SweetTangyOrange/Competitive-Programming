#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    
    int x {}, y {}, m {};
    cin >> x >> y >> m;
    
    int o {0};
    
    for (int i {0}; i <= (m / x); ++i) {
        const int l {i * x + (m - i * x) / y * y};
        if (l > o) {o = {l};}
    }
    
    cout << o;
}
