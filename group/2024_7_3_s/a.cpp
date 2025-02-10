#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
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
            cost += aug * h[t];
        }
        return {flow, cost};
    }
};
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	int n=4;
	vector<string>a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=' '+b[i];
	}
	auto get= [&](int x,int y)->int{
		return n*(x-1)+y;
	};
	auto rget = [&](int val)->pair<int,int>{
		int j=val%4;
		int i=val/4+1;
		if(j==0){
			j=4;
			i--;
		}
		return {i,j};
	};
	MCFGraph g(20);
	int s=0,t=17;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]=='1'){
				g.addEdge(s,get(i,j),1,0);
			}
			if(b[i][j]=='1'){
				g.addEdge(get(i,j),t,1,0);
			}
			for(int k=0;k<4;k++){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=n){
					g.addEdge(get(i,j),get(tx,ty),Max,1);
				}
			}
		}
	}
	cout<<g.flow(s,t).second<<'\n';
	vector<array<int,4>>res;
	for(int i=0;i<g.e.size();i+=2){
		int v=g.e[i].v;
		int u=g.e[i^1].v;
		if(u==s||v==t)continue;
		for(int j=1;j<=Max-g.e[i].c;j++){
			res.push_back({rget(u).first,rget(u).second,rget(v).first,rget(v).second});
		}
	}
	vector<int>temp(res.size());
	vector<int>vis(res.size());
	auto dfs = [&](auto self,int now)->void{
		if(now==res.size()){
			int flag=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i][j]!=b[i][j]){
						flag=0;
						break;
					}
				}
			}
			if(flag){
				for(int i=0;i<res.size();i++){
					auto [x1,y1,x2,y2]=res[temp[i]];
					cout<<x1<<y1<<x2<<y2<<'\n'; 
				}
				exit(0);
			}
		}
		for(int i=0;i<res.size();i++){
			if(vis[i])continue;
			auto [x1,y1,x2,y2]=res[i];
			if(a[x1][y1]==a[x2][y2])continue;
			vis[i]=1;
			swap(a[x1][y1],a[x2][y2]);
			temp[now]=i;
			self(self,now+1);
			swap(a[x1][y1],a[x2][y2]);
			vis[i]=0;
		}
	};
	dfs(dfs,0);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}