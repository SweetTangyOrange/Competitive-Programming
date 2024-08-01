#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

bool differ (vector<int> a, vector<int> b) {return a[0] < b[0];}

void hooveshake (map<int, int>& infected, int m, vector<int> timestamp) {
    bool i {false};
    bool j {false};

    if (!(infected.find(timestamp[1]) == infected.end())) {if (infected[timestamp[1]] < m) {++infected[timestamp[1]]; i = {true};}}

    if (!(infected.find(timestamp[2]) == infected.end())) {if (infected[timestamp[2]] < m) {++infected[timestamp[2]]; j = {true};}}

    if (infected.find(timestamp[1]) == infected.end() && j) {infected[timestamp[1]] = {0};}
    if (infected.find(timestamp[2]) == infected.end() && i) {infected[timestamp[2]] = {0};}
}

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int n {}, t {};
    cin >> n >> t;

    vector<int> official (n, 0); for (int i {0}; i < n; ++i) {char j {}; cin >> j; if (j == '0') {official[i] = {0};} else {official[i] = {1};}}
    
    vector<vector<int>> timestamps (t, vector<int> {0, -1, -1}); for (int l {0}; l < t; ++l) {for (int m {0}; m < 3; ++m) {int o {}; cin >> o; timestamps[l][m] += o;}} sort(timestamps.begin(), timestamps.end(), differ);

    int patients {0};
    pair<int, int> k {250, 0};

    for (int l {0}; l < n; ++l) {
        if (official[l] == 1) {
            bool patient {false};

            for (int m {0}; m <= t; ++m) {
                map<int, int> infected {{l, 0}}; for (vector<int> timestamp : timestamps) {hooveshake(infected, m, timestamp);}

                vector<int> sample (n, 0); for (auto o {infected.begin()}; o != infected.end(); ++o) {sample[o->first] = {1};}
                
                if (official == sample) {patient = {true}; if (m < k.first) {k.first = {m};} if (m > k.second) {k.second = {m};}}
            }

            if (patient) {++patients;}
        } else {
            continue;
        }
    }

    if (k.second == t) {cout << patients << " " << k.first << " Infinity";} else {cout << patients << " " << k.first << " " << k.second;}

    return 0;
}
