//
// Created by Luhao Yan on 2024/7/20.
//
 
#include <bits/stdc++.h>
 
using ll = long long;
const ll mod = 1e9 + 7;
const int lim = 2e6 + 10;
 
template<const int mod>
class Combinatorics {
    using ll = long long;
    int n = 0;
    std::vector<int>factorial, inverse_factorial, inverse;
public:
    Combinatorics() = default;
    explicit Combinatorics(int _n) : n(_n) {
        factorial.resize(n + 1);
        inverse_factorial.resize(n + 1);
        inverse.resize(n + 1);
        factorial[0] = inverse_factorial[0] = inverse_factorial[1] = 1;
        inverse[0] = inverse[1] = 1;
        for (int i = 1; i <= n; ++ i)
            factorial[i] = 1ll * factorial[i - 1] * i % mod;
        for (int i = 2; i <= n; ++ i)
            inverse[i] = 1ll * (mod - mod / i) * inverse[mod % i] % mod;
        for (int i = 1; i <= n; ++ i)
            inverse_factorial[i] = 1ll * inverse_factorial[i - 1] * inverse[i] % mod;
    }
    ll binom(int a, int b) {
        assert(0 <= a and a <= n);
        if (a < b || a < 0 || b < 0) return 0;
        return 1ll * factorial[a] * inverse_factorial[b] % mod * inverse_factorial[a - b] % mod;
    }
 
    [[maybe_unused]] ll fac(int a) {
        assert(0 <= a and a <= n);
        return factorial[a];
    }
 
    [[maybe_unused]] ll ifac(int a) {
        assert(0 <= a and a <= n);
        return inverse_factorial[a];
    }
    ll inv(int x) {
        if (x <= n) return inverse[x];
        ll res = 1;
        while (x != 1) {
            res = res * (mod - mod / x) % mod;
            x = mod % x;
        } return res;
    }
};
Combinatorics<mod> Calc(lim + 1);
 
void solve() {
    int n; std::cin >> n;
    std::vector a(n + 1, std::vector<int>(2, 0));
    for (int i = 1; i <= n; ++ i)
        std::cin >> a[i][0] >> a[i][1];
    std::vector dp (n + 2, std::vector (2, 0ll));
    dp[1][0] = dp[1][1] = 1;
    ll ans = 1;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < 2; ++ j) {
            auto b = a[i]; b[j] --;
            if (b[j] < 0) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                continue;
            }
            // the matching process finishs here
            if (a[i][j] >= 1) {
                ll way = ((b[0] + 2) * Calc.binom(b[0] + b[1] + 2, b[0] + 2) - b[1] - 1 + mod) % mod;
                way = way * Calc.inv(b[1] + 1) % mod;
                ans = (ans + dp[i][j] * way) % mod;
            }
            for (int k = 0; k < 2; ++ k) {
                // channeled every of the k-th orb, the next period must begins with the k-th orb
                ll way = Calc.binom(b[0] + b[1] + 1, b[k] + 1);
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * way) % mod;
            }
        }
    } std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    int t; std::cin >> t;
    while (t-->0) solve();
    return 0;
}
