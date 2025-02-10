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
	int n,m;cin>>n>>m;
	vector a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	if(n<=2&&m<=2){
		 cout<<-1<<'\n';
		 return ;
	}
	vector<int>val1(m+1),val2(m+1);
	for(int i=1;i<=m;i++){
		val2[i]=a[1][i]+a[n][i];
		for(int j=1;j<=n;j++)val1[i]+=a[j][i];
	}
	vector dp(m+1,vector<int>(5,-Max));
	dp[0][0]=0;
	for(int i=1;i<=m;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=max(dp[i-1][0],dp[i-1][1])+val1[i];
		dp[i][2]=max(dp[i-1][1],dp[i-1][2])+val2[i];
		dp[i][3]=max(dp[i-1][2],dp[i-1][3])+val1[i];
		dp[i][4]=max(dp[i-1][3],dp[i-1][4]);
	}
	cout<<max(dp[m][4],dp[m][3])<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}