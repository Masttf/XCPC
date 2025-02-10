#include<bits/stdc++.h>
using namespace std;
int dp[105][1005];
int val[105];
int wight[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,m;cin>>t>>m;
	for(int i=1;i<=m;i++)cin>>wight[i]>>val[i];
	for(int i=0;i<=t;i++){
		dp[0][i]=0;
		if(i<=m)dp[i][0]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			if(j-wight[i]<0)dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wight[i]]);
		}
	}
	cout<<dp[m][t];
	return 0;
}
