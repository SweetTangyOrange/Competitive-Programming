#include <iostream>
#include <array>
#include <cstdio>
using namespace std;

struct Rect {
    array<int, 4> coordinates {};

    Rect(int x_1, int y_1, int x_2, int y_2) {coordinates[0] = x_1; coordinates[1] = y_1; coordinates[2] = x_2; coordinates[3] = y_2;}

    int width() {return coordinates[2] - coordinates[0];}

    int height() {return coordinates[3] - coordinates[1];}
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x_1 {}, y_1 {}, x_2 {}, y_2 {};

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    Rect a(x_1, y_1, x_2, y_2);

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    Rect g(x_1, y_1, x_2, y_2);

    cin >> x_1 >> y_1 >> x_2 >> y_2;
    Rect t(x_1, y_1, x_2, y_2);

    int w_1 {}, h_1 {}, w_2 {}, h_2 {};

    w_1 = {max(min(a.coordinates[2], t.coordinates[2]) - max(a.coordinates[0], t.coordinates[0]), 0)};
    w_2 = {max(min(g.coordinates[2], t.coordinates[2]) - max(g.coordinates[0], t.coordinates[0]), 0)};

    h_1 = {max(min(a.coordinates[3], t.coordinates[3]) - max(a.coordinates[1], t.coordinates[1]), 0)};
    h_2 = {max(min(g.coordinates[3], t.coordinates[3]) - max(g.coordinates[1], t.coordinates[1]), 0)};

    const int area {((a.height() * a.width()) + (g.height() * g.width())) - (w_1 * h_1 + w_2 * h_2)};

    cout << area;
}