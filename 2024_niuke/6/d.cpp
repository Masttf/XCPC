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
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n + 1);
	vector<array<int, 3>>e(m + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		string t; cin >> t;
		if(t[0] == 'L'){
			G[u].push_back(v);
			G[v].push_back(u);
			e[i] = {u, v, 1};
		}else{
			e[i] = {u, v, 0};
		}
	}
	vector<int>dfn(n + 1), low(n + 1);
	vector<int>stk;
	int tot = 0;
	int cnt = 0;
	vector<int>bl(n + 1);
	//vector<int> vis(n + 1);
	auto tarjan = [&](auto self, int now, int father) -> void{
		dfn[now] = low[now] = ++tot;
		stk.push_back(now);
		//vis[now] = 1;
		for(auto v : G[now]){
			if(v == father)continue;
			
			if(!dfn[v]){
				self(self, v, now);
				low[now] = min(low[now], low[v]);
			}else if(!bl[v]) low[now] = min(low[now], dfn[v]);
		}
		if(dfn[now] == low[now]){
			int y;
			cnt++;
			do{
				y = stk.back();
				stk.pop_back();
				bl[y] = cnt;
				//vis[y] = 0;
			}while(y != now);
		}
	};
	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			tarjan(tarjan, i, 0);
		}
	}
	set<pair<int, int>>ans;
	vector<int>f(n + 1);
	for(int i = 1; i <= n; i++)f[i] = i; 
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	auto merge = [&](int a, int b) -> bool{
		int fa = find(find, a);
		int fb = find(find, b);
		if(fa == fb)return false;
		f[fa] = fb;
		return true;
	};
	for(int i = 1; i <= m; i++){
		auto [u, v, w] = e[i];
		if(bl[u] == bl[v] && w == 1){
			ans.insert({u, v});
			merge(u, v);
		}
	}
	for(int i = 1; i <= m; i++){
		auto [u, v, w] = e[i];
		if(w == 0){
			if(merge(u, v)){
				ans.insert({u, v});
			}
		}
	}
	for(int i = 1; i <= n; i++)f[i] = i;
	for(auto [u, v] : ans){
		merge(u, v);
	}
	int num = 0;
	for(int i = 1; i <= n; i++){
		if(find(find, i) == i)num++;
	}
	if(num == 1){
		cout << "YES\n";
		cout << ans.size() << '\n';
		for(auto [u, v] : ans){
			cout << u << ' ' << v << '\n';
		}
	}else cout << "NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}