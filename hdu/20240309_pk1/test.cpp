#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
const int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
const int maxn=1234568;
int f[maxn],inv[maxn],p[maxn];
void init(){
	f[0]=inv[0]=1;
	f[1]=inv[1]=1;
	p[0]=1;
	p[1]=2;
	for(int i=2;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		p[i]=p[i-1]*2%mod;
	}
}
int C(int n,int m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	int N=0;
	for(int i=n;i>=1;i--){
		if(s[i]=='1')N+=1<<(n-i);
	}
	dbg(N);
	int ans=0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if((i^j)==(i|j)){
				ans++;
				//if(i>=4)dbg(i,j);
			}
		}
	}
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