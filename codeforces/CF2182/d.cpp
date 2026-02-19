#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
constexpr int maxn = 100;
int f[maxn], inv[maxn];
int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
void init() {
    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    inv[maxn - 1] = qmi(f[maxn - 1], mod - 2);
    for (int i = maxn - 1; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % mod;
    }
    return ;
}
int C(int n, int m) {
    if (n < 0 || m < 0) {
        return 0;
    }
    return f[n] * inv[n - m] % mod * inv[m] % mod;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int d = sum / n;
    int y = sum % n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > d + 1) {
            cout << 0 << '\n';
            return ;
        }
        if (a[i] == d + 1) {
            cnt++;
        }
    }

    if (cnt > y) {
        cout << 0 << '\n';
        return ;
    }
    int ans = 1;
    ans = ans * f[y] % mod;
    ans = ans * f[n - y] % mod;
    ans = ans * C(n - cnt, y - cnt) % mod;
    cout << ans << '\n';
    return ;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
