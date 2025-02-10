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
const int mod=1e9+7;
long long qmi(int a,int b){
	long long res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n;cin>>n;
	vector<int>a(n+1),p(n+1),dfn(n+1),low(n+1),f(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	vector<int>stk;
	int tot=0,cnt=0;
	long long ans=0;
	auto tarjan = [&](auto self,int now)->void{
		//dbg(now);
		dfn[now]=low[now]=++tot;
		stk.push_back(now);
		if(!dfn[a[now]]){
			self(self,a[now]);
			low[now]=min(low[now],low[a[now]]);
		}else if(!f[a[now]])low[now]=min(low[now],dfn[a[now]]);
		if(dfn[now]==low[now]){
			int y;
			cnt++;
			long long pp=1;
			long long res=0;
			int sz=0;
			do{
				y=stk.back();
				sz++;
				stk.pop_back();
				f[y]=cnt;
				pp=pp*(mod-p[y]+1)%mod;
				res=(res+(mod-p[y]+1))%mod;
			}while(y!=now);
			ans=(ans+res-(sz-1)*pp%mod)%mod;
			if(ans<0){
				ans+=mod;
			}
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i);
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