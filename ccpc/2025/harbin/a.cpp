#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n; cin >> n;
    int g = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        a[i] /= g;
    }
    int ans = g;
    int d = 0;
    for (int i = 2; i <= n; i++) {
        d = gcd(d, abs(a[i] - a[i - 1]));
    }
    ans *= d;
    if (ans == 0) {
        cout << "infinite\n";
        return ;
    }
    cout << ans << ' ' << d << '\n';
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
