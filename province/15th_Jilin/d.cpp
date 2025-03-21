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
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }

    int q; cin >> q;
    map<pair<int, int>, vector<pair<int, int>>> Q;
    vector<array<int, 3>> tempQ(q + 1);
    vector<int> ans(q + 1);
    for(int i = 1; i <= q; i++){
    	int u, v, w; cin >> u >> v >> w;
    	tempQ[i] = {u, v, w};
    }

    vector<int> dp(n + 1), mx(n + 1), dep(n + 1);
    auto dfs = [&](auto self, int u, int father) -> void{
    	dep[u] = dep[father] + 1;
    	for(auto [v, w] : g[u]){
    		if(v == father)continue;
    		self(self, v, u);
    		dp[u] = max({dp[u], dp[v], mx[u] + mx[v] + w});
    		mx[u] = max(mx[u], mx[v] + w);
    	}
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= q; i++){
    	auto [u, v, w] = tempQ[i];
    	if(dep[u] > dep[v])swap(u, v);
    	Q[{u, v}].push_back({w, i});
    }
    auto dfs2 = [&](auto self, int u, int father) -> void{
    	const int sz = g[u].size();
    	vector<int> predp(sz + 1), sufdp(sz + 2);
    	vector<int> premx(sz + 1), sufmx(sz + 2);
    	for(int i = 0; i < sz; i++){
    		auto [v, w] = g[u][i];
    		premx[i + 1] = max(premx[i], mx[v] + w);
			predp[i + 1] = max({predp[i], dp[v], premx[i] + mx[v] + w});
    	}
    	for(int i = sz - 1; i >= 0; i--){
    		auto [v, w] = g[u][i];
    		sufmx[i + 1] = max(sufmx[i + 2], mx[v] + w);
			sufdp[i + 1] = max({sufdp[i + 2], dp[v], sufmx[i + 2] + mx[v] + w});
    	}
    	for(int i = 0; i < sz; i++){
    		auto [v, w] = g[u][i];
    		if(v == father)continue;
    		mx[u] = max(premx[i], sufmx[i + 2]);
    		dp[u] = max({predp[i], sufdp[i + 2], premx[i] + sufmx[i + 2]});
    		if(Q.count({u, v})){
    			for(auto [newW, id] : Q[{u, v}]){
    				ans[id] = max({dp[u], dp[v], mx[u] + mx[v] + newW});
    			}
    		}
    		self(self, v, u);
    	}
    };
    dfs2(dfs2, 1, 0);
    for(int i = 1; i <= q; i++){
    	cout << ans[i] << '\n';
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