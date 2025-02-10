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
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	sort(a.begin()+1,a.end());

	vector g(n+1,vector<pair<int,int>>());
	for(int i=2;i<=n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>val(n+1),f(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			f[v]=now;
			val[v]=w;
			self(self,v,now);
		}
	};
	dfs(dfs,1,0);

	vector<int>res(n+1);
	vector cnt(n+1,vector<int>(n+1));
	vector l(n+1,vector<int>(n+1));
	
	for(int i=1;i<=n;i++){
		int x=a[i].second;
		int now=0;
		int ans=0;
		while(x!=1){
			
			x=f[x];
		}
		res[a[i].second]=ans;
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}