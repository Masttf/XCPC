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
constexpr int maxn = 2e5 + 5;
void solve(){
	int n, m; cin >> n >> m;
	vector<int> l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	vector<pair<int, int>>edge;
	vector<int> f(n + 1), sz(n + 1), ans(n + 1);
	vector<int>stk;
	for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 1;
	auto find = [&](int x) -> int{
		while(f[x] != x){
			x = f[x];
		}
		return x;
	};
	auto merge = [&](int x) -> void{
		auto [a, b] = edge[x];
		int fa = find(a);
		int fb = find(b);
		if(fa == fb)return ;
		if(sz[fa] > sz[fb])swap(fa, fb);
		f[fa] = fb;
		sz[fb] += sz[fa];
		ans[fa] -= ans[fb];
		stk.push_back(fa);
	};
	auto rollback = [&](int x) -> void{
		while(stk.size() > x){
			int fa = stk.back();
			int fb = f[fa];
			stk.pop_back();
			f[fa] = fa;
			sz[fb] -= sz[fa];
			ans[fa] += ans[fb];
		}
	};
	vector<vector<int>> tr(maxn * 4);
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].push_back(val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	auto dfs = [&](auto self, int l, int r, int p) -> void{
		int sz = stk.size();
		for(auto x : tr[p])merge(x);
		if(l == r){
			ans[find(1)]++;
			rollback(sz);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		rollback(sz);
	};
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		int ll = max(l[u], l[v]);
		int rr = min(r[u], r[v]);
		if(ll <= rr){
			updata(updata, 1, maxn, ll, rr, edge.size(), 1);
			edge.push_back({u, v});
		}
	}
	dfs(dfs, 1, maxn, 1);
	for(int i = 1; i <= n; i++){
		if(ans[i])cout << i << ' ';
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}