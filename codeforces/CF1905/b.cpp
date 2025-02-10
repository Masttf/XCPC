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
	int cnt=0;
	vector<int>dep(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		dep[now]=dep[father]+1;
		if(g[now].size()==1)cnt++;
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
	};
	dfs(dfs,1,0);
	//int d=*max(dep.begin()+1,dep.end());
	int ans=(cnt-1)/2+1;
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