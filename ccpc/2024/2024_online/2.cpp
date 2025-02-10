#include <bits/stdc++.h>

#define int long long
using namespace std;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)
void err() { cout << endl << endl; }
template <class T, class... Ts>
void err(T arg, Ts... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
template <const int mod>
class ModInt {
   private:
    int x = 0;

   public:
    ModInt() {}
    ModInt(int X) : x(X % mod) {}
    // ModInt(long long X) : x(X % mod) {}
    int val() { return x; }
    ModInt operator+(const ModInt &a) const {
        int x0 = x + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    ModInt operator-(const ModInt &a) const {
        int x0 = x - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    ModInt operator*(const ModInt &a) const {
        return ModInt(1LL * x * a.x % mod);
    }
    ModInt operator/(const ModInt &a) const { return *this * a.inv(); }
    bool operator==(const ModInt &a) const { return x == a.x; }
    bool operator!=(const ModInt &a) const { return x != a.x; }
    ModInt &operator+=(const ModInt &a) {
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &a) {
        x -= a.x;
        if (x < 0) x += mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &a) {
        x = 1LL * x * a.x % mod;
        return *this;
    }
    ModInt &operator/=(const ModInt &a) {
        *this = *this / a;
        return *this;
    }
    friend ModInt operator+(int y, const ModInt &a) {
        int x0 = y + a.x;
        return ModInt(x0 < mod ? x0 : x0 - mod);
    }
    friend ModInt operator-(int y, const ModInt &a) {
        int x0 = y - a.x;
        return ModInt(x0 < 0 ? x0 + mod : x0);
    }
    friend ModInt operator*(int y, const ModInt &a) {
        return ModInt(1LL * y * a.x % mod);
    }
    friend ModInt operator/(int y, const ModInt &a) { return ModInt(y) / a; }
    friend std::istream &operator>>(std::istream &in, ModInt &x) {
        in >> x.x;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, ModInt &x) {
        out << x.x;
        return out;
    }

    ModInt pow(long long n) const {
        ModInt res(1), mul(x);
        while (n) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};
constexpr int mod = 998244353;
using mint = ModInt<mod>;
constexpr int maxn = 1e3 + 5;
mint f[maxn];
// int ff[maxn];
void init() {
    f[0] = 1;
    // ff[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i;
        // ff[i] = ff[i - 1] * i % mod;
        // assert(ff[i] == f[i].val());
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        int mx = a[i], mi = a[i];
        for (int j = i; j <= n; j++) {
            mx = max(mx, a[j]);
            mi = min(mi, a[j]);
            ans1 += mx - mi;
        }
    }
    mint ans2 = 2;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n && a[j] == a[i]) {
            j++;
        }
        int len = j - i;
        ans2 *= f[len];
        i = j - 1;
    }
    if (a[1] == a[n]) ans2 /= 2;
    cout << ans1 << ' ' << ans2 << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    init();
    // cin >> T;
    while (T--) solve();
    return 0;
}