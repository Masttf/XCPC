// O(nlog^2(n))

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

#ifdef EMOFUNC
#include <debug.h>
#else
#define LOG(...)
#endif

const int mod = 998244353;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int&a, int b) { if ((a += b) >= mod) a -= mod; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod: a - b; }
inline void dec(int&a, int b) { if ((a -= b)<0) a += mod; }
inline int mul(int a, int b) { return int(i64(a) * b % mod); }

int qpow(int a, int n) {
    int ans = 1;
    for ( ; n; n >>= 1, a = mul(a, a)) {
        if (n & 1) {
            ans = mul(ans, a);
        }
    }
    return ans;
}

namespace ntt {

// P = 998244353 = (119<<23) + 1
const int modinv2 = (mod + 1) / 2; // 1/2 in F_P
const int G = 3;

//-------------------------------NTT--------------------------------
int wn[30], iwn[30]; //wn[i] = G^((P-1)/(2^i)) (mod P), iwn[i] = wn[i]^(-1) (mod P)

//do this before NTT
inline void init() {
    wn[23] = qpow(G, (mod - 1) / (1 << 23));
    for (int i = 22; i >= 0; i--) {
        wn[i] = mul(wn[i + 1], wn[i + 1]);
    }

    iwn[23] = qpow(wn[23], (1 << 23) - 1);
    for (int i = 22; i >= 0; i--) {
        iwn[i] = mul(iwn[i + 1], iwn[i + 1]);
    }
}

inline void revbin_permute(int a[], int n) {
    int i = 1, j = n >> 1, k;
    for ( ; i < n - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        for (k = n >> 1; j >= k; ) { j -= k; k >>= 1; }
        if (j < k) j += k;
    }
}

void NTT(int f[], int ldn, int is) {
    int n = (1 << ldn);
    revbin_permute(f, n);
    for (int ldm = 1; ldm <= ldn; ldm++) {
        int m = (1 << ldm), mh = (m >> 1);
        int dw = is > 0 ? wn[ldm] : iwn[ldm], w = 1;
        for (int j = 0; j < mh; j++) {
            for (int r = 0; r < n; r += m) {
                int u = f[r + j], v = mul(f[r + j + mh], w);
                f[r + j] = add(u, v);
                f[r + j + mh] = sub(u, v);
            }
            w = mul(w, dw);
        }
    }
}

void convolution(int f[], int g[], int n) {
    int ldn = __lg(n);
    NTT(f, ldn, 1);
    NTT(g, ldn, 1); // g will be changed
    for (int i = 0; i < n; i++) {
        f[i] = mul(f[i], g[i]);
    }
    NTT(f, ldn, -1);
    int iv = qpow(n, mod-2);
    for (int i = 0; i < n; i++) {
        f[i] = mul(f[i], iv);
    }
}

}; // namespace ntt

const int maxn = 1 << 19;

// f * g
vector<int> poly_mul(const vector<int>& f, const vector<int>& g) {
    int len = f.size() + g.size() - 1;

    if (len < 256) {
        vector<int> res(len);
        for (int i = 0; i < int(f.size()); i++) {
            for (int j = 0; j < int(g.size()); j++) {
                inc(res[i + j], mul(f[i], g[j])); 
            }
        }
        return res;
    }

    static int _f[maxn * 2], _g[maxn * 2];

    int ntt_len = 1 << (__lg(len) + 1);
    assert(ntt_len >= len && ntt_len < maxn * 2);

    for (int i = 0; i < ntt_len; i++) {
        _f[i] = i < int(f.size()) ? f[i] : 0;
        _g[i] = i < int(g.size()) ? g[i] : 0;
    }

    ntt::convolution(_f, _g, ntt_len);
    
    return vector<int>(_f, _f + len);
}

