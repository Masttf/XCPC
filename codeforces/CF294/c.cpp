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
const int maxn=1005;
int f[maxn],inv[maxn];
void init(){
	f[0]=1;
	inv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
	return ;
}
int c(int n,int m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	int len=n-m;
	int res=1;
	//dbg("yes");
	for(int i=2;i<=m;i++){
		int l=a[i]-a[i-1]-1;
		if(l<=0)continue;
		res=res*c(len,l)%mod*qmi(2,l-1)%mod;
		len-=l;
		//dbg(i);
	}
	res=res*c(len,a[1]-1)%mod;

	cout<<res<<'\n';
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