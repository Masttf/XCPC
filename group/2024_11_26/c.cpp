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
	int n; cin >> n;
	vector<int> f(n);
	vector<vector<int>>g(n);
	for(int i = 1; i < n; i++){
		cin >> f[i];
		g[f[i]].push_back(i);
	}
	vector<int> dep(n + 1);
	vector fa(21, vector<int>(n + 1));
	vector mx(21, vector<int>(n + 1));
	auto dfs = [&](auto self, int now, int father) -> void{
		fa[0][now] = father;
		dep[now] = dep[father] + 1;
		mx[0][now] = father;
		for(int i = 1; i <= 20; i++){
			fa[i][now] = fa[i - 1][fa[i - 1][now]];
			mx[i][now] = max(mx[i - 1][now], mx[i - 1][fa[i - 1][now]]);
		}
		for(auto v : g[now]){
			self(self, v, now);
		}
	};
	dfs(dfs, 0, 0);
	auto lca = [&](int a, int b) ->int{
		if(dep[a] < dep[b])swap(a, b);
		for(int i = 20; i >= 0; i--){
			if(dep[a] - (1 << i) >= dep[b]){
				a = fa[i][a];
			}
		}
		if(a == b)return a;
		for(int i = 20; i >= 0; i--){
			if(fa[i][a] != fa[i][b]){
				a = fa[i][a];
				b = fa[i][b];
			}
		}
		return fa[0][a];
	};
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int m; cin >> m;
		int rt = -1;
		for(int j = 1; j <= m; j++){
			int x; cin >> x;
			if(rt == -1)rt = x;
			else{
				rt = lca(rt, x);
			}
		}
		int ans = max(rt, mx[20][rt]);
		cout << ans << '\n';
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