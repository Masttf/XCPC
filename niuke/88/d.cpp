#include<bits/stdc++.h>
//#define int long long
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
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i],a[i]%=n;
	vector dp(m+1,vector<int>(n));
	dp[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			int d=(j+a[i])%n;
			dp[i][d]|=dp[i-1][j];
			d=(j-a[i]+n)%n;
			dp[i][d]|=dp[i-1][j];
		}
	}
	if(dp[m][0])cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}