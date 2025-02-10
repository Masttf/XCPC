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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            if (a[i][j] == 'c' && a[i][j + 1] == 'c' && a[i + 1][j] == 'p' &&
                a[i + 1][j + 1] == 'c')
                ans++;
        }
    }
    cout << ans << '\n';
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