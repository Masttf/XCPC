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
	int n; cin >> n;
	vector<vector<int>>color(n + 1);
	vector<pair<int, int>>edge;
	vector<int> f(n + 1), sz(n + 1);
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
		stk.push_back(fa);
	};
	auto rollback = [&](int x) -> void{
		while(stk.size() > x){
			int fa = stk.back();
			int fb = f[fa];
			stk.pop_back();
			f[fa] = fa;
			sz[fb] -= sz[fa];
		}
	};
	vector<vector<int>>tr(n * 4);
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].push_back(val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	int ans = 0;
	auto dfs = [&](auto self, int l, int r, int p) -> void{
		int siz = stk.size();
		for(auto x : tr[p])merge(x);
		if(l == r){
			for(auto x : color[l]){
				auto [u, v] = edge[x];
				int fa = find(u);
				int fb = find(v);
				ans += sz[fa] * sz[fb];
			}
			rollback(siz);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		rollback(siz);
	};
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		if(w > 1)updata(updata, 1, n, 1, w - 1, edge.size(), 1);
		if(w < n)updata(updata, 1, n, w + 1, n, edge.size(), 1);
		color[w].push_back(edge.size());
		edge.push_back({u, v});
	}
	dfs(dfs, 1, n, 1);
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}