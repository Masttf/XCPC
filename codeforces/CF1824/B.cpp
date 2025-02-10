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
const int maxn=2e5+5;
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
	return ;
}
int C(int n,int m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
	int n,k;cin>>n>>k;
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k%2==1){
		cout<<1<<'\n';
		return ;
	}
	int ans=0;
	int tot=C(n,k);
	vector<int>sz(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		sz[now]=1;
		int cnt=0;
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			sz[now]+=sz[v];
			if(sz[v]>=k)cnt+=C(sz[v],k);
		}
		if(n-sz[now]>=k)cnt+=C(n-sz[now],k);
		ans+=tot-cnt;
		ans%=mod;
	};
	dfs(dfs,1,0);
	ans=ans*qmi(tot,mod-2)%mod;
	if(ans<0)ans+=mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}