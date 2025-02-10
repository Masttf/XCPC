#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int mass[2][4] = {
    {2, 1, 0, 1},
    {1, 2, 1, 0}
};
// mass[i][j] : area of rectangle [[j, j + 1], [i, i + 1]] x 2

constexpr i64 inf = 4000000000ll;

int main() {
    // input
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    // calculation
    i64 ans = 0;
    for (int fy = 0; fy < 2; ++fy) {
        for (int fx = 0; fx < 4; ++fx) {
            const i64 x1 = (a - fx + 3 + inf) / 4, x2 = (c - fx + 3 + inf) / 4;
            const i64 count_x = x2 - x1; // count along x axis
            const i64 y1 = (b - fy + 1 + inf) / 2, y2 = (d - fy + 1 + inf) / 2;
            const i64 count_y = y2 - y1; // count along y axis
            ans += count_x * count_y * mass[fy][fx];
        }
    }

    // output
    cout << ans << endl;
}
