#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
using namespace std;

bool day (tuple<int, string, int> a, tuple<int, string, int> b) {return get<0>(a) < get<0>(b);}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n {}; cin >> n;

    vector<tuple<int, string, int>> log {};
    for (int i {0}; i < n; ++i) {int day {}; string cow {}; int milk {}; cin >> day >> cow >> milk; log.emplace_back(day, cow, milk);}
    sort(log.begin(), log.end(), day);

    unordered_map<string, int> milks {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
    unordered_map<string, int> pictures {{"Bessie", 1}, {"Elsie", 1}, {"Mildred", 1}};

    int changes {0};

    for (tuple<int, string, int> entry : log) {
        const string cow {get<1>(entry)}; int milk {get<2>(entry)}; milks[cow] += milk;

        unordered_map<string, int> hung {{"Bessie", 0}, {"Elsie", 0}, {"Mildred", 0}};

        const int i {max(max(milks["Bessie"], milks["Elsie"]), milks["Mildred"])};

        if (milks["Bessie"] == i) {hung["Bessie"] = {1};}
        if (milks["Elsie"] == i) {hung["Elsie"] = {1};}
        if (milks["Mildred"] == i) {hung["Mildred"] = {1};}

        if (hung != pictures) {++changes; pictures = {hung};}
    }

    cout << changes;
}