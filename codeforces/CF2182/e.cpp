#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m + 1);
    vector<pair<int, int>> b(n + 1);

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int x, y, z; cin >> x >> y >> z;
        k -= y;
        z -= y;
        b[i] = {x, z};
    }

    int ans = 0;
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    priority_queue<int> q;
    int j = 1;
    for (int i = 1; i <= m; i++) {
        while(j <= n && b[j].first <= a[i]) {
            q.push(b[j].second);
            j++;
        }
        if (q.empty()) continue;
        ans++;
        q.pop();
        // cout << "--" << i << endl;
    }
    while(j <= n) {
        q.push(b[j].second);
        j++;
    }

    int sz = q.size();
    vector<int> c(sz + 1);
    int id = 1;
    while(!q.empty()) {
        c[id++] = q.top();
        q.pop();
    }
    reverse(c.begin() + 1, c.end());
    for (int i = 1; i <= sz; i++) {
        if (k >= c[i]) {
            ans++;
            k -= c[i];
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
    while(t--)solve();
    return 0;
}
