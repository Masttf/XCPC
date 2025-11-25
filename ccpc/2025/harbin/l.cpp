#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[] = {-1, 1, 0};
int dy[] = {0, 0, 1};
constexpr int inf = 1e9;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> a(k + 1);
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    queue<pair<int, int>> q;
    for (int _ = 0; _ < (1 << k); _++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                g[i][j] = 1;
                vis[i][j] = -1;
            }
        }
        for (int i = 0; i < k; i++) {
            auto [x, y] = a[i + 1];
            int d = (_ >> i) & 1;
            int f = 1;
            if (d == 1) f = -1;
            for (int j = x; j >= 1 && j <= n; j += f) {
                g[j][y] = 0;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << g[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++) {
            vis[i][1] = 0;
            q.push({i, 1});
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            // cout << x << ' ' << y << endl;
            q.pop();
            for (int i = 0; i < 3; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx >= 1 && tx <= n && ty >=1 && ty <= m && g[tx][ty] == 1 && vis[tx][ty] == -1) {
                    vis[tx][ty] = vis[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            if (vis[i][m] != -1) {
                ans = min(ans, vis[i][m]);
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
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
