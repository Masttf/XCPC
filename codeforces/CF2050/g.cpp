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
    int ans = 1;
    vector<int> fa(n + 1), val(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	fa[now] = father;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		val[v] = val[now] + g[now].size() - 2;
    		self(self, v, now);
    	}
    };
    dfs(dfs, 1, 0);
    vector<int> mx(n + 1);
    auto dfs2 = [&](auto self, int now, int father) -> void{
    	
    };
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
枚举lca，然后计数即可
f[u] + f[v] - 2 * f[lca] + (lca != 1)
*/