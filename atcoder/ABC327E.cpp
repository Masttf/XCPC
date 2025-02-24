#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	vector<double>res(n+1);
	vector<double>temp(n+1);
	for(int i=1;i<=n;i++){
		res[i]=(double)(1200/sqrt(i));
		temp[i]=temp[i-1]*0.9+1;
		//dbg(res[i]);
	}
	vector dp(n+1,vector<double>(n+1));
	dp[1][1]=a[1];
	double ans=dp[1][1]-1200;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)dp[i][j]=dp[i-1][j];
		for(int j=1;j<i;j++){
			dp[i][j]=max(dp[i-1][j-1]*0.9+a[i],dp[i][j]);
			ans=max(ans,dp[i][j]/temp[j]-res[j]);
		}
		dp[i][i]=dp[i-1][i-1]*0.9+a[i];
		ans=max(ans,dp[i][i]/temp[i]-res[i]);
	}
	cout<<fixed<<setprecision(10)<<ans;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}