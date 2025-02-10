#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>dp(n+1);
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		dp[i]=a[i];
		if((a[i]%2+2)%2!=(a[i-1]%2+2)%2){
			dp[i]=max(dp[i],dp[i-1]+a[i]);
		}
	}
	//for(int i=1;i<=n;i++)cout<<i<<" "<<dp[i]<<endl;
	int ans=*max_element(dp.begin()+1,dp.end());
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}