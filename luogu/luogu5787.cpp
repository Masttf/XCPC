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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>>tr(k * 4);
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].push_back(val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	vector<pair<int, int>>edge(m + 1);
	for(int i = 1; i <= m; i++){
		int u, v, l, r; cin >> u >> v >> l >> r;
		edge[i] = {u, v};
		//dbg(i, l, r);
		r--;
		if(l <= r)updata(updata, 0, k, l, r, i, 1);
	}
	vector<int> f(2 * n + 1), sz(2 * n + 1);
	vector<int>stk;
	for(int i = 1; i <= 2 * n; i++)f[i] = i, sz[i] = 1;
	auto find = [&](int x) -> int{
		while(f[x] != x){
			x = f[x];
		}
		return x;
	};
	auto merge = [&](int x) -> void{
		auto [a, b] = edge[x];
		int fa = find(a);
		int fb = find(b + n);
		if(fa != fb){
			if(sz[fa] > sz[fb])swap(fa, fb);
			f[fa] = fb;
			sz[fb] += sz[fa];
			stk.push_back(fa);
		}
		fa = find(a + n);
		fb = find(b);
		if(fa != fb){
			if(sz[fa] > sz[fb])swap(fa, fb);
			f[fa] = fb;
			sz[fb] += sz[fa];
			stk.push_back(fa);
		}
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
	vector<int>ans(k + 1);
	auto dfs = [&](auto self, int l, int r, int p) -> void{
		//dbg(l, r);
		int siz = stk.size();
		int ok = 0;
		for(auto x : tr[p]){
			merge(x);
			auto [u, v] = edge[x];
			if(find(u) == find(u + n)){
				ok = 1;
				//dbg(u, v);
			}
		}
		if(ok){
			//dbg(l, r);
			for(int i = l; i <= r; i++)ans[i] = 1;
			rollback(siz);
			return ;
		}
		if(l == r){
			rollback(siz);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		rollback(siz);
	};
	dfs(dfs, 0, k, 1);
	for(int i = 0; i < k; i++){
		if(ans[i])cout << "No\n";
		else cout << "Yes\n";
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