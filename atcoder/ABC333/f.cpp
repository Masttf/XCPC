#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n;cin>>n;
	vector dp(n+1,vector<int>(n+1));
	dp[1][1]=1;
	//dp i j =dp i-1 j-1 dpi j-1
	//dp i 1 =dp ii
	int inv=qmi(2,mod-2);
	for(int i=2;i<=n;i++){
		int k=1;
		int b=0;
		for(int j=2;j<=i;j++){
			k=k*inv%mod;
			b=(b*inv%mod+dp[i-1][j-1]*inv%mod)%mod;
		}
		k=k*inv%mod;
		b=b*inv%mod;
		int x=b*qmi(1-k,mod-2)%mod;
		if(x<0)x+=mod;
		dp[i][1]=x;
		for(int j=2;j<=i;j++){
			dp[i][j]=(dp[i-1][j-1]*inv%mod+dp[i][j-1]*inv%mod)%mod;
		}
	}
	for(int i=1;i<=n;i++)cout<<dp[n][i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}