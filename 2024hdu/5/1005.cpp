#include<bits/stdc++.h>
//#define int long long
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
	int n; cin >> n;
	vector<vector<pair<int, int>>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});

	}
	vector<int>ans(n);
	vector<int>dep(n + 1);
	vector<int>ID(n + 1);
	vector<int>p(n + 1);
	auto dfs = [&](auto self, int now, int father) -> void{
		dep[now] = dep[father] + 1;
		p[now] = father;
		for(auto [v, id] : g[now]){
			if(v == father)continue;
			ID[v] = id;
			self(self, v, now);
		}
	};
	dfs(dfs, 1, 0);
	vector<int>f(n + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	vector<int>res(n + 1);
	for(int d = n / 2; d >= 1; d--){
		int x = find(find, d);
		for(int j = d + d; j <= n; j += d){
			int y = find(find, j);
			while(x != y){
				if(dep[x] > dep[y])swap(x, y);
				ans[ID[y]] = d;
				f[y] = find(find, p[y]);
				y = f[y];
			}
		}
	}
	for(int i = 1; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}