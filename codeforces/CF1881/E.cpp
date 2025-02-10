#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=n;
	vector<int>dp(n+1);
	vector<int>mi(n+5,INT_MAX);
	for(int i=n;i>=1;i--){
		mi[i]=min(mi[i+1],mi[i]);
		dp[i]=n-i+1;
		if(a[i]+i==n)dp[i]=0;
		// for(int j=a[i]+1+i;j<=n;j++){
		// 	dp[i]=min(dp[i],dp[j]+j-(a[i]+i+1));
		// }
		if(a[i]+i+1<=n)dp[i]=min(dp[i],mi[a[i]+1+i]-(a[i]+i+1));
		mi[i]=min(mi[i],dp[i]+i);

	}
	//for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		ans=min(ans,i-1+dp[i]);
	}
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