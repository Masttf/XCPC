#include<bits/stdc++.h>
using namespace std;
int res[1005][1005];
int dp[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)cin>>res[i][j];
	}
	for(int i=1;i<=n;i++)dp[n][i]=res[n][i];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+res[i][j];
		}
	}
	cout<<dp[1][1];
	return 0;
}
