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
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n + 1);
    vector<int> vis(n + 1);
    int root;
    for(int i = 1; i <= m; i++){
    	int x; cin >> x;
    	root = x;
    	vis[x] = 1;
    }
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    int ans = 0;
    vector<int> sz(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	if(!vis[now])sz[now] = 1;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		sz[now] += sz[v];
    	}
    	if(vis[now]){
    		if(sz[now] % 2 == 0)ans += sz[now] / 2;
    		else{
    			ans += (sz[now] + 1) / 2;
    			if(!vis[father]){
    				sz[father]--;
    				vis[father] = 1;
    			}
    		}
    		sz[now] = 0;
    	}
    };
    dfs(dfs, root, 0);
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