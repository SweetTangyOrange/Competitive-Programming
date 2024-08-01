#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n {}, s {};
    cin >> n >> s; --s;

    vector<pair<int, int>> line (n, {0, 0});

    int pads {0};
    int targets {0};

    for (int i {0}; i < n; ++i) {int j {}, k {}; cin >> j >> k; line[i].first = {j}; line[i].second = {k}; if (j == 0) {++pads;} else {++targets;}}

    int broken {0};
    int power {1};
    int direction {1};
    int moves {1};

    if (line[s].first == 0) {
        direction = {-1};
        power += line[s].second;
    } else if (line[s].first == 1) {
        if (power >= line[s].second) {
            ++broken;
            line[s].first = {2};
        }
    }

    while (true) {
        ++moves;
        s += direction * power;

        if (!(s >= 0 && s <= n - 1)) {break;}
        if (broken == targets) {break;}
        if (moves > 1000000) {break;}

        if (line[s].first == 0) {
            direction *= -1;
            power += line[s].second;
        } else if (line[s].first == 1) {
            if (power >= line[s].second) {
                ++broken;
                line[s].first = {2};
            }
        }
    }

    cout << broken;
}