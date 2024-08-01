#include <iostream>
#include <cmath>
#include <array>
#include <cstdio>
using namespace std;

struct Rect {
    array<int, 4> coordinates {};
    int area {};

    Rect(int x_1, int y_1, int x_2, int y_2) {
        coordinates[0] = x_1; coordinates[1] = y_1; coordinates[2] = x_2; coordinates[3] = y_2;
        area = abs((x_2 - x_1) * (y_2 - y_1));
    }
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x_1 {}, y_1 {}, x_2 {}, y_2 {};

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    Rect lawn(x_1, y_1, x_2, y_2);

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    Rect cow(x_1, y_1, x_2, y_2);

    if ((cow.coordinates[0] <= lawn.coordinates[0] || cow.coordinates[2] >= lawn.coordinates[2]) && (cow.coordinates[1] <= lawn.coordinates[1] && lawn.coordinates[3] <= cow.coordinates[3])) {
        int width{max(min(cow.coordinates[2], lawn.coordinates[2]) - max(cow.coordinates[0], lawn.coordinates[0]), 0)};
        int height{max(min(cow.coordinates[3], lawn.coordinates[3]) - max(cow.coordinates[1], lawn.coordinates[1]), 0)};

        const int tarp{lawn.area - width * height};
        cout << tarp;
    } else if ((cow.coordinates[3] >= lawn.coordinates[3] || cow.coordinates[1] <= lawn.coordinates[1]) && (cow.coordinates[0] <= lawn.coordinates[0] && lawn.coordinates[2] <= cow.coordinates[2])) {
        int width{max(min(cow.coordinates[2], lawn.coordinates[2]) - max(cow.coordinates[0], lawn.coordinates[0]), 0)};
        int height{max(min(cow.coordinates[3], lawn.coordinates[3]) - max(cow.coordinates[1], lawn.coordinates[1]), 0)};

        const int tarp{lawn.area - width * height};
        cout << tarp;
    } else {
        cout << lawn.area;
    }
}