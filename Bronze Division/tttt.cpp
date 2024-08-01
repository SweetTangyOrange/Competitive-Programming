#include <iostream>
#include <set>
#include <array>
#include <cstdio>
using namespace std;

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    
    array<array<char, 3>, 3> b {};
    for (int i {0}; i < 3; ++i) {for (int k {0}; k < 3; ++k) {char j {}; cin >> j; b[i][k] = {j};}}

    set<set<char>> t {};
    set<set<char>> i {};

    for (int j {0}; j < 3; ++j) {
        set<char> row {};
        for (int k {0}; k < 3; ++k) {row.insert(b[j][k]);}
        if (row.size() == 1) {i.insert(row);} else if (row.size() == 2) {t.insert(row);}
    }

    for (int k {0}; k < 3; ++k) {
        set<char> col {};
        for (int j {0}; j < 3; ++j) {col.insert(b[j][k]);}
        if (col.size() == 1) {i.insert(col);} else if (col.size() == 2) {t.insert(col);}
    }

    set<char> n {b[0][0], b[1][1], b[2][2]};
    set<char> p {b[0][2], b[1][1], b[2][0]};
    
    if (n.size() == 1) {i.insert(n);} else if (n.size() == 2) {t.insert(n);}
    if (p.size() == 1) {i.insert(p);} else if (p.size() == 2) {t.insert(p);}

    cout << i.size() << "\n" << t.size() << "\n";
    return 0;
}
