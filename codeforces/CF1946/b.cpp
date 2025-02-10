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
const int mod=1e9+7;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>dp(n+1);
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1]+a[i],a[i]);
	}
	int mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,dp[i]);
	if(mx==0){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		sum%=mod;
		if(sum<0)sum+=mod;
		cout<<sum<<'\n';
	}else{
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i];
		sum%=mod;
		if(sum<0)sum+=mod;
		sum-=mx;
		sum%=mod;
		if(sum<0)sum+=mod;
		mx%=mod;
		int ans=(sum+mx*qmi(2,k)%mod)%mod;
		if(ans<0)ans+=mod;
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}