#include <iostream>
#include <set>
using namespace std;

/*
 * This solves in O(n^2) complexity, failing on the last five test cases.
 */

int main() {
    long long n {}; cin >> n;

    long long patches[n];

    for (int i {0}; i < n; ++i) {cin >> patches[i];}

    long long pesticides {0};

    for (int patch {0}; patch < n; ++patch) {
        if (patches[patch] == 0) {continue;}

        const long long level {0 - patches[patch]};

        pesticides += abs(level);
        for (int i {patch}; i < n; ++i) {patches[i] += level * (i - patch + 1);}
    }

    cout << pesticides;
}