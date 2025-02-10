#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int n=s.size();
	int cnt0=0,cnt1=0;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')cnt1++;
		else cnt0++;
	}
	int d=(n*(n-1)/2-cnt0*(cnt0-1)/2+cnt1*(cnt1-1)/2)/2;
	vector<vector<int>>dp(n+1,vector<int>(n*n+1,INT_MAX));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=cnt1;j>=1;j--){
			for(int k=i-1;k<=d;k++){
				dp[j][k]=min(dp[j][k],dp[j-1][k-i+1]+(s[i]=='0'));
			}
		}
	}
	cout<<dp[cnt1][d]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
