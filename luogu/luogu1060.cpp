#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[30005],p[30],val[30];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,n;cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>val[i]>>p[i];
	for(int i=1;i<=n;i++){
		for(int j=t;j>=val[i];j--){
			dp[j]=max(dp[j],dp[j-val[i]]+val[i]*p[i]);
		}
	}
	cout<<dp[t];
	return 0;
}
