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
	int n;cin>>n;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	vector<int>pa(n+1),pb(n+1);
	for(int i=1;i<=n;i++){
		pa[i]=pa[i-1]+a[i];
		pb[i]=pb[i-1]+b[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=(n-1)*a[i]*a[i];
		ans+=(n-1)*b[i]*b[i];
	}
	int mx=pa[n]+pb[n];
	vector dp(n+1,vector<int>(mx+5,Max));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int sum=pa[i]+pb[i];
		for(int j=0;j<=mx;j++){
			int d=sum-j;
			if(j-a[i]>=0&&d-b[i]>=0)dp[i][j]=min(dp[i][j],dp[i-1][j-a[i]]+(j-a[i])*a[i]+(d-b[i])*b[i]);
			if(j-b[i]>=0&&d-a[i]>=0)dp[i][j]=min(dp[i][j],dp[i-1][j-b[i]]+(j-b[i])*b[i]+(d-a[i])*a[i]);
		}
	}
	int mi=Max;
	for(int i=0;i<=mx;i++)mi=min(dp[n][i],mi);
	ans+=2*mi;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}