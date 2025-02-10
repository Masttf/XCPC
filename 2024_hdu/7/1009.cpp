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
constexpr int Max = 1e18;
void solve(){
	int n,k;cin >> n >> k;
	int lim = 1e9;
	vector<vector<pair<int, int>>>g(n + 1);
	vector<int>val(n + 1);
	for(int i = 1; i <= n; i++){
		int p; cin >> p;
		if(p == 0){
			int x; cin >> x;
			val[i] = x;
		}else{
			int x; cin >> x;
			for(int j = 1; j <= x; j++){
				int v, w; cin >> w >> v;
				g[i].push_back({v, w});
			}
		}
	}
	vector<int>vis(n + 1);
	auto dfs = [&](auto self, int now) -> void{
		for(auto [v, w] : g[now]){
			self(self, v);
			val[now] += val[v] * w;
			if(val[now] > lim)vis[now] = 1;
			vis[now] |= vis[v];
		}
		if(val[now] > lim)vis[now] = 1;
	};
	dfs(dfs, k);
	int cnt = 0;
	for(auto [v, w] : g[k]){
		if(vis[v] || val[v] * w > lim)cnt++;
	}
	int ans = Max;
	if(cnt >= 2){
		cout << "Impossible\n";
		return ;
	}else if(cnt == 1){
		for(auto [v, w] : g[k]){
			if(vis[v] || val[v] * w > lim){
				ans = val[k] - val[v] * w;
				break;
			}
		}
	}else{
		for(auto [v, w] : g[k]){
			ans = min(ans, val[k] - val[v] * w);
		}
	}
	if(ans <= lim)cout << ans << '\n';
	else cout << "Impossible\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}