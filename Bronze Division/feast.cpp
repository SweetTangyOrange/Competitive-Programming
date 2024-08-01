#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n {}, m {};
    cin >> n >> m;

    // heights
    vector<long long> cows (n, 0);
    vector<long long> canes (m, 0);

    for (long long i {0}; i < n; ++i) {
        cin >> cows[i];
    }

    for (long long i {0}; i < m; ++i) {
        cin >> canes[i];
    }

    long long bottom {0};
    for (long long i {0}; i < m; ++i) { // each cane
        const long long q {canes[i]}; // cane height
        for (long long j {}; j < n; ++j) { // each cow
            const long long p {cows[j]}; // cow height

            if (q == bottom) {
                break;
            } else if (p >= q) {
                cows[j] += q - bottom;
                bottom = {q};
            } else if (p > bottom) {
                cows[j] += p - bottom;
                bottom = p;
            }
        }
        bottom = {0};
    }

    for (long long i {0}; i < n; ++i) {
        cout << cows[i] << "\n";
    }
}