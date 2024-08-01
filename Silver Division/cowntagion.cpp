#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll n {}, days {0};

bool infected[100000];
void dfs(ll barn, vector<ll> adjacency[]) {
    ll uninfected {0};
    for (ll b : adjacency[barn]) {if (!infected[b]) {++uninfected;}}

    if (infected[barn] || !uninfected) {
        return;
    } else {
        days += uninfected + ceil(log(uninfected + 1) / log(2));

        infected[barn] = true;
        for (ll b : adjacency[barn]) {
            dfs(b, adjacency);
        }
    }
}

int main() {
    cin >> n;

    vector<ll> adjacency[n];
     for (int i {1}; i < n; ++i) {
        pair<int, int> road {}; cin >> road.first >> road.second; --road.first; --road.second;

        adjacency[road.first].push_back(road.second);
        adjacency[road.second].push_back(road.first);
    }

    dfs(0, adjacency);

    cout << days;
}