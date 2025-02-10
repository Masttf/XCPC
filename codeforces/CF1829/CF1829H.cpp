#include<bits/stdc++.h>
#define lowbit(x) (x)&-(x)
#define int long long
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
int a[maxn];
int dp[maxn][65];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=64;j++)dp[i][j]=0;
	}
	for(int i=1;i<=n;i++){//表示前i项and和为j的子序列个数
		dp[i][a[i]]+=1;//单独加1
		for(int j=0;j<=64;j++){
			dp[i][j]+=dp[i-1][j];//不加这个
			dp[i][a[i]&j]+=dp[i-1][j];//加这个
			dp[i][j]%=mod;
		}
	}
	int ans=0;
	for(int i=0;i<=64;i++){
		int cnt=0;
		int x=i;
		while(x){
			cnt++;
			x-=lowbit(x);
		}
		if(cnt==k)ans+=dp[n][i],ans%=mod;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
