#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[35][35];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	dp[2][1]=1,dp[n][1]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j==1)dp[1][i]=dp[n][i-1]+dp[2][i-1];
			else if(j==n)dp[n][i]=dp[j-1][i-1]+dp[1][i-1];
			else dp[j][i]=dp[j-1][i-1]+dp[j+1][i-1];
		}
	}
	cout<<dp[1][m];
	return 0;
}
