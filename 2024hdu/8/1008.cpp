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
	for(int i = 2; i <= n; i++){
		int x; cin >> x;
		g[x].push_back({i, i});
	}
	vector<int> mi(n + 1);
	auto dfs = [&](auto self, int now) -> void{
		mi[now] = now;
		for(auto &[id, v] : g[now]){
			self(self, v);
			mi[now] = min(mi[now], mi[v]);
			id = mi[v];
		}
		sort(g[now].begin(), g[now].end());
	};
	dfs(dfs, 1);
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	int dfn = 0;
	auto dfs1 = [&](auto self, int now) -> void{
		dfn++;
		a[now] = n + 1 - dfn;
		int sz = g[now].size();
		for(int i = sz - 1; i >= 0; i--){
			int v = g[now][i].second;
			self(self, v);
		}
	};
	dfs1(dfs1, 1);
	dfn = 0;
	auto dfs2 = [&](auto self, int now) -> void{
		dfn++;
		b[now] = n + 1 - dfn;
		for(auto [id, v] : g[now]){
			self(self, v);
		}
	};
	dfs2(dfs2, 1);
	for(int i = 1; i <= n; i++){
		cout << a[i] <<' ' << b[i] <<' ';
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