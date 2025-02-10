#include <bits/stdc++.h>

#include <queue>

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
constexpr int Max = 1e18;
struct MCFGraph {
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> h, dis, pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, Max);
        pre.assign(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                auto [v, c, f] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != Max;
    }
    MCFGraph(int a) {
        n = a;
        g.assign(a, vector<int>());
    }
    void addEdge(int u, int v, int c, int f) {
        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }
    pair<int, int> flow(int s, int t) {
        int flow = 0;
        int cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; i++) h[i] += dis[i];
            int aug = Max;
            for (int i = t; i != s; i = e[pre[i] ^ 1].v)
                aug = min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return {flow, cost};
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> val(n + 1), ct(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> ct[i];
    }
    vector<array<int, 3>> b(m + 1);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        b[i] = {u, v, w};
        sum += w;
    }
    int s = 0;
    int t = n + m + 1;
    MCFGraph f(t + 1);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = b[i];
        f.addEdge(s, n + i, w, 0);
        f.addEdge(n + i, u, w, 0);
        f.addEdge(n + i, v, w, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            f.addEdge(i, t, val[i] - ct[i], -1);
        } else {
            f.addEdge(i, t, val[i] - ct[i], 0);
        }
    }
    auto [flow, mx] = f.flow(s, t);
    mx = -mx + ct[1];
    //dbg(mx);
    if (flow != sum) {
        cout << "NO\n";
        return;
    }
    for (int i = 2; i <= n; i++) {
        val[i] = min(val[i], mx - 1);
        if (val[i] < ct[i]) {
            cout << "NO\n";
            return;
        }
    }
    MCFGraph f2(t + 1);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = b[i];
        f2.addEdge(s, n + i, w, 0);
        f2.addEdge(n + i, u, w, 0);
        f2.addEdge(n + i, v, w, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            f2.addEdge(i, t, val[i] - ct[i], -1);
        } else {
            f2.addEdge(i, t, val[i] - ct[i], 0);
        }
    }
    auto [ff, cc] = f2.flow(s, t);
    // dbg(ff, cc);
    if (ff != sum) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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