#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 998244353;

struct Mint {
    int x;
    int &val() { return x; }
    Mint(int _x = 0) : x(_x) {}
    Mint operator + (const Mint &a) const { int x0 = x + a.x; return Mint(x0 < mod ? x0 : x0 - mod); }
    Mint operator - (const Mint &a) const { return (x < a.x ? x - a.x + mod : x - a.x); }
    Mint operator * (const Mint &a) const { return (1LL * x * a.x % mod); }
    Mint operator / (const Mint &a) const { return *this * a.inv(); }
    Mint& operator+=(const Mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& a) { if ((x -= a.x) < 0) x += mod; return *this; }
    friend ostream &operator<<(ostream &os, const Mint &a) { return os << a.x; }
    Mint inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};
template<class T>
T qpow(T x, int64_t n) {
    T res = 1;
    for (; n > 0; x = x * x, n /= 2)
        if (n & 1)
    	res = res * x;
    return res;
}

constexpr int M = 1 << 21;
Mint fac[M] = {1}, ifac[M];
Mint C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fac[n] * ifac[k] * ifac[n - k];
}

int main() {
    // freopen("01.in","r",stdin);
    // freopen("01.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i < M; i++) fac[i] = fac[i - 1] * i;
    ifac[M - 1] = fac[M - 1].inv();
    for (int i = M - 1; i > 0; i--) ifac[i - 1] = ifac[i] * i;
    
    int tc;cin>>tc;
    
    while(tc--){
        int n, k;
        cin >> n >> k;
        assert(1<=n&&n<=1000000);
        assert(1<=k&&k<=1000000000);
        Mint x = qpow(Mint(2), k);
        vector<Mint> f(n + 1, 1);
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] * Mint(x - n + i);
        Mint ans;
        for (int i = 0; i <= n; i++) ans += C(n, i) * f[n - i] * Mint(i % 2 ? mod - 1 : 1);
        ans = ans * f[n] * Mint(x - n + mod);
        cout << ans * x.inv()<<endl;
    }
    return 0;
}