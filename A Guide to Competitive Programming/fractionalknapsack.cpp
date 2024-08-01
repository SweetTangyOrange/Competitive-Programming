#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool s (pair<double, double> a, pair<double, double> b) {
    return a.second / a.first > b.second / b.first;
}

int main() {
    int n {}; double w {}; cin >> n >> w;

    vector<pair<double, double>> items (n);
    for (int i {0}; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end(), s);

    double v {0};
    
    while (w > 0) {
        if (w >= items[0].first) {
            w -= items[0].first; v += items[0].second; items.erase(items.begin());
        } else {
            v += w * items[0].second / items[0].first; break;
        }
    }

    cout << v;
}