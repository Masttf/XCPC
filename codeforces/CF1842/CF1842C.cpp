#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int dp[maxn];
int mx[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i]=0,mx[i]=-INT_MAX;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(mx[a[i]]!=INT_MAX){
			dp[i]=max(dp[i],i+1+mx[a[i]]);
		}
		mx[a[i]]=max(mx[a[i]],dp[i-1]-i);
	}
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
