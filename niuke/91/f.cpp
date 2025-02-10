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
constexpr int mod=1e9+7;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector pre1(25,vector<int>(n+1));
	vector pre0(25,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<25;j++){
			pre1[j][i]=pre1[j][i-1];
			pre0[j][i]=pre0[j][i-1];
		}
		for(int j=0;j<25;j++){
			if(a[i]>>j&1)pre1[j][i]+=i;
			else pre0[j][i]+=i;
		}
	}
	vector suf1(25,vector<int>(n+5));
	vector suf0(25,vector<int>(n+5));
	for(int i=n;i>=1;i--){
		for(int j=0;j<25;j++){
			suf1[j][i]=suf1[j][i+1];
			suf0[j][i]=suf0[j][i+1];
		}
		for(int j=0;j<25;j++){
			if(a[i]>>j&1)suf1[j][i]+=n-i+1;
			else suf0[j][i]+=n-i+1;
		}
	}
	int ans=0;
	for(int k=0;k<25;k++){
		for(int i=1;i<=n;i++){
			if(a[i]>>k&1){
				ans+=(1ll<<k)*pre0[k][i]%mod*(n-i+1)%mod;
				ans%=mod;
				ans+=(1ll<<k)*suf0[k][i]%mod*i%mod;
				ans%=mod;
			}else{
				ans+=(1ll<<k)*pre1[k][i]%mod*(n-i+1)%mod;
				ans%=mod;
				ans+=(1ll<<k)*suf1[k][i]%mod*i%mod;
				ans%=mod;
			}
		}
	}
	ans%=mod;
	if(ans<0)ans+=mod;
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