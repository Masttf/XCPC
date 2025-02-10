#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#define CAT(a, b) a ## b
using i128 = CAT(__int, 128);
using u128 = unsigned CAT(__int, 128);

#ifdef EMOFUNC
#include <debug.h>
#else
#define LOG(...)
#endif

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
            vector<i64> v;
            v.push_back(x);

            if (x == (x & -x)) {
                return v;
            }
            
            auto add_lowbit = [&](int lb) {
                i64 y = x >> lb;
                v.push_back((y * (y - 1)) << lb);
                v.push_back((y * (y + 1)) << lb);
                v.push_back((y + 1) << lb);
                x += (1 << lb);
            };

            for (int i = 0; i < 15 && x / (x & -x) >= (x & -x); i++) {
                if ((x >> i) & 1) {
                    add_lowbit(i);
                }
            }

            while (x > (x & -x)) {
                i64 y = x / (x & -x);
                i64 t = 1ll << (__lg(y) + 1);
                x = (t - y) * (x & -x);
                v.push_back(x);
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