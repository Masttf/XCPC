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
	int n,l;cin>>n>>l;
	n*=2;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<double>x(n+1),y(n+1);
	double pi=acos(-1.0);
	for(int i=1;i<=n;i++){
		x[i]=cos(a[i]*pi/(2.0*l));
		y[i]=sin(a[i]*pi/(2.0*l));
	}
	auto get = [&](int i,int j)->double{
		return (x[i]*y[j]-x[j]*y[i])*0.5;
	};
	vector dp(n+5,vector<double>(n+5,Max));
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		dp[i][i-1]=0;
		dp[i+1][i]=0;
	}
	for(int len=2;len<=n;len+=2){
		for(int i=1;i+len-1<=n;i++){
			int l=i,r=i+len-1;
			dp[l][r]=dp[l+1][r-1]+get(l,r);
			for(int j=i+1;j<=r;j+=2){
				dp[l][r]=min(dp[l][r],dp[l][j]+dp[j+1][r]);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<dp[1][n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}