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
constexpr int Max=1e18;
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
            cost += (int)aug * h[t];
        }
        return {flow, cost};
    }
};
void solve(){
    int n;cin>>n;
    vector a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)cin>>a[i][j];
    }
	MCFGraph g(2*n+2);
	for(int i=1;i<=n;i++){
		g.addEdge(0,i,1,0);
		g.addEdge(n+i,2*n+1,1,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g.addEdge(i,n+j,1,a[i][j]);
		}
	}
	int mi=g.flow(0,2*n+1).second;
	MCFGraph g2(2*n+2);
	for(int i=1;i<=n;i++){
		g2.addEdge(0,i,1,0);
		g2.addEdge(n+i,2*n+1,1,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g2.addEdge(i,n+j,1,-a[i][j]);
		}
	}
	int mx=-g2.flow(0,2*n+1).second;
	cout<<mi<<'\n'<<mx<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}