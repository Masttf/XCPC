#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
struct MCFGraph {
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
        dis.assign(n, Max);
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
        return dis[t] != Max;
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
            int aug = Max;
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
    int n, p, q; cin >> n >> p >> q;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
    	cin >> b[i];
    }
    int s = 0, t = n + 3;
    MCFGraph g(t + 1);
    for(int i = 1; i <= n; i++){
    	g.addEdge(s, i, 1, 0);
    	g.addEdge(i, n + 1, 1, -a[i]);
    	g.addEdge(i, n + 2, 1, -b[i]);
    }
    g.addEdge(n + 1, t, p, 0);
    g.addEdge(n + 2, t, q, 0);
    cout << -g.flow(s, t).second << '\n';
    vector<int>res1, res2;
    for(int i = 0; i < g.e.size(); i += 2){
    	int u = g.e[i ^ 1].v;
    	int v = g.e[i].v;
    	int c = g.e[i].c;
    	if(c != 0)continue;
    	if(v == n + 1)res1.push_back(u);
    	if(v == n + 2)res2.push_back(u);
    }
    for(auto x : res1){
    	cout << x << ' ';
    }
    cout << '\n';
    for(auto x : res2){
    	cout << x << ' ';
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}