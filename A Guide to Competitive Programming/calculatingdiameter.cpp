#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int vertice, int parent, vector<int>& toLeaf, vector<int>& longestPath, const vector<vector<int>>& adj) {
    vector<int> children {};

    for (int i : adj[vertice]) {
        if (i == parent) continue;

        dfs(i, vertice, longestPath, toLeaf, adj);
        children.push_back(i);
    }

    if (children.empty()) return;

    int length = 0; for (int i : children) length = max(length, toLeaf[i]); toLeaf[vertice] = length + 1;

    vector<int> path {}; for (int i : children) path.push_back(longestPath[i]); sort(path.begin(), path.end(), greater<int>());

    int longest = 0; if (path.size() >= 2) {longest = path[0] + path[1] + 2;} else {longest = path[0] + 1;} longestPath[vertice] = longest;
}

int main() {
    int n {}; cin >> n;

    vector<vector<int>> adj (n);
    for (int i {1}; i < n; ++i) {
        int a {}, b {}; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> toLeaf (n); vector<int> longestPath (n);
    dfs(0, -1, toLeaf, longestPath, adj);

    int d {0}; for (int i {0}; i < n; ++i) d = max(d, longestPath[i]); cout << d;
}