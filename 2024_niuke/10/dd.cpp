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
	int n, m;
	double k; cin >> n >> m >> k;
	int r0; cin >> r0;
	vector<int>p(n + 1);
	for(int i = 1; i <= n; i++)cin >> p[i];
	vector<double> dp(m + 1);
	dp[0] = r0;
	for(int i = 1; i <= n; i++){
		auto ndp = dp;
		dp.assign(m + 1, 0);
		for(int j = 1; j <= min(i, m); j++){
			dp[j] = max(dp[j], ndp[j - 1]);
		}
		for(int j = 0; j <= min(i - 1, m); j++){
			dp[j] = max(dp[j], ndp[j] * (1 - k) + k * p[i]);
		}
	}
	double ans = 0;
	for(int i = 0; i <= m; i++)ans = max(ans, dp[i]);
	cout << fixed << setprecision(10) << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}