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
void solve(){
	int n,p;cin>>n>>p;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	vector<int>dp(n+1,Max);
	dp[1]=p;
	for(int i=1;i<=n;i++){
		dp[i]=min(dp[i-1]+p,dp[i]);
		for(int j=1;j<=n;j++){
			dp[min(n,j+b[i])]=min(dp[min(n,j+b[i])],dp[j]+a[i]);
		}
	}
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}