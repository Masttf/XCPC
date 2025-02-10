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
constexpr int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>suf(n+5);
	vector<int>len(n+5);
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]+a[i];
		suf[i]%=mod;
		int temp=a[i];
		int res=1;
		while(temp){
			res*=10;
			temp/=10;
		}
		len[i]=len[i+1]+res;
		len[i]%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=(suf[i+1]+a[i]*len[i+1]%mod)%mod;
		ans%=mod;
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