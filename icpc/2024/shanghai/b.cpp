#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> val(n + 1), p(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		val[p[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end(), [&](int x, int y) -> bool{
			return val[x] < val[y];
		});
	}
	vector<pair<int, int>> ans;
	vector<int> vis(n + 1);
	int nxt = 1;
	auto dfs = [&](auto self, int now) -> void{
		vis[now] = 1;
		assert(now == p[nxt]);
		nxt++;
		if(nxt > n)return ;
		const int sz = g[now].size();
		for(int i = 0; i < sz; i++){
			int v = g[now][i];
			if(vis[v])continue;
			// dbg(now, v, p[nxt]);
			if(v != p[nxt]){
				i--;
				ans.push_back({now, p[nxt]});
				self(self, p[nxt]);
			}else{
				self(self, p[nxt]);
			}
			
		}
	};
	for(int i = 1; i <= n; i++){
		if(vis[p[i]])continue;
		dfs(dfs, p[i]);
	}
	assert(ans.size() <= n - 1);
	cout << ans.size() << '\n';
	for(auto [x, y] : ans){
		cout << x << ' ' << y << '\n';
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