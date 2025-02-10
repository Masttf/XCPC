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
const int maxn=5005;
int dp[maxn],a[maxn],dp2[maxn],sum[maxn],sum2[maxn];
bool vis[maxn],vis2[maxn];
void solve(){
	int n,k,mod;cin>>n>>k>>mod;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]%=mod;
	long long ans=0;
	for(int i=n;i>=1;i--){
		for(int j=0;j<k;j++){
			dp2[j]=dp[j];
			sum2[j]=sum[j];
			vis2[j]=vis[j];
			dp[j]=sum[j]=0;
			vis[j]=0;
		}
		dp[a[i]%k]=a[i]/k;
		sum[a[i]%k]=a[i];
		vis[a[i]%k]=1;
		for(int j=0;j<k;j++){
			if(!vis2[j])continue;
			int d1=(sum2[j]+mod-a[i+1]+a[i])%mod;
			int d2=(sum2[j]+a[i])%mod;
			//dbg(i,j,d1,d2);
			dbg(i,j,sum2[j]);
			dp[d1%k]=(dp[d1%k]+d1/k)%mod;
			dp[d2%k]=(dp[d2%k]+d2/k)%mod;
			sum[d1%k]=(sum[d1%k]+d1)%mod;
			sum[d2%k]=(sum[d2%k]+d2)%mod;
			vis[d1%k]=1;
			vis[d2%k]=1;
		}
		for(int j=0;j<k;j++){
			ans=(ans+dp[j])%mod;
			//dbg(i,j,dp[j]);
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