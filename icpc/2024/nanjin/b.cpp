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
constexpr int inf = 1e9;
void solve(){
	string s; cin >> s;
	int n; n = s.size();
	s = ' ' + s;
	vector dp(n + 1, vector<array<int, 2>>(2, {inf, inf}));
	if(s[1] == '0'){
		dp[1][0] = {1, 1};
	}else if(s[1] == '1'){
		dp[1][1] = {1, 1};
	}else{
		dp[1][0] = {1, 1};
		dp[1][1] = {1, 1};
	}
	for(int i = 2; i <= n; i++){
		if(s[i] == '0'){
			dp[i][0] = {dp[i - 1][1][0] + 1, dp[i - 1][1][1] + 1};
			dp[i][1] = {dp[i - 1][0][0] - 1, dp[i - 1][0][1] - 1};
		}else if(s[i] == '1'){
			dp[i][1] = {dp[i - 1][0][0] + 1, dp[i - 1][0][1] + 1};
			dp[i][0] = {dp[i - 1][1][0] - 1, dp[i - 1][1][1] - 1};
		}else{
			dp[i][0] = {dp[i - 1][1][0] - 1, dp[i - 1][1][1] + 1};
			dp[i][1] = {dp[i - 1][0][0] - 1, dp[i - 1][0][1] + 1};
		}
	}
	int ans = inf;
	auto [l1, r1] = dp[n][0];
	if(r1 >= 0){
		ans = min(ans, l1 >= 0 ? l1 : (l1 % 2 + 2) % 2);
	}else ans = min(ans, -r1);
	auto [l2, r2] = dp[n][1];
	if(r2 >= 0){
		ans = min(ans, l2 >= 0 ? l2 : (l2 % 2 + 2) % 2);
	}else ans = min(ans, -r2);
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}