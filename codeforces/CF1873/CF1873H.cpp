#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,a,b;cin>>n>>a>>b;
	vector<vector<int>>g(n+1,vector<int>());
	vector<int>vis(n+1);
	vector<int>deep(n+1);
	for(int i=1;i<=n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)p[i]=i;
	int st=-1,ed=-1;
	auto dfs = [&](auto dfs,int now,int father)->void{
		vis[now]=1;
		p[now]=father;
		for(auto v:g[now]){
			if(v==father)continue;
			if(vis[v]){
				if(st!=-1)continue;
				st=now;
				ed=v;
			}else dfs(dfs,v,now);
		}
	};
	auto bfs = [&](int s)->void{
		deep[s]=1;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int root=q.front();
			q.pop();
			for(auto v:g[root]){
				if(!deep[v]){
					q.push(v);
					deep[v]=deep[root]+1;
				}
			}
		}
	};
	int res=-1;
	auto get = [&](auto get,int x)->void{
		if(res==-1||deep[x]<deep[res])res=x;
		if(x==ed)return ;
		else get(get,p[x]);
		return ;
	};
	dfs(dfs,b,0);
	bfs(b);
	get(get,st);
	int mi=deep[res]-deep[b]+1;
	for(int i=1;i<=n;i++)deep[i]=0;
	bfs(a);
	int d=deep[res]-deep[a]+1;
	//cout<<res<<' '<<mi<<' '<<d<<'\n';
	if(d<=mi)cout<<"NO\n";
	else cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
