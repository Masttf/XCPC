#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int dp[maxn][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int x,y,z;cin>>x>>y>>z;
	string s;cin>>s;
	int len=s.size();
	s=' '+s;
	dp[0][1]=z;
	for(int i=1;i<=len;i++){
		if(s[i]=='a'){
			dp[i][0]=min({dp[i-1][0]+x,dp[i-1][1]+y+z,dp[i-1][1]+z+x});
			dp[i][1]=min({dp[i-1][0]+x+z,dp[i-1][1]+y,dp[i-1][1]+z+x+z});
		}else{
			dp[i][1]=min({dp[i-1][1]+x,dp[i-1][0]+y+z,dp[i-1][0]+z+x});
			dp[i][0]=min({dp[i-1][1]+x+z,dp[i-1][0]+y,dp[i-1][0]+z+x+z});
		}
	}
	cout<<min(dp[len][0],dp[len][1]);
	return 0;
}
