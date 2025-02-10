#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n, m; cin >> n >> m;
	int k; cin >> k;
	vector<vector<pair<int, int>>>g(n + 1);
	vector<int>val(n + 1);
	vector<int>cnt(n + 1);
	vector<int>bl(n + 1);
	for(int i = 1; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		val[i] = w;
	}
	vector<int>dep(n + 1);
	vector f(21, vector<int>(n + 1));
	auto dfs = [&](auto self, int now, int father) -> void{
		dep[now] = dep[father] + 1;
		f[0][now] = father;
		for(int i = 1; i <= 20; i++){
			f[i][now] = f[i - 1][f[i -1][now]];
		}
		for(auto [v, id] : g[now]){
			if(v == father)continue;
			bl[v] = id;
			self(self, v, now);
		}
	};
	dfs(dfs, 1, 0);
	auto lca = [&](int a, int b) -> int{
		if(dep[a] < dep[b])swap(a, b);
		for(int i = 20; i >= 0; i--){
			if(dep[a] - (1ll << i) >= dep[b]){
				a = f[i][a];
			}
		}
		if(a == b)return a;
		for(int i =20; i >= 0; i--){
			if(f[i][a] != f[i][b]){
				a = f[i][a];
				b = f[i][b];
			}
		}
		return f[0][a];
	};
	int pre = 1;
	for(int i = 1; i <= m; i++){
		int x; cin >> x;
		int fa = lca(pre, x);
		//dbg(x, pre, fa);
		cnt[x]++;
		cnt[pre]++;
		cnt[fa] -= 2;
		pre = x;
	}
	vector<int>num(n + 1);
	auto dfs2 = [&](auto self, int now, int father) -> void{
		for(auto [v, id] : g[now]){
			if(v == father)continue;
			self(self, v, now);
			cnt[now] += cnt[v];
		}
		//dbg(now, cnt[now]);
		num[bl[now]] = cnt[now];
	};
	dfs2(dfs2, 1, 0);
	// for(int i = 1; i < n; i++){
	// 	dbg(i, num[i]);
	// }
	int ans = 0;
	for(int i = 1; i < n; i++){
		ans += val[i] * num[i];
	}
	priority_queue<pair<int, int>>q;
	for(int i = 1; i < n; i++){
		int d = val[i] - val[i] / 2;
		q.push({d * num[i], i});
	}
	while(!q.empty() && k){
		auto [v, id] = q.top();
		q.pop();
		k--;
		ans -= v;
		val[id] /= 2;
		int d = val[id] - val[id] / 2;
		d *= num[id];
		if(d > 0)q.push({d, id});
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}