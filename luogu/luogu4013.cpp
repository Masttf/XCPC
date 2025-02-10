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
    int m,n;cin>>m>>n;
    vector val(n+1,vector<int>(m+n));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m+i-1;j++)cin>>val[i][j];
    }
	int s=0,t=(m+n+m-1)*n+1;
	int tot=(m+n+m-1)*n/2;
	MCFGraph g1(t+1);
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m+i-1;j++){
    		int u=(m+i+m-2)*(i-1)/2+j;
    		//dbg(i,j,u);
    		g1.addEdge(u,u+tot,1,-val[i][j]);
    		if(i==1){
    			g1.addEdge(s,u,1,0);
    		}
    		if(i==n){
    			g1.addEdge(u+tot,t,1,0);
    		}
    		if(i<n){
    			for(int k=0;k<2;k++){
	    			int tx=i+1;
	    			int ty=j+k;
	    			int v=(m+tx+m-2)*(tx-1)/2+ty;
	    			g1.addEdge(u+tot,v,1,0);
	    		}
    		}
    		
    	}
    }
    MCFGraph g2(t+1);
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m+i-1;j++){
    		int u=(m+i+m-2)*(i-1)/2+j;
    		g2.addEdge(u,u+tot,Max,-val[i][j]);
    		if(i==1){
    			g2.addEdge(s,u,1,0);
    		}
    		if(i==n){
    			g2.addEdge(u+tot,t,Max,0);
    		}
    		if(i<n){
    			for(int k=0;k<2;k++){
	    			int tx=i+1;
	    			int ty=j+k;
	    			int v=(m+tx+m-2)*(tx-1)/2+ty;
	    			g2.addEdge(u+tot,v,1,0);
	    		}
    		}
    	}
    }
    MCFGraph g3(t+1);
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m+i-1;j++){
    		int u=(m+i+m-2)*(i-1)/2+j;
    		g3.addEdge(u,u+tot,Max,-val[i][j]);
    		if(i==1){
    			g3.addEdge(s,u,1,0);
    		}
    		if(i==n){
    			g3.addEdge(u+tot,t,Max,0);
    		}
    		if(i<n){
    			for(int k=0;k<2;k++){
	    			int tx=i+1;
	    			int ty=j+k;
	    			int v=(m+tx+m-2)*(tx-1)/2+ty;
	    			g3.addEdge(u+tot,v,Max,0);
	    		}
    		}
    	}
    }
    cout<<-g1.flow(s,t).second<<'\n';
    cout<<-g2.flow(s,t).second<<'\n';
    cout<<-g3.flow(s,t).second<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}