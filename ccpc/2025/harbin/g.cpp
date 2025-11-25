#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] <= 0) {
                a[i][j - 1] += a[i][j];
            } else {
                a[i + 1][j] += a[i][j];
            }
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        ans += a[n + 1][i];
    }
    for (int i = 1; i <= n; i++) {
        ans -= a[i][0];
    }
    cout << ans << '\n';
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
