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
int dx[]={0,1};
int dy[]={1,0};
void solve(){
    int n,k;cin>>n>>k;
    vector a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)cin>>a[i][j];
    }
	int s=0,t=n*n*2+1;
	MCFGraph g(t+1);
	g.addEdge(s,1,k,0);
	g.addEdge(n*n*2,t,k,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int u=(i-1)*n+j;
			g.addEdge(u,n*n+u,1,-a[i][j]);
			g.addEdge(u,n*n+u,k-1,0);
			for(int kk=0;kk<2;kk++){
				int tx=i+dx[kk];
				int ty=j+dy[kk];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=n){
					int v=(tx-1)*n+ty;
					g.addEdge(n*n+u,v,k,0);
				}
			}
		}
	}
	cout<<-g.flow(s,t).second<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}