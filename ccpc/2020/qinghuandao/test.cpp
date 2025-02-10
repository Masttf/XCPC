
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> x(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> x[i].first >> x[i].second;
    }
    vector<int> nex(m + 1, m + 1);
    vector<int> ll(n + 1, m + 1);
    for(int i = m; i >= 1; i--){
        auto [pos, c] = x[i];
        nex[i] = ll[c];
        ll[c] = i;
    }
    set<pair<int, int>> q;
    for (int i = 1; i <= n; i++) q.insert({m + 1, i});
    for (int i = m; i >= 1; i--) {
        q.insert({i, x[i].second});
    }
    int last = 0;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 1; i <= m; i++) {
        auto [pos, c] = x[i];
        while (!q.empty() && (*q.begin()).first < i) q.erase(q.begin());
        while (last < pos && !q.empty()) {
            int cy = (*q.begin()).second;
            int use = min(pos - last, b[cy]);
            b[cy] -= use;
            last += use;
            if(!b[cy])q.erase(q.begin());
        }
        if (last < pos) break;
        b[c] = a[c];
        q.insert({nex[i], c});
    }
    for(int i = 1; i <= n; i++)last += b[i];
    cout << last << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}