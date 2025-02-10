#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
void solve(){
	string s;cin>>s;
	int n=s.size();
	if(n==1){
		if(s[0]=='2'||s[0]=='1'){
			cout<<0<<'\n';
		}else if(s[0]=='0'||s[0]=='*'){
			cout<<1<<'\n';
		}else cout<<2<<'\n';
		return ;
	}
	s=' '+s;
	
	vector<vector<int>>dp(10,vector<int>(n+1));
	if(s[1]=='1'){
		dp[3][1]=1;
	}else if(s[1]=='0'){
		dp[1][1]=1;
	}else if(s[1]=='*'){
		dp[0][1]=1;
	}else if(s[1]=='?'){
		dp[1][1]=1;
		dp[0][1]=1;
		dp[3][1]=1;
	}
	for(int i=2;i<=n;i++){
		if(s[i]!='?'){
			if(s[i]=='*'){
				dp[0][i]=(dp[3][i-1]+dp[4][i-1]+dp[0][i-1])%mod;
			}else if(s[i]=='0'){
				dp[1][i]=(dp[1][i-1]+dp[2][i-1])%mod;
			}else if(s[i]=='1'){
				dp[2][i]=dp[0][i-1];
				dp[3][i]=(dp[1][i-1]+dp[2][i-1])%mod;
				
			}else{
				dp[4][i]=dp[0][i-1];
			}
		}else{
			dp[0][i]=(dp[3][i-1]+dp[4][i-1]+dp[0][i-1])%mod;
			dp[1][i]=(dp[1][i-1]+dp[2][i-1])%mod;
			dp[2][i]=dp[0][i-1];
			dp[3][i]=(dp[1][i-1]+dp[2][i-1])%mod;
			dp[4][i]=dp[0][i-1];
		}
	}
	int ans=0;
	ans=(ans+dp[0][n])%mod;
	ans=(ans+dp[1][n])%mod;
	ans=(ans+dp[2][n])%mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}