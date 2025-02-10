#include<bits/stdc++.h>
//#define int long long
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
constexpr int N=505;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<bitset<N*N>> dp(n);
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		dp[i]|=dp[i-1];
		for(int j=1;j<i;j++){
			dp[i]|=dp[i-1]<<(a[i]-a[j]);
		}
		for(int j=0;j<=10;j++){
			dbg(i,j,dp[i][j]);
		}
	}
	for(int i=0;i<=499*n;i++){
		if(dp[n-1][i])cout<<i<<' ';
	}
	cout<<'\n';  
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}