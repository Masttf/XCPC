#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>g(n+1,vector<int>());
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>sz(n+1);
	vector<int>sum(n+1);
	auto dfs = [&](auto dfs,int now,int father)->void{
		int k=a[father]^a[now];
		sz[now]=1;
		for(auto v:g[now]){
			if(v==father)continue;
			dfs(dfs,v,now);
			sz[now]+=sz[v];
		}
		sum[1]+=k*sz[now];
	};
	dfs(dfs,1,0);
	auto get = [&](auto get,int now,int father)->void{
		for(auto v:g[now]){
			if(v==father)continue;
			sum[v]=sum[now]-n*a[now]-sz[v]*(a[now]^a[v])+n*a[v]+(n-sz[v])*(a[now]^a[v]);
			get(get,v,now);
		}
	};
	get(get,1,0);
	for(int i=1;i<=n;i++)cout<<sum[i]-n*a[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
