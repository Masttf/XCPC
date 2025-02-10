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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	mx*=2;
	vector<int>prim;
	vector<int>vis(mx+1);
	vis[1]=1;
	for(int i=2;i<=mx;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;i*prim[j]<=mx;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	vector dp(n + 5,vector<int>(5,INT_MAX));
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
	dp[1][3] = 0;  
	if (a[1] == 1) dp[1][2] = 0;
	for (int i = 2;i <= n;i++) {
		if (a[i] == 1) {
			dp[i][3] = min(dp[i - 1][2],dp[i - 1][1]);
		}
		else if (a[i] % 2 == 0) {
			dp[i][3] = min(dp[i][3],dp[i - 1][0]);
			if (!vis[a[i] + 1]) {
				dp[i][3] = min(dp[i][3],dp[i - 1][2]);
			} 
		}
		else dp[i][3] = min(dp[i][3],dp[i - 1][1]);
		if (!vis[a[i] + a[i - 1]]) {
			dp[i][3] = min(dp[i][3],dp[i - 1][3]);
		}
		if (a[i] == 1) {
			dp[i][2] = min(dp[i][2],dp[i][3]);
		}
		else {
			dp[i][2] = min(dp[i - 1][1] + 1,dp[i - 1][2] + 1);
			if (!vis[1 + a[i - 1]]) {
				dp[i][2] = min(dp[i][2],dp[i - 1][3] + 1);
			}
		}
		dp[i][1] = min(dp[i - 1][2] + 1,dp[i - 1][0] + 1);
		if (a[i - 1] % 2) {
			dp[i][1] = min(dp[i][1],dp[i - 1][3] + 1);
		}
		dp[i][0] = dp[i - 1][1] + 1;
		if (a[i - 1] % 2 == 0) {
			dp[i][0] = min(dp[i][0],dp[i - 1][3] + 1);
		}
		//dbg(dp[i][0],dp[i][1],dp[i][2],dp[i][3],i);
	}
	int ans = 1e18;
	ans = min(ans,dp[n][0]);
		ans = min(ans,dp[n][1]);
			ans = min(ans,dp[n][2]);
				ans = min(ans,dp[n][3]);
				cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
//1 0 0 