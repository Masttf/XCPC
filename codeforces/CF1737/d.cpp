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
constexpr int maxn = 505;
int g[maxn][maxn];
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++)g[i][j] = Max;
    }
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u][v] = min(g[u][v], w);
    	g[v][u] = min(g[v][u], w);
    }
    int ans = 1e18;
   	vector dis(n + 1, vector<int>(n + 1));
  	auto bfs = [&](int x, int y) -> void{
  		queue<pair<int, int>>q;
  		vector vis(n + 1, vector<int>(n + 1));
  		vis[x][y] = 1;
  		vis[y][x] = 1;
  		q.push({x, y});
  		q.push({y, x});
  		while(!q.empty()){
  			auto [u, v] = q.front();
  			q.pop();
  			for(int i = 1; i <= n; i++){
  				if(g[u][i] != Max && !vis[i][v]){
  					dis[i][v] = dis[u][v] + 1;
  					vis[i][v] = 1;
  					q.push({i, v});
  				}
  				if(g[v][i] != Max && !vis[u][i]){
  					dis[u][i] = dis[u][v] + 1;
  					vis[u][i] = 1;
  					q.push({u, i});
  				}
  			}
  		}
  	};
  	bfs(1, n);
  	vector<int>d(n + 1);
  	vector<int> vis(n + 1);
  	auto bfs2 = [&](int s) -> void{
  		vis.assign(n + 1, 0);
  		queue<int>q;
  		vis[s] = 1;
  		d[s] = 0;
  		q.push(s);
  		while(!q.empty()){
  			int u = q.front();
  			q.pop();
  			for(int i = 1; i <= n; i++){
  				if(!vis[i] && g[u][i] != Max){
  					vis[i] = 1;
  					d[i] = d[u] + 1;
  					q.push(i);
  				}
  			}
  		}
  	};
  	for(int i = 1; i <= n; i++){
  		bfs2(i);
  		for(int j = 1; j <= n; j++){
  			if(g[i][j] == Max)continue;
  			int c = dis[i][j];
	  		for(int k = 1; k <= n; k++){
	  			c = min(c, d[k] + 1 + dis[k][k]);
	  		}
	  		ans = min(ans, (c + 1) * g[i][j]);
  		}
  	}
   	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}