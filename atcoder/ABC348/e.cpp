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
void solve(){
	int n;cin>>n;
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>c(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)cin>>c[i],sum+=c[i];
	vector<int>sz(n+1);
	vector<int>dep(n+1);
	int ans=0;
	auto dfs = [&](auto self,int now,int father)->void{
		sz[now]=c[now];
		dep[now]=dep[father]+1;
		ans+=(dep[now]-1)*c[now];
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			sz[now]+=sz[v];
		}
	};
	dfs(dfs,1,0);
	vector<int>val(n+1);
	val[1]=ans;
	auto dfs2 =[&](auto self,int now,int father)->void{
		for(auto v:g[now]){
			if(v==father)continue;
			int d=sum-sz[v];
			val[v]=val[now]+d-sz[v];
			self(self,v,now);
		}
	};
	dfs2(dfs2,1,0);
	for(int i=1;i<=n;i++)ans=min(ans,val[i]);
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