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
	vector<int>dp(n + 1);
	for(int i = 1; i <=m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
	}
	dp[n] = n;
	for(int i = n - 1; i >= 1; i--){
		int now = i + 1;
		int s = 0;
		while(s < g[i].size() && g[i][s] == now){
			now++;
			s++;
		}
		dp[i] = min(dp[i + 1], now - 1);
		//dbg(i, dp[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[i] - i + 1;
	}
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