#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e4+5;
vector<pair<int,int>>g[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	int l=0,r=0;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		r=max(r,w);
	}
	auto check = [&](int k)->bool{
		vector<int>vis(n+1);
		bool ok=1;
		auto dfs = [&](auto dfs,int now,int c)->void{
			vis[now]=c;
			for(auto &[v,w]:g[now]){
				if(w>k){
					if(!vis[v])dfs(dfs,v,3-c);
					else if(vis[v]==c)ok=0;
				}
			}
			return ;
		};
		for(int i=1;i<=n;i++){
			if(!vis[i])dfs(dfs,i,1);
		}
		return ok;
	};
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<'\n';
	return 0;
}
