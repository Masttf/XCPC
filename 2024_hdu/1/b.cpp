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
const int Max=1e18;
void solve(){
	int n,k;cin>>n>>k;
	vector val(n+1,vector<int>(5));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++)cin>>val[i][j];
	}
	vector dp(n+1,vector<int>(k+1,Max));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++)dp[i][j]=dp[i-1][j];
		for(int j=1;j<=4;j++){
			for(int d=j;d<=k;d++){
				dp[i][d]=min(dp[i][d],dp[i-1][d-j]+val[i][j]);
			}
		}
	}
	cout<<dp[n][k]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}