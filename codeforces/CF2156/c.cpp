#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(n + 1);
    vector<int> suf(n + 2);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + cnt[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int num = cnt[i];
        if (i * 2 <= n) {
            num += cnt[i * 2];
        }
        if (i * 3 <= n) {
            num += cnt[i * 3];
        }
        if (i * 4 <= n) {
            num += suf[i * 4];
        }
        if (num >= n - k) {
            ans = i;
        }
    }
    cout << ans << '\n';
    return ;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
