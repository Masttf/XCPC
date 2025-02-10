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
    vector g(n + 1, vector<int>());
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> dep(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	dep[now] = dep[father] + 1;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    	}
    };
    dfs(dfs, 1, 0);
    int root = 1;
    for(int i = 1; i <= n; i++){
    	if(dep[root] < dep[i]){
    		root = i;
    	}
    }
    dfs(dfs, root, 0);
    int v = 1;
    for(int i = 1; i <= n; i++){
    	if(dep[v] < dep[i]){
    		v = i;
    	}
    }
    if(dep[v] - dep[root] == n - 1){
    	cout << root << ' ' << v << '\n';
    	return ;
    }
    cout << -1 << '\n';
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
/*
链
*/