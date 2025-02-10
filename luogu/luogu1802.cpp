#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[1005],v1[1005],v2[1005];
int dp[1005][1005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>v1[i]>>v2[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(j-w[i]<0)dp[i][j]=dp[i-1][j]+v1[i];
			else dp[i][j]=max(dp[i-1][j]+v1[i],dp[i-1][j-w[i]]+v2[i]);
		}
	}
	cout<<5*dp[n][x];
	return 0;
}
