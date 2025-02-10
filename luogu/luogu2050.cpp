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
    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> h, dis;
    vector<int> pre;
    vector<int> vis;
    vector<int>temp;
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
    MCFGraph(int n){
        this->n = n;
        g.assign(n,{});
        vis.assign(n,0);
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
        temp.clear();
        if (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = Max;
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                int u=e[pre[i] ^ 1].v;
                if(!vis[u]){
                    vis[u]=1;
                    temp.push_back(u);
                }
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;

            }
            flow += aug;
            cost += (int)aug * h[t];
        }
        return {flow, cost};
    }
    void pf(){
        int sz=e.size();
        for(int i=0;i<sz;i+=2){
            int u=e[i+1].v;
            int v=e[i].v;
            cout<<u<<' '<<v<<' '<<e[i].c<<' '<<e[i].f<<endl;
            cout<<v<<' '<<u<<' '<<e[i+1].c<<' '<<e[i+1].f<<endl;
        }
    }
};
void solve(){
    int n,m;cin>>n>>m;
    vector<int>cnt(n+1);
    int sum=0;
    for(int i=1;i<=n;i++)cin>>cnt[i],sum+=cnt[i];
    vector time(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>time[i][j];
	}
	int s=0,t=m*sum+n+1;
	MCFGraph g(t+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        g.addEdge(sum*m+i,t,cnt[i],0);
    }
    for(int i=1;i<=m;i++){
        int u=i;
        g.addEdge(0,u,1,0);
        for(int k=1;k<=n;k++){
            int v=m*sum+k;
            g.addEdge(u,v,1,time[k][i]);
        }
    }
    int tot=0;
    {
        auto [a,b]=g.flow(s,t);
        tot+=a;
        ans+=b;
    }
    while(tot<sum){
        vector<int>res=g.temp;
        for(auto x:res){
            if(x>=1&&x<=m*(sum-1)){
                int u=x+m;
                g.addEdge(0,u,1,0);
                int ct=(u+m-1)/m;
                int v=(u-1)%m+1;
                for(int k=1;k<=n;k++){
                    g.addEdge(u,m*sum+k,1,ct*time[k][v]);
                }
            }
        }
        auto [a,b]=g.flow(s,t);
        tot+=a;
        ans+=b;
    }
	cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
