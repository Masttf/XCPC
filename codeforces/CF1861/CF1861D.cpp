#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>dp(2,vector<int>(n+1));
	dp[0][1]=1;
	for(int i=2;i<=n;i++){
		dp[1][i]=dp[0][i-1];
		if(a[i]>a[i-1]){
			dp[1][i]=min(dp[1][i],dp[1][i-1]);
			dp[0][i]=dp[0][i-1]+1;
		}else if(a[i]<a[i-1]){
			dp[1][i]=min(dp[1][i],dp[1][i-1]+1);
			dp[0][i]=dp[0][i-1];
		}else{
			dp[1][i]=min(dp[1][i],dp[1][i-1]+1);
			dp[0][i]=dp[0][i-1]+1;
		}
	}
	int ans=min(dp[0][n],dp[1][n]);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
