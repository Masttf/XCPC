#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
constexpr int mod=998244353;
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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>b(m+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=m;i++)cin>>b[i];
	vector<int>f(n+1),inv(n+1);
	f[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
	vector<int>t(mx+1);
	auto add = [&](int x,int val)->void{
		while(x<=mx){
			t[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		add(a[i],1);
	}
	int ans=0;
	int ok=1;
	int last=1;
	for(int i=1;i<=min(m,n);i++){
		int d=ask(b[i]-1);
		int t=ask(b[i])-d;
		ans+=last*d%mod*f[n-i]%mod;
		ans%=mod;
		last*=t;
		last%=mod;
		if(t==0){
			ok=0;
			break;
		}
		add(b[i],-1);
	}
	vector<int>cnt(mx+1);
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	for(int i=1;i<=mx;i++){
		ans=ans*inv[cnt[i]]%mod;
	}
	if(n<m&&ok)ans++;
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