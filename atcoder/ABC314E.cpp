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
void err(T arg, Ts ... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>c(n+1);
	
	vector s(n+1,vector<int>());
	for(int i=1;i<=n;i++){
		cin>>c[i];
		int k;cin>>k;
		s[i]=vector<int>(k+1);
		for(int j=1;j<=k;j++)cin>>s[i][j];
	}
	
	vector<double>dp(m+1,INT_MAX);
	dp[0]=0;
	for(int i=0;i<=m;i++){
		for(int j=1;j<=n;j++){
			double d=0;
			int p=s[j].size()-1;
			int cnt=0;
			for(int k=1;k<=p;k++){
				if(s[j][k]==0)cnt++;
				else d+=dp[max(0ll,i-s[j][k])];
			}
			d/=(p-cnt);
			d+=c[j]*p*1.0/(p-cnt);
			dp[i]=min(dp[i],d);

		}
		//cout<<i<<' '<<dp[m]<<'\n';
	}
	cout<<fixed<<setprecision(10)<<dp[m]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}