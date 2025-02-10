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
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, 0);
        pre.assign(n, -1);
        std::priority_queue<std::pair<int, int>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            int d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] > d) continue;
            for (int i : g[u]) {
                int v = e[i].v;
                int c = e[i].c;
                int f = e[i].f;
                if (c > 0 && dis[v] < d + f) {
                    dis[v] = d + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != 0;
    }
    MCFGraph(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int c, int f) { // 最大流
	    g[u].push_back(e.size());
	    e.emplace_back(v, c, f);
	    g[v].push_back(e.size());
	    e.emplace_back(u, 0, -f);
	}
    std::pair<int, int> flow(int s, int t) {
        int flow = 0;
        int cost = 0;
        while (dijkstra(s, t)) {
            int aug = std::numeric_limits<int>::max();
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = std::min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += aug*dis[t];
        }
        return std::make_pair(flow, cost);
    }
    vector<vector<int>> get (int s,int t){
    	vector<vector<int>>res;
    	vector<int>vis(n+1);
    	for(int _=1;_<=2;_++){
    		vector<int>temp;
    		for(int i=s;i!=t;){
    			temp.push_back(i);
    			for(auto j:g[i]){
    				auto [v,c,f]=e[j];
    				int cc=e[j^1].c;
    				if(cc>=1&&!vis[v]){
    					if(i==s&&cc==1)vis[v]=1;
    					i=v;
    					break;
    				}
    			}
    		}
    		res.push_back(temp);
    	}
    	return res;
    }
};

void solve(){
	int n,m;cin>>n>>m;
	map<string,int>mp;
	vector<string>nm(n+1);
	for(int i=1;i<=n;i++){
		cin>>nm[i];
		mp[nm[i]]=i;
	}
	MCFGraph g(2*n+1);
	for(int i=1;i<=n;i++){
		if(i==1||i==n){
			g.addEdge(i,i+n,2,1);
		}else g.addEdge(i,i+n,1,1);
	}
	for(int i=1;i<=m;i++){
		string uu,vv;cin>>uu>>vv;
		int u=mp[uu];
		int v=mp[vv];
		cout << u << ' ' << v << ' ' << 1 << '\n';
		if(u>v)swap(u,v);
		g.addEdge(u+n,v,Max,0);
	}
	auto [flow,cost]=g.flow(1,2*n);
	if(flow!=2){
		cout<<"No Solution!\n";
		return ;
	}
	cout<<cost-2<<'\n';
	vector<vector<int>>ans=g.get(n+1,2*n);
	reverse(ans[1].begin(),ans[1].end());
	cout<<nm[1]<<'\n';
	for(auto x:ans[0]){
		if(x<n)cout<<nm[x]<<'\n';
	}
	cout<<nm[n]<<'\n';
	for(auto x:ans[1]){
		if(x<n)cout<<nm[x]<<'\n';
	}
	cout<<nm[1]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}