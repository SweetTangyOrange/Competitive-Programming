#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool a (pair<int, int> a, pair<int, int> b) {return a.first < b.first;}
bool b (pair<int, int> a, pair<int, int> b) {return a.second < b.second;}
bool c (pair<int, int> a, pair<int, int> b) {return (a.first + a.second) < (b.first + b.second);}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    int n {};
    cin >> n;

    vector<pair<int, int>> points (n, {0, 0});

    for (int i {0}; i < n; ++i) {int j {}, k {}; cin >> j >> k; points[i].first = {j}; points[i].second = {k};}

    vector<pair<int, int>> endpoints (4, {0, 0});

    sort(points.begin(), points.end(), a);
    endpoints[0].first = {points[0].first}; endpoints[0].second = {points[0].second};
    endpoints[1].first = {points[n - 1].first}; endpoints[1].second = {points[n - 1].second};

    const int l {endpoints[1].first - endpoints[0].first};

    sort(points.begin(), points.end(), b);
    endpoints[2].first = {points[0].first}; endpoints[2].second = {points[0].second};
    endpoints[3].first = {points[n - 1].first}; endpoints[3].second = {points[n - 1].second};

    const int h {endpoints[3].second - endpoints[2].second};
    
    for (int i {0}; i < 4; ++i) {
        int j {}, k {};

        sort(points.begin(), points.end(), a);
        if (endpoints[i].first == points[0].first && endpoints[i].second == points[0].second) {
            j = {points[1].first - endpoints[i].first};
        } else if (endpoints[i].first == points[n - 1].first && endpoints[i].second == points[n - 1].second) {
            j = {endpoints[i].first - points[n - 2].first};
        } else {
            j = {0};
        }

        sort(points.begin(), points.end(), b);
        if (endpoints[i].first == points[0].first && endpoints[i].second == points[0].second) {
            k = {points[1].second - endpoints[i].second};
        } else if (endpoints[i].first == points[n - 1].first && endpoints[i].second == points[n - 1].second) {
            k = {endpoints[i].second - points[n - 2].second};
        } else {
            k = {0};
        }

        endpoints[i].first = {j}; endpoints[i].second = {k};
    }

    sort(endpoints.begin(), endpoints.end(), c);
    cout << (l - endpoints[3].first) * (h - endpoints[3].second);
}
