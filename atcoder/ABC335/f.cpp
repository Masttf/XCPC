#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>dp(n+1);
	for(int i=n;i>=1;i--){
		dp[i]=1;
		for(int j=1;i+a[i]*j<=n;j++){
			int k=i+a[i]*j;
			if(a[k]==a[i]){
				dp[i]+=2*dp[k]-1;
				break;
			}else dp[i]+=dp[k];
			dp[i]%=mod;
		}
		dp[i]%=mod;
	}
	cout<<dp[1]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	int t=1;
	while(t--)solve();
	return 0;
}