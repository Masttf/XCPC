#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+2);
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=n+1;
	
	vector<vector<int>>dp(n+3,vector<int>(n+3,INT_MAX));
	dp[0][0]=0;
	for(int i=1;i<=n+1;i++){
		for(int x=0;x<i;x++){
			if(a[i]>a[x]){
				for(int y=0;y<=x;y++){
					dp[i][y+1]=min(dp[i][y+1],dp[x][y]+i-x-1);
				}
			}
		}
		if(a[i]>a[i-1]){
			for(int x=0;x<=i;x++){
				dp[i][x]=min(dp[i][x],dp[i-1][x]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dp[n+1][i]<<' ';
		dp[n+1][i+1]=min(dp[n+1][i+1],dp[n+1][i]);
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}