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
	string s; cin >> s;
	int n = s.size();
	s = ' ' + s;
	vector dp(4, vector<int>(n + 1));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		dp[0][i] = dp[0][i - 1];
		for(int j = 1; j <= min(i, 3ll); j++){
			dp[j][i] = dp[j - 1][i - 1] + dp[j][i - 1];
			//dbg(i, j, dp[j][i]);
			for(int k = i - 1; k >= max(1ll, i - j); k--){
				if(s[k] == s[i]){
					int d = i - k;
					dp[j][i] -= dp[j - d][k - 1];
					break;
					//dbg(j - d, k - 1, dp[j][i], dp[j - d][k - 1]);
				}
			}
			//dbg(i, j, dp[j][i]);
		}
	}
	int ans = 0;
	for(int i = 0; i <= 3; i++){
		ans += dp[i][n];
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