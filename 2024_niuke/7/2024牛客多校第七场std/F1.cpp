#include <bits/stdc++.h>
using namespace std;

#define concat(x, y) x ## y

using i64 = long long;
using u64 = unsigned long long;
using i128 = concat(__int, 128_t); // suppress polygon warning

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {    
        i64 x, y;
        cin >> x >> y;

        i64 ox = x;
        i64 oy = y;
        
        // turns x to 2^k
        auto solve = [](i64& x) -> vector<i64> {
            int t = __lg(x);

            vector<i64> v;
            v.push_back(x);

            if (x == (1ll << t)) {
                return v;
            }
            
            auto add_lowbit = [&](int lb) {
                i64 y = x >> lb;
                v.push_back((y * (y - 1)) << lb);
                v.push_back((y * (y + 1)) << lb);
                v.push_back((y + 1) << lb);
                x += (1 << lb);
            };

            int m = t / 2;
            for (int i = 0; i <= m; i++) {
                if ((x >> i) & 1) {
                    add_lowbit(i);
                }
            }

            if (x == (1ll << t + 1)) {
                return v;
            }

            auto num = [](i64 x) -> int {
                i64 y = x / (x & -x);
                return __lg(y) + 1 - __builtin_popcountll(y) + 1;
            };

            if (num(x) > num((1ll << t + 1) - x)) {
                x = (1ll << t + 1) - x;
                v.push_back(x);
            }

            t = __lg(x);
            for (int i = m + 1; i <= t; i++) {
                if ((x >> i) & 1) {
                    add_lowbit(i);
                }
            }

            return v;
        };
        
        auto vx = solve(x);
        auto vy = solve(y);

        // x = 2^i < y = 2^j
        // turns x to y
        auto adjust = [&](vector<i64>& vx, i64 &x, i64 y) {
            vx.push_back(3 * x);
            while (x < y) {
                x *= 2;
                vx.push_back(3 * x);
            }
            vx.push_back(x);
        };

        if (x < y) {
            adjust(vx, x, y);
        } else if (y < x) {
            adjust(vy, y, x);
        }

        for (int i = int(vy.size()) - 2; i >= 0; i--) {
            vx.push_back(vy[i]);
        }

        cout << int(vx.size()) - 1 << "\n";
        for (int i = 0; i < int(vx.size()); i++) {
            cout << vx[i] << " \n"[i == int(vx.size()) - 1];
        }

        auto check = [&](const vector<i64>& v, i64 x, i64 y) -> bool {
            if (v.size() == 0) {
                cerr << "error: empty" << endl;
                return false;
            }

            if (v.size() > 151) {
                cerr << "error: too many steps: " << int(v.size()) - 1 << endl;
            }

            if (v.front() != x || v.back() != y) {
                cerr << "error: v[0] != x || v[m] != y" << endl;
                return false;
            }

            for (int i = 0; i < int(v.size()) - 1; i++) {
                if (v[i] * i128(v[i + 1]) % (v[i] + v[i + 1]) != 0) {
                    cerr << "error: from " << v[i] << " to " << v[i + 1] << endl;
                    return false;
                }
            }

            return true;
        };

        assert(check(vx, ox, oy));
    }

    return 0;
}
