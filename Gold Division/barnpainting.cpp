#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll m = 1e9 + 7;

void dfs(ll barn, ll parent, vector<ll>& dp, const vector<ll>& colors, const vector<vector<ll>>& adj) {
    vector<ll> children {}; for (ll i : adj[barn]) {
        if (i == parent) continue;

        dfs(i, barn, dp, colors, adj);
        children.push_back(i);
    }

    bool a = false, b = false, c = false;
    for (ll i : children) {
        if (!colors[i]) continue;

        switch(colors[i]) {
            case 1: a = true;
            case 2: b = true;
            case 3: c = true;
        }
    }

    if (colors[barn]) {
        dp[barn] = 1;
        for (ll i : children) {
            dp[barn] *= dp[i];
        }
    } else if (children.empty()) {
        dp[barn] = 2;
    } else if (barn == 0) {
        dp[barn] = 3 - a - b - c;
        for (ll i : children) {
            dp[barn] *= dp[i];
        }
    } else {
        dp[barn] = 2 - a - b - c;
        for (ll i : children) {
            dp[barn] *= dp[i];
        }
    }
}


int main() {
    io //freopen("barnpainting.in", "r", stdin); freopen("barnpainting.out", "w", stdout);

    ll n {}, k {}; cin >> n >> k;

    vector<vector<ll>> adj (n); for (ll i {1}; i < n; ++i) {
        ll a {}, b {}; cin >> a >> b; --a; --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<ll> colors (n); for (ll i {0}; i < k; ++i) {
        ll a {}, c {}; cin >> a >> c; --a;
        colors[a] = c;
    }

    vector<ll> dp (n); dfs(0, -1, dp, colors, adj);

    cout << dp[0];

    return 0;
}