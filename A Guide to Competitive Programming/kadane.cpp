#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp (n); dp[0] = a[0]; for (int i {1}; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }

    int m {0}; for (int i : dp) {
        m = max(m, i);
    } cout << m;
}