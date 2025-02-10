#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
const int Max=1e18;
const int maxn=2e5+5;
int dp[maxn][2][2];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i][1][1]=Max;
		dp[i][1][0]=Max;
		dp[i][0][1]=Max;
		dp[i][0][0]=Max;
	}
	dp[1][1][0]=a[1];
	dp[1][0][0]=0;
	for(int i=2;i<=n;i++){
		if(s[i]==s[i-1]){
			dp[i][0][1]=min(dp[i-1][0][0],dp[i-1][1][1]);
			dp[i][0][0]=dp[i-1][1][0];
			dp[i][1][0]=dp[i-1][0][0]+a[i];
			dp[i][1][1]=min(dp[i-1][1][0],dp[i-1][0][1])+a[i];
		}else{
			dp[i][0][1]=min(dp[i-1][1][0],dp[i-1][0][1]);
			dp[i][0][0]=dp[i-1][0][0];
			dp[i][1][0]=dp[i-1][1][0]+a[i];
			dp[i][1][1]=min(dp[i-1][0][0],dp[i-1][1][1])+a[i];
		}
	}
	int ans=min(dp[n][1][1],dp[n][0][1]);
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