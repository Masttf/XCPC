#include <bits/stdc++.h>

#include <vector>

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
void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    vector dp(n + 1, vector(m + 5, vector<mint>(m + 5)));
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            dp[i][j][j - 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int len = 1; len <= m; len++) {
            for (int l = 1; l + len - 1 <= m; l++) {
                int r = l + len - 1;
                dp[i][l][r] += 2 * dp[i - 1][l][r];
                for (int mid = l; mid < r; mid++) {
                    dp[i][l][r] += dp[i - 1][l][mid] * dp[i - 1][mid + 1][r];
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                for (int l = j; l >= 1; l--) {
                    for (int r = j; r <= m; r++) {
                        dp[i][l][r] += dp[i - 1][l][j - 1] * dp[i - 1][j + 1][r];
                    }
                }
            }
        }
    }
    cout << dp[n][1][m] << '\n';
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