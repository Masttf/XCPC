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
void solve(){
	int n;cin>>n;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector dp(1ll<<n,vector<int>(n));
	int ans=0;
	for(int i=0;i<n;i++){
		dp[1ll<<i][i]=a[i].size();
		ans=max(ans,dp[1ll<<i][i]);
	}
	for(int i=1;i<(1ll<<n);i++){
		for(int j=0;j<n;j++){
			if(i>>j&1){
				for(int k=0;k<n;k++){
					if((i^(1ll<<j))>>k&1&&a[j][0]==a[k].back()){
						dp[i][j]=max(dp[i][j],dp[i^(1ll<<j)][k]+(int)a[j].size());
						ans=max(ans,dp[i][j]);
					}
				}
			}
		}
	}
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