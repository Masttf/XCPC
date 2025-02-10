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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	vector<int>dp(n+1);
	int ans=0;
	int p=qmi(n,mod-2);
	for(int i=1;i<=n;i++){
		dp[i]=ans*p%mod+i*a[i]%mod;
		dp[i]%=mod;
		ans+=dp[i];
		ans%=mod;
	}
	ans=ans*p%mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}