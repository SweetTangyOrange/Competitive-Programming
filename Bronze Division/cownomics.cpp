#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n{}, m{};
    cin >> n >> m;

    vector<vector<char>> spotty(n, vector<char>(m, 'A'));
    vector<vector<char>> plain(n, vector<char>(m, 'A'));

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            char k{};
            cin >> k;
            spotty[i][j] = {k};
        }
    }
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            char k{};
            cin >> k;
            plain[i][j] = {k};
        }
    }

    int o{0};

    for (int i{0}; i < m; ++i) { // genome
        // ACGT
        vector<bool> s(4, false);
        vector<bool> p(4, false);

        for (int j{0}; j < n; ++j) { // spotty cows
            switch (spotty[j][i]) {
                case ('A'): s[0] = true; break;
                case ('C'): s[1] = true; break;
                case ('G'): s[2] = true; break;
                case ('T'): s[3] = true; break;
            }
        }

        for (int j{0}; j < n; ++j) { // plain cows
            switch (plain[j][i]) {
                case ('A'): p[0] = true; break;
                case ('C'): p[1] = true; break;
                case ('G'): p[2] = true; break;
                case ('T'): p[3] = true; break;
            }
        }

        bool l{true};
        for (int j{0}; j < 4; ++j) {
            if (s[j] && p[j]) {
                l = {false};
                break;
            }
        }
        if (l) { ++o; }
    }

    cout << o;
}
