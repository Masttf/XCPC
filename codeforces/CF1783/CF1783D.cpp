#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=305,mod=998244353;
int a[maxn];
int dp[maxn][maxn*maxn*2];//定义为经过第i次变换i+1为j的方案数
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int wc=300*300;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1][a[2]+wc]=1;
	for(int i=2;i<=n-1;i++){
		for(int j=-wc;j<=wc;j++){
			int t=a[i+1]-j;
			if(t>=-wc&&t<=wc){
				if(t==0)dp[i][j+wc]=dp[i-1][t+wc];
				else dp[i][j+wc]=(dp[i][j+wc]+dp[i-1][t+wc]+dp[i-1][-t+wc])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=wc*2;i++)ans=(ans+dp[n-1][i])%mod;
	cout<<ans<<'\n';
	return 0;
}
