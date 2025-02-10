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
    int N;cin>>N;
    vector<int>a(N+1);
    for(int i=1;i<=N;i++){
    	cin>>a[i];
    }
    int p,m,f,n,s;
    cin>>p>>m>>f>>n>>s;
    int ss=0,tt=N*2+1;
    MCFGraph g(tt+1);
    for(int i=1;i<=N;i++){
    	g.addEdge(0,i,a[i],p);
    	g.addEdge(i,tt,a[i],0);
    	g.addEdge(0,N+i,a[i],0);
    }
    for(int i=1;i<=N;i++){
    	if(i<N)g.addEdge(i,i+1,Max,0);
    	if(i+m<=N)g.addEdge(i+N,i+m,Max,f);
    	if(i+n<=N)g.addEdge(i+N,i+n,Max,s);
    }
    cout<<g.flow(ss,tt).second<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}