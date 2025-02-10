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
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> sz(n + 1);
    int rt = -1, siz = n;
    auto dfs = [&](auto self, int now, int father) -> void{
    	sz[now] = 1;
    	int mx = 0;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		sz[now] += sz[v];
    		mx = max(mx, sz[v]);
    	}
    	mx = max(mx, n - sz[now]);
    	if(rt == -1 || siz > mx){
    		rt = now;
    		siz = mx;
    	}
    };
    dfs(dfs, 1, 0);
    vector<int> pos(n + 1);
    int dfn = 0;
    auto dfs2 = [&](auto self, int now, int father) -> void{
    	pos[++dfn] = now;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    	}
    };
    dfs2(dfs2, rt, 0);
    reverse(pos.begin() + 1, pos.end());
    for(int i = 1; i <= n / 2; i++){
    	cout << pos[i] << ' ' << pos[i + n / 2] << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}