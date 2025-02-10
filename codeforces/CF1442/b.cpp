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
const int Max=1e18;
const int mod=998244353;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	vector<int>s(n+1);
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)p[a[i]]=i;
	for(int i=1;i<=m;i++)s[b[i]]=i;
	int ans=1;
	for(int i=1;i<=m;i++){
		int pp=p[b[i]];
		int pre=pp-1;
		int suf=pp+1;
		int d=0;
		if(pre!=0&&s[a[pre]]<i){
			d++;
		}
		if(suf!=n+1&&s[a[suf]]<i){
			d++;
		}
		ans=ans*d%mod;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}