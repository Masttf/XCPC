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
    int x;

   public:
    ModInt(int X = 0) : x(X % mod) {}
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
    friend std::ostream &operator<<(std::ostream &out, const ModInt &x) {
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
void solve() {
    int n, m;
    cin >> n >> m;
    mint ans1 = n * (m + 1);
    int now = 1;
    int cnt = 0;
    vector<mint> p(10);
    p[0] = 1;
    for (int i = 1; i < 10; i++) p[i] = p[i - 1] * 26;
    while (n >= now && cnt <= m) {
        now *= 26;
        cnt++;
    }
    now /= 26;
    ans1 -= n * cnt;
    for (int i = 0; i <= cnt - 1; i++) ans1 += p[i];
    auto get = [&](auto self, mint N, int k) -> mint {
        if (k == 1) {
            return 1;
        }
        if (k % 2 == 1) {
            return self(self, N, k / 2) * (1 + N.pow(k / 2)) + N.pow(k - 1);
        } else {
            return self(self, N, k / 2) * (1 + N.pow(k / 2));
        }
    };
    //dbg(get(get, 2, 5));
    mint N = 1;
    mint ans2 = 1;
    for (int i = 1; i <= m; i++) {
        N *= 26;
        ans2 += get(get, (N - 1) / N, n);
        // dbg(dp[i]);
        dbg(ans2);
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}