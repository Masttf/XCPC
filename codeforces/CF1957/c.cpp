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
constexpr int mod=1e9+7;
constexpr int maxn=3e5+5;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
};
int f[maxn],inv[maxn];
void init(){
	f[0]=inv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
}
int C(int n,int m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		if(x==y)n--;
		else n-=2;
	}
	int ans=1;
	int last=1;
	for(int i=2;i<=n;i+=2){
		last=last*(i-1)%mod*2%mod;
		ans+=last*C(n,i)%mod;
		ans%=mod;
		//dbg(i,last);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}