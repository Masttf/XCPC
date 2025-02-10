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
	vector<vector<int>>g(n + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>dep(n + 1);
	vector<int>ans;
	vector<int>t1;
	map<int, int>t2;
	auto dfs = [&](auto self, int now, int father) -> void{
		dep[now] = dep[father] + 1;
		//dbg(now);
		if(dep[now] % 2 == 1){
			t1.push_back(now);
		}
		else t2[now]++;
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
		}
	};
	for(int i = 1; i <= n; i++){
		if(!dep[i]){
			dfs(dfs, i, 0);
		}
	}
	int ok = 0;
	if(!t2.empty()){
		for(auto x : t1){
			if(ok)break;
			int chose = -1;
			for(auto v : g[x]){
				t2.erase(v);
			}
			if(!t2.empty()){
				ok = 1;
				chose = t2.begin() -> first;
				t2.erase(chose);
				for(auto xx : t1){
					if(xx != x)ans.push_back(xx);
				}
				ans.push_back(x);
				ans.push_back(chose);
				t1.push_back(chose);
			}
			for(auto v : g[x]){
				if(v != chose)t2[v]++;
			}
		}
	}else{
		for(auto x : t1)cout << x << ' ';
		cout << '\n';
		return ;
	}
	if(!ok){
		cout << -1 << '\n';
		return ;
	}
	for(auto [x, y] : t2){
		ans.push_back(x);
	}

	for(auto x : ans) cout << x <<' ';
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