// f + g
vector<int> poly_add(const vector<int>& f, const vector<int>& g) {
    if (f.size() <= g.size()) {
        vector<int> res(g);
        for (int i = 0; i < int(f.size()); i++) {
            inc(res[i], f[i]);
        }
        return res;
    }

    vector<int> res(f);
    for (int i = 0; i < int(g.size()); i++) {
        inc(res[i], g[i]);
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ntt::init();
    
    int n, k;
    cin >> n >> k;

    vector<int> col(n);
    for (auto& v: col) {
        cin >> v;
        v--;
    }

    vector e(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> st;
    vector<bool> in_stack(n, false);
    vector<int> dep(n, 0);
    
    vector<int> vc(n);
    iota(vc.begin(), vc.end(), 2 * n);

    vector<int> anc(n);

    vector<vector<int>> ext(3 * n);
    vector<int> sz(3 * n, 1);

    auto build_ext = [&](auto& self, int u, int p, int d) -> void {
        st.push_back(u);
        in_stack[u] = true;
        dep[u] = d;

        int cu = col[u];

        while (vc[cu] < n && !in_stack[vc[cu]]) {
            vc[cu] = anc[vc[cu]];
        }

        anc[u] = vc[cu];

        int t = anc[u] < n ? st[dep[anc[u]] + 1] + n : anc[u];
        ext[t].push_back(u);

        vc[cu] = u;

        for (auto& v: e[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, d + 1);
            ext[u].push_back(n + v);
            sz[u] += sz[n + v];
        }

        sz[t] += sz[u];

        st.pop_back();
        in_stack[u] = false;
    };

    build_ext(build_ext, 0, 0, 0);

    for (int i = 0; i < 3 * n; i++) {
        sort(ext[i].begin(), ext[i].end(), [&sz](int u, int v) { return sz[u] > sz[v]; });
    }

    auto solve = [&](auto& self, int u) -> pair<vector<int>, vector<int>> {
        vector<int> id;
        
        vector<pair<vector<int>, vector<int>>> gt;
        vector<int> y;
        y.push_back(0);

        for (int v = u; ; v = ext[v][0]) {
            id.push_back(v);

            if (ext[v].size() == 0) {
                gt.emplace_back(vector<int>{1}, vector<int>{0});
                y.emplace_back(1);
                break;
            }

            // heavy child only
            if (ext[v].size() == 1) {
                gt.emplace_back(vector<int>{1}, vector<int>{0});
                y.emplace_back(1);
                continue;
            }

            // merge light children
            vector<pair<vector<int>, vector<int>>> fs;
            fs.reserve(ext[v].size() - 1);

            vector<int> x;
            x.reserve(ext[v].size());
            x.emplace_back(0);

            for (int i = 1; i < int(ext[v].size()); i++) {
                fs.emplace_back(self(self, ext[v][i]));

                if (ext[v][i] >= n) {
                    fs.back().second = poly_add(fs.back().second, fs.back().first);
                }

                x.emplace_back(fs.back().first.size());
            }

            for (int i = 1; i < int(x.size()); i++) {
                x[i] += x[i - 1];
            }
            
            auto light_dc = [&](auto &s, int l, int r) -> pair<vector<int>, vector<int>> {
                if (l == r - 1) {
                    return fs[l];
                }

                int m = lower_bound(x.begin() + l + 1, x.begin() + r - 1,  x[l] + (x[r] - x[l]) / 2) - x.begin();
                auto [f1, s1] = s(s, l, m);
                auto [f2, s2] = s(s, m, r);

                // (g[u], t[u])
                return {poly_mul(f1, f2), poly_add(s1, s2)};
            };

            gt.emplace_back(light_dc(light_dc, 0, fs.size()));
            y.emplace_back(gt.back().first.size());
        }

        id.push_back(-1);

        for (int i = 1; i < int(y.size()); i++) {
            y[i] += y[i - 1];
        }

        struct mat {
            vector<int> a[4];
        };

        auto heavy_dc = [&](auto &s, int l, int r) -> mat {
            if (l == r - 1) {
                return mat{vector<int>{id[l + 1] >= n}, gt[l].second, gt[l].first, vector<int>{0, id[l] < n}};
            }

            int m = lower_bound(y.begin() + l + 1, y.begin() + r - 1,  y[l] + (y[r] - y[l]) / 2) - y.begin();
            auto ml = s(s, l, m);
            auto mr = s(s, m, r);

            int l02 = int(ml.a[0].size()) + int(mr.a[2].size()) - 1;
            int l03 = int(ml.a[0].size()) + int(mr.a[3].size()) - 1;
            int l22 = int(ml.a[2].size()) + int(mr.a[2].size()) - 1;
            int l23 = int(ml.a[2].size()) + int(mr.a[3].size()) - 1;

            int len = max({l02, l03, l22, l23});

            if (len < 256) {
                return mat{
                    poly_add(mr.a[0], poly_mul(ml.a[0], mr.a[2])),
                    poly_add(poly_add(mr.a[1], poly_mul(ml.a[0], mr.a[3])), ml.a[1]),
                    poly_mul(ml.a[2], mr.a[2]),
                    poly_add(poly_mul(ml.a[2], mr.a[3]), ml.a[3])
                };
            }

            static int _f1[maxn * 2], _f2[maxn * 2], _f3[maxn * 2], _f4[maxn * 2];

            int ntt_ldn = __lg(len) + 1;
            int ntt_len = 1 << ntt_ldn;
            assert(ntt_len < maxn * 2);

            for (int i = 0; i < ntt_len; i++) {
                _f1[i] = i < int(ml.a[0].size()) ? ml.a[0][i] : 0;
                _f2[i] = i < int(ml.a[2].size()) ? ml.a[2][i] : 0;
                _f3[i] = i < int(mr.a[2].size()) ? mr.a[2][i] : 0;
                _f4[i] = i < int(mr.a[3].size()) ? mr.a[3][i] : 0;
            }

            ntt::NTT(_f1, ntt_ldn, 1);
            ntt::NTT(_f2, ntt_ldn, 1);
            ntt::NTT(_f3, ntt_ldn, 1);
            ntt::NTT(_f4, ntt_ldn, 1);
            
            // f1 = f1 * f3, f2 = f2 * f4, f3 = f2 * f3, f4 = f1 * f4
            for (int i = 0; i < ntt_len; i++) {
                int tmp = mul(_f1[i], _f4[i]);
                _f1[i] = mul(_f1[i], _f3[i]);
                _f3[i] = mul(_f2[i], _f3[i]);
                _f2[i] = mul(_f2[i], _f4[i]);
                _f4[i] = tmp;
            }

            ntt::NTT(_f1, ntt_ldn, -1);
            ntt::NTT(_f2, ntt_ldn, -1);
            ntt::NTT(_f3, ntt_ldn, -1);
            ntt::NTT(_f4, ntt_ldn, -1);

            int iv = qpow(ntt_len, mod - 2);
            for (int i = 0; i < ntt_len; i++) {
                _f1[i] = mul(_f1[i], iv);
                _f2[i] = mul(_f2[i], iv);
                _f3[i] = mul(_f3[i], iv);
                _f4[i] = mul(_f4[i], iv);
            }

            return mat{
                poly_add(mr.a[0], vector<int>(_f1, _f1 + l02)),
                poly_add(poly_add(mr.a[1], vector<int>(_f4, _f4 + l03)), ml.a[1]),
                vector<int>(_f3, _f3 + l22),
                poly_add(vector<int>(_f2, _f2 + l23), ml.a[3])
            };
        };

        auto M = heavy_dc(heavy_dc, 0, int(id.size()) - 1);

        // (f[u], s[u])
        return {poly_add(M.a[2], M.a[3]), poly_add(M.a[0], M.a[1])};
    };

    int ans = 0;
    for (int i = 2 * n; i < 3 * n; i++) {
        auto [f, s] = solve(solve, i);

        for (int j = 1; j < int(f.size()) && j <= k; j++) {
            inc(ans, f[j]);
        }
        
        for (int j = 1; j < int(s.size()) && j <= k - 1; j++) {
            inc(ans, s[j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
