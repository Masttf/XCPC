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
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n);
    vector<int> inf(n);
    for(int i = 1; i <= m; i++){
    	int u, d; cin >> u >> d;
    	if(d == 0)continue;
    	u = (u % n + n) % n;
    	int v = (((u + d) % n) + n) % n;
    	if(u == v){
    		inf[u] = 1;
    	}
    	g[u].push_back({v, d});
    }
    int tot = 0, cnt = 0;
    vector<int> dfn(n), low(n);
    vector<int> stk;
    vector<int> bl(n), val(n + 1), sz(n + 1);
    auto tarjan = [&](auto self, int now) -> void{
    	dfn[now] = low[now] = ++tot;
    	stk.push_back(now);
    	for(auto [v, w] : g[now]){
    		if(!dfn[v]){
    			self(self, v);
    			low[now] = min(low[now], low[v]);
    		}else if(!bl[v]){
    			low[now] = min(low[now], dfn[v]);
    		}
    	}
    	if(dfn[now] == low[now]){
    		cnt++;
    		int y;
    		// dbg(cnt);
    		do{
    			y = stk.back();
    			stk.pop_back();
    			// dbg(y);
    			bl[y] = cnt;
    			sz[cnt]++;
    		}while(y != now);
    	}
    };
    for(int i = 0; i < n; i++){
    	if(!dfn[i]){
    		tarjan(tarjan, i);
    	}
    }
    vector<int> vis(cnt + 1);
    vector<int> d(n);
    vector<int> iv(n);
    for(int i = 0; i < n; i++){
    	if(vis[bl[i]] || sz[bl[i]] < 2)continue;
    	vis[bl[i]] = 1;
    	queue<int> q;
    	q.push(i);
    	iv[i] = 1;
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		for(auto [v, w] : g[u]){
    			if(bl[v] != bl[u])continue;
    			if(iv[v]){
    				if(d[v] != d[u] + w){
    					inf[i] = 1;
    				}
    			}else{
    				iv[v] = 1;
    				d[v] = d[u] + w;
    				q.push(v);
    			}
    		}
    	}
    }
    vector<vector<int>>G(n);
    for(int i = 0; i < n; i++){
    	for(auto [v, w] : g[i]){
    		G[v].push_back(i);
    	}
    }
    auto bfs = [&]() -> void{
    	queue<int> q;
    	for(int i = 0; i < n; i++){
    		if(inf[i])q.push(i);
    	}
    	while(!q.empty()){
    		int u = q.front();
    		// dbg(u);
    		q.pop();
    		for(auto v : G[u]){
    			if(inf[v])continue;
    			inf[v] = 1;
    			q.push(v);
    		}
    	}
    };
    bfs();
    for(int i = 1; i <= q; i++){
    	int x; cin >> x;
    	x = (x % n + n) % n;
    	if(inf[x])cout << "Yes\n";
    	else cout << "No\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}