#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max=1e18;
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='y')s[i]='0';
		else s[i]='1';
	}
	vector dp(n+1,vector<int>(5,Max));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			dp[i][0]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=dp[i-1][3];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
			dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
		}else{
			dp[i][0]=min(dp[i-1][0],dp[i-1][2])+1;
			dp[i][2]=dp[i-1][3]+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][3]=min(dp[i-1][1],dp[i-1][3]);
		}
	}
	int ans=Max;
	for(int i=0;i<=3;i++)ans=min(ans,dp[n][i]);
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