#include <bits/stdc++.h>

using i64 = long long;
constexpr int LOG = 20;
constexpr int MAX = 2e5 + 1;
std::vector<i64> p, w;
std::vector<std::vector<int>> pth;

/* data validation arguments and functions --- start */
std::vector<char> visited(MAX, false); 
bool check_2e5_nonnegative(i64 x) {
    return 0 <= x && x <= 200000;
}
bool check_2e5_positive(i64 x) {
    return 1 <= x && x <= 200000;
}
bool check_1e6(i64 x) {
    return 1 <= x && x <= 1000000;
}
/* data validation arguments and functions --- end */

void add(int u, int v) {
    pth[u][0] = v;
    for(int i = 1; i < LOG; ++i) {
        pth[u][i] = pth[pth[u][i - 1]][i - 1];
    }
}

std::pair<i64,i64> query(int k, i64 s) {
    i64 res1 = 0, res2 = 0;
    while(s > 0 && w[k] != 0) {
        int now = k;
        for(int i = LOG - 1; i >= 0; --i) {
            if(w[pth[now][i]] != 0) {
                now = pth[now][i];
            }
        }

        if(w[now] == -1) {
            w[now] = 0;
            continue;
        }

        i64 buy = std::min(s, w[now]);
        s -= buy;
        w[now] -= buy;
        res1 += buy;
        res2 += buy * p[now];
    }
    return std::pair<i64,i64>(res1, res2);
}

void invade(int l) {
    if(w[pth[l][0]] != 0) {
        w[l] = -1;
    }else {
        w[l] = 0;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        int q, opt;
        std::cin >> q;
        std::vector<i64>(q + 1).swap(p);
        std::vector<i64>(q + 1).swap(w);
        std::vector<std::vector<int>>(q + 1, std::vector<int>(LOG)).swap(pth);
        /* data validation arguments and functions --- start */
        std::vector<char>(q, false).swap(visited); 
        /* data validation arguments and functions --- end */
        std::cin >> p[0] >> w[0];
        
        assert(check_2e5_positive(q));
        visited[0] = true; // data validation
        assert(check_1e6(p[0]) && check_1e6(w[0]));
    
        while(q --> 0) {
            std::cin >> opt;
            assert(1 <= opt && opt <= 3);
            switch (opt) {
                case 1: {
                    int u, v;
                    std::cin >> u >> v >> p[u] >> w[u];
                    assert(check_2e5_positive(u) && check_2e5_nonnegative(v) && check_1e6(p[u]) && check_1e6(w[u]));
                    assert(!visited[u]);
                    visited[u] = true; // data validation
                    assert(visited[v]);
                    add(u, v);
                }
                break;
    
                case 2: {
                    int k;
                    i64 s;
                    std::cin >> k >> s;
                    assert(check_2e5_nonnegative(k) && check_1e6(s));
                    auto [res1, res2] = query(k, s);
                    std::cout << res1 << ' ' << res2 << '\n';
                }
                break;
    
                case 3: {
                    int l;
                    std::cin >> l;
                    assert(check_2e5_nonnegative(l));
                    invade(l);
                }
                break;
    
            }
        }
    }
    return 0;
}
