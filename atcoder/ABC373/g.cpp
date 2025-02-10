#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
struct MCFGraph {
    //#define int long long
    static constexpr int inf = 1e18;
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> h, dis;
    vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                auto[v, c, f] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != inf;
    }
    MCFGraph(int n) : n(n), g(n) {}
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
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].c);
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
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    for(int i = 1; i <= n; i++){
    	cin >> b[i].first >> b[i].second;
    }
    auto dis = [&](int x, int y) -> int{
    	return (a[x].first - b[y].first) * (a[x].first - b[y].first) + (a[x].second - b[y].second) * (a[x].second - b[y].second);
    };
    int s = 0, t = 2 * n + 1;
    MCFGraph g(t + 1);
    for(int i = 1; i <= n; i++){
    	g.addEdge(s, i, 1, 0);
    	g.addEdge(i + n, t, 1, 0);
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		g.addEdge(i, j + n, 1, dis(i, j));
    	}
    }
    auto [flow, cost] = g.flow(s, t);
    assert(flow == n);
    vector<int> ans(n + 1);
    for(int i = 4 * n; i < g.e.size(); i += 2){
    	int v = g.e[i].v;
    	int c = g.e[i].c;
    	int u = g.e[i ^ 1].v;
    	if(c == 0){
    		ans[u] = v - n;
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}