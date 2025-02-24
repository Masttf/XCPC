#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x);\
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
	int n;cin >> n;
	vector <char> a(n + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	vector <string> s(8);
	s[0] = "100";
	s[1] = "101";
	s[2] = "110";
	s[3] = "111";
	s[4] = "000";
	s[5] = "001";
	s[6] = "010";
	s[7] = "011";
	vector dp(n + 5,vector <int> (10));
	for (int i = 0;i < 8;i++) {
		int ok = 0;
		for (int j = 0;j < 3;j++) {
			if (s[i][j] != a[j + 1]) ok = 1;
		}
		if (!ok) dp[3][i] = 1;
		if (dp[3][3]) dp[3][7] = 1;
		if (dp[3][0]) dp[3][4]= 1;
		if (dp[3][1]) dp[3][2] = 1,dp[3][5] = 1;
		if (dp[3][2]) dp[3][1] = 1,dp[3][6] = 1;	
		if (dp[3][1]) dp[3][2] = 1,dp[3][5] = 1;
		if (dp[3][2]) dp[3][1] = 1,dp[3][6] = 1;
	}	
	//dbg(dp[3][1],dp[3][2]);
	for (int i = 4;i <= n;i++) {
		for (int j = 0;j < 8;j++) {
			if (dp[i - 1][j]) {
				for (int k = 0;k < 8;k++) {
					if (s[j][1] == s[k][0] && s[j][2] == s[k][1] && a[i] == s[k][2]) {
						dp[i][k] = 1;
					}
				}
			}
		}
		if (dp[i][3]) dp[i][7] = 1;
		if (dp[i][0]) dp[i][4] = 1;
		if (dp[i][1]) dp[i][2] = 1,dp[i][5] = 1;
		if (dp[i][2]) dp[i][1] = 1,dp[i][6] = 1;
		if (dp[i][1]) dp[i][2] = 1,dp[i][5] = 1;
		if (dp[i][2]) dp[i][1] = 1,dp[i][6] = 1;	
	}
	//dbg(dp[n][0],dp[n][1]);
	if (dp[n][0] || dp[n][4]) {
		cout << "Yes" << '\n';
	}
	else cout << "No" << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}