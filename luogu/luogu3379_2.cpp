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
void solve(){
	int n, m, s; cin >> n >> m >> s;
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>dfn(n + 1), dep(n + 1);
	vector st(21, vector<pair<int, int>>(n + 1));
	int tot = 0;
	auto dfs = [&](auto self, int now, int father) -> void{
		dfn[now] = ++tot;
		dep[now] = dep[father] + 1;
		st[0][tot] = {dep[now], father};
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
		}
	};
	dfs(dfs, s, 0);
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1ll << k) <= n + 1; i++){
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
		}
	}
	auto lca = [&](int a, int b) -> int{
		if(a == b)return a;
		if(dfn[a] > dfn[b])swap(a, b);
		int l = dfn[a] + 1;
		int r = dfn[b];
		int len = (r - l + 1);
		int d = __lg(len);
		return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
	};
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}