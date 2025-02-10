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
	int n,d;cin>>n>>d;
	vector<int>a(n);
	double sum=0;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	sum/=d;
	//dbg(sum);
	int len=1<<n;
	vector dp(d+1,vector<double>(len,LONG_LONG_MAX));
	for(int i=0;i<len;i++){
		dp[1][i]=0;
		for(int j=0;j<n;j++){
			if(i>>j&1){
				dp[1][i]+=a[j];
			}
		}
		dp[1][i]=(dp[1][i]-sum)*(dp[1][i]-sum);
	}
	for(int i=2;i<=d;i++){
		for(int s=1;s<len;s++){
			for(int k=s;k>0;k--){
				int res=k&s;
				dp[i][s]=min(dp[i][s],dp[i-1][s-res]+dp[1][res]);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<dp[d][len-1]/d<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}