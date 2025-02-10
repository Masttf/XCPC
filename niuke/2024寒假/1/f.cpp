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
const int maxn=1e5+5;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
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
	int n,m;cin>>n>>m;
	if(n<m){
		cout<<0<<'\n';
		return ;
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		ans=(ans+qmi(-1,m-i)*qmi(i,n)%mod*inv[i]%mod*inv[m-i]%mod)%mod;
	}
	ans%=mod;
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}