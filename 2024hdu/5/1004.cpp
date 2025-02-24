#include<bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
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
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int N = 1e5;
	int q; cin >> q;
	vector<vector<pair<int, int>>>qu(N + 1);
	for(int i = 1; i <= q; i++){
		int r, x;cin >> r >> x;
		qu[x].push_back({r, i});
	}
	vector<int>st(n + 1);
	vector<int>ed(n + 1);
	int dfn = 0;
	vector<int> dep(n + 1);
	vector<vector<int>> f(25, vector<int>(n + 1));
	auto dfs = [&](auto self, int now, int father) -> void{
		st[now] = ++dfn;
		dep[now] = dep[father]+1;
		f[0][now] = father;
		for(int i = 1; i <= 20; i++){
			f[i][now] = f[i - 1][f[i - 1][now]];
		}
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
		}
		ed[now] = dfn;
		return ;
	};
	dfs(dfs, 1, 0);
	
	auto lca = [&](int a, int b) -> int{
		if(dep[a] < dep[b])swap(a,b);
		for(int i = 20; i >= 0; i--){
			if(dep[a] - (1ll << i) >= dep[b])a = f[i][a];
		}
		if(a == b)return a;
		for(int i = 20; i >= 0; i--){
			if(f[i][a] != f[i][b]){
				a = f[i][a];
				b = f[i][b];
			}
		}
		return f[0][a];
	};
	vector<vector<int>>d(N + 1);
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			d[j].push_back(i);
		}
	}
	// int num = 0;
	vector<vector<pair<int, int>>>res(N + 1);
	for(int i = 1; i <= N; i++){
		int sz = d[i].size();
		for(int j = 0; j < sz; j++){
			for(int k = j; k < sz; k++){
				// num++;
				if(lcm(d[i][j], d[i][k]) == i){
					res[i].push_back({d[i][j], d[i][k]});
				}
			}
		}
	}
	// dbg(num);
	vector<long long>ans(q + 1);
	vector<long long>tr(n + 1);
	auto add = [&](int x, int val) -> void{
		while(x <= n){
			tr[x] += val;
			x += lowbit(x);
		}
	};
	auto ask = [&](int x) -> int{
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	};
	for(int i = 1; i <= N; i++){
		for(auto [x, y] : res[i]){
			if(x > n || y > n)continue;
			int fa = lca(x, y);
			if(x == y)add(st[fa], 1);
			else add(st[fa], 2);
		}
		
		for(auto [r, id] : qu[i]){
			ans[id] = ask(ed[r]) - ask(st[r] - 1);
		}
	}
	for(int i = 1; i <= q; i++){
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