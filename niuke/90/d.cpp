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
const int mod=998244353;
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i].first>>a[i].second;
	int ans=0;
	vector<int>val(n+5);
	auto dfs = [&](auto self,int now)->void{
		if(now==m+1){
			int ok=1;
			int x=0;
			for(int i=1;i<=n;i++){
				x+=val[i];
				if(x<2){
					ok=0;
					break;
				}
			}
			if(ok)ans++;
			return ;
		}
		self(self,now+1);
		val[a[now].first]++;
		val[a[now].second+1]--;
		self(self,now+1);
		val[a[now].first]--;
		val[a[now].second+1]++;
	};
	dfs(dfs,1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}