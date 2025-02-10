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
	int n, m; cin >> n >> m;
	vector a(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)cin >> a[i][j];
	}
	vector<int> dp(m + 1);
	vector<int> f(m + 1);
	for(int i = 1; i <= n; i++){
		swap(dp, f);
		vector<int>sum(m + 1);
		for(int j = 1; j <= m; j++)sum[j] = sum[j - 1] + a[i][j];
		vector<int>pre(m + 1);
		for(int j = 1; j <= m; j++){
			pre[j] = a[i][j];
			pre[j] = max(pre[j], pre[j - 1] + a[i][j]);
		}
		vector<int>suf(m + 2);
		for(int j = m; j >= 1; j--){
			suf[j] = a[i][j];
			suf[j] = max(suf[j], suf[j + 1] + a[i][j]);
		}
		int mx = -Max;
		for(int j = 1; j <= m; j++){
			mx = max(mx, f[j] - sum[j - 1] + max(0ll, pre[j - 1]));
			dp[j] = mx + sum[j] + max(0ll, suf[j + 1]);
			//dbg(j, mx);
		}
		mx = -Max;
		for(int j = m; j >= 1; j--){
			dp[j] = max(dp[j], mx - sum[j - 1] + max(0ll, pre[j - 1]));
			mx = max(mx, f[j] + sum[j] + max(0ll, suf[j + 1]));
		}
		// dbg(i);
		// for(int j = 1; j <= m; j++){
		// 	dbg(j, dp[j]);
		// }
	}
	int ans = -Max;
	for(int i = 1; i <= m; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}