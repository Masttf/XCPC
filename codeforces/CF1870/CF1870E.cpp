#include<bits/stdc++.h>
//#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	vector<vector<int>>dp(n+1,vector<int>(2*n+1));
	vector<vector<bool>>vis(n+1,vector<bool>(n+1));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)dp[i][j]=dp[i-1][j];
		int mex=0;
		vector<bool>cnt(n+1);
		for(int j=i;j>=1;j--){
			cnt[a[j]]=1;
			int ok=0;
			while(mex<=n&&cnt[mex])mex++,ok=1;
			if(vis[j][mex])continue;
			vis[j][mex]=1;
			if(ok){
				for(int k=0;k<=j;k++){
					dp[i][k^mex]|=dp[j-1][k];
				}
			}
		}
	}
	for(int i=n;i>=0;i--){
		if(dp[n][i]){
			cout<<i<<'\n';
			return ;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
