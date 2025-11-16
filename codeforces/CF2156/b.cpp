#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B'){
            ok = 1;
            break;
        }
    }
    for (int _ = 1; _ <= q; _++) {
        int x; cin >> x;
        if (!ok) {
            cout << x << '\n';
        } else {
            int now = 0;
            int cnt = 0;
            while(x > 0) {
                cnt++;
                if (s[now] == 'A') {
                    x -= 1;
                } else {
                    x /= 2;
                }
                // cout << x << ' ' << now << endl;
                now++;
                now %= n;
            }
            cout << cnt << '\n';
        }
    }
    return ;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
