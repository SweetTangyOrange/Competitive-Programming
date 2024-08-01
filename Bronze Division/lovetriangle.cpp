#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n {}; cin >> n;

    vector<int> edges {0}; for (int i {0}; i < n; ++i) {int node {}; cin >> node; edges.push_back(node);}

    for (int i {1}; i <= n; ++i) {if (edges[edges[edges[i]]] == i) {cout << "YES"; return 0;}}

    cout << "NO"; return 0;
}