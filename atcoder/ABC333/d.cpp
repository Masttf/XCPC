#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector g(n+1,vector<int>());
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>sz(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		sz[now]=1;
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			sz[now]+=sz[v];
		}
	};
	dfs(dfs,1,0);
	int ans=sz[1];
	for(auto v:g[1]){
		ans=min(sz[1]-sz[v],ans);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}