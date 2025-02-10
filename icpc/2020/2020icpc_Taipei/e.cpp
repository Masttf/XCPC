#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int m;cin>>m;
	int n=s.size();
	s=' '+s;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='R')a[i]=0;
		else if(s[i]=='G')a[i]=1;
		else if(s[i]=='B')a[i]=2;
		else if(s[i]=='C')a[i]=3;
		else if(s[i]=='M')a[i]=4;
		else if(s[i]=='Y')a[i]=5;
		else a[i]=6;
	}
	if(m==1){
		cout<<"Yes\n";
		return ;
	}
	vector dp(n+1,vector (n+1,vector<int>(7)));
	vector ok(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<7;k++)dp[i][j][k]=-INT_MAX;
		}
	}
	for(int i=1;i<=n;i++)dp[i][i][a[i]]=1;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i;k<j;k++){
				for(int c=0;c<7;c++){
					if(dp[i][k][c]>0&&dp[k+1][j][c]>0)dp[i][j][c]=max(dp[i][j][c],dp[i][k][c]+dp[k+1][j][c]);
					if(ok[i][k])dp[i][j][c]=max(dp[i][j][c],dp[k+1][j][c]);
					if(ok[k+1][j])dp[i][j][c]=max(dp[i][j][c],dp[i][k][c]);
				}
				for(int c=0;c<7;c++){
					if(dp[i][j][c]>=m)ok[i][j]=1;
				}
			}
		}
	}
	if(ok[1][n])cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}