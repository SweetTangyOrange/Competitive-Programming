#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n {}, b {}; cin >> n >> b;

    vector<pair<int, int>> cows (n, {0, 0});

    vector<int> abcissa (n, 0);
    vector<int> oordinate (n, 0);

    for (int l {0}; l < n; ++l) {int m {}, o {}; cin >> m >> o; cows[l].first = {m}; cows[l].second = {o}; abcissa[l] = {m}; oordinate[l] = {o};}

    sort(abcissa.begin(), abcissa.end());
    sort(oordinate.begin(), oordinate.end());

    abcissa.insert(abcissa.begin(), abcissa[0] - 2); abcissa.push_back(abcissa[n] + 2);
    oordinate.insert(oordinate.begin(), oordinate[0] - 2); oordinate.push_back(oordinate[n] + 2);

    vector<int> horizontals {};
    vector<int> verticals {};

    for (int l {0}; l < abcissa.size() - 1; ++l) {if (abcissa[l] == abcissa[l + 1]) {continue;} horizontals.push_back(abcissa[l] + (abcissa[l + 1] - abcissa[l]) / 2);}
    for (int l {0}; l < oordinate.size() - 1; ++l) {if (oordinate[l] == oordinate[l + 1]) {continue;} verticals.push_back(oordinate[l] + (oordinate[l + 1] - oordinate[l]) / 2);}

    int m {101};

    for (int horizontal : horizontals) {
        for (int vertical : verticals) {
            vector<int> regions (4, 0);

            for (pair<int, int> cow : cows) {if (cow.first < horizontal && cow.second < vertical) {++regions[0];} if (cow.first < horizontal && cow.second > vertical) {++regions[1];} if (cow.first > horizontal && cow.second < vertical) {++regions[2];} if (cow.first > horizontal && cow.second > vertical) {++regions[3];}}

            sort(regions.begin(), regions.end());
            if (regions[3] < m) {m = {regions[3]};}
        }
    }

    cout << m;
}
