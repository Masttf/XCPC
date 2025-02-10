#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
vector<int>g[maxn];
int sz[maxn];
void dfs(int now,int father){
	int flag=1;
	for(auto v:g[now]){
		if(v==father)continue;
		flag=0;
		dfs(v,now);
		sz[now]+=sz[v];
	}
	if(flag)sz[now]=1;
	return ;
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)g[i].clear(),sz[i]=0;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<sz[x]*sz[y]<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
