#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<vector<int>>g(n+1);
	vector<int>mk(n+1);
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		mk[x]=1;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=n;
	vector<int>mx1(n+1,-1),mx2(n+1,-1);
	auto dfs = [&](auto dfs,int now,int father)->void{
		if(mk[now])mx1[now]=mx2[now]=0;
		for(auto v:g[now]){
			if(v==father)continue;
			dfs(dfs,v,now);
			if(mx1[v]!=-1){
				if(mx1[v]+1>mx1[now]){
					mx2[now]=max(mx2[now],mx1[now]);
					mx1[now]=mx1[v]+1;
				}else if(mx1[v]+1>mx2[now]){
					mx2[now]=mx1[v]+1;
				}
			}
		}
		//cout<<now<<' '<<mx1[now]<<' '<<mx2[now]<<endl;
	};
	dfs(dfs,1,0);

	//for(int i=1;i<=n;i++)cout<<mx1[i]<<' '<<mx2[i]<<endl;
	ans=min(ans,mx1[1]);
	//cout<<mx1[1]<<' '<<mx2[1]<<endl;
	auto dfs2 = [&](auto dfs2,int now,int father)->void{
		for(auto v:g[now]){
			if(v==father)continue;
			if(mx1[v]==-1){
				mx1[v]=mx1[now]+1;
			}else{
				if(mx1[now]==mx2[now]||mx1[now]!=mx1[v]+1){
					if(mx1[now]+1>mx1[v]){
						mx2[v]=max(mx2[v],mx1[v]);
						mx1[v]=mx1[now]+1;
					}else if(mx1[now]+1>mx2[v]){
						mx2[v]=mx1[now]+1;
					}
				}else{
					if(mx2[now]!=-1){
						if(mx2[now]+1>mx1[v]){
							mx2[v]=max(mx2[v],mx1[v]);
							mx1[v]=mx2[now]+1;
						}else if(mx2[now]+1>mx2[v]){
							mx2[v]=mx2[now]+1;
						}
					}
				}
			}
			
			//cout<<v<<' '<<mx1[v]<<' '<<mx2[v]<<endl;
			ans=min(ans,mx1[v]);
			dfs2(dfs2,v,now);
		}
	};
	dfs2(dfs2,1,0);

	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}