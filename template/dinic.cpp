#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int Max=1e18;
struct node{
	int v,w;
};
void solve(){
	int n,m,s,t;cin>>n>>m>>s>>t;
	vector<node>e;
	vector g(n+1,vector<int>());
	auto add = [&](int u,int v,int w)->void{
		g[u].push_back(e.size());
		e.push_back({v,w});
		g[v].push_back(e.size());
		e.push_back({u,0});
	};
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);
	}
	vector<int>h(n+1),cur(n+1);
	auto bfs = [&]()->bool{
		h.assign(n+1,-1);
		queue<int>q;
		h[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto i:g[u]){
				auto [v,w]=e[i];
				if(h[v]==-1&&w){
					h[v]=h[u]+1;
					if(v==t){
						return true;
					}
					q.push(v);
				}
			}
		}
		return false;
	};

	auto dfs =[&](auto self,int u,int val)->int{
		if(u==t)return val;
		int res=val;
		for(auto &i=cur[u];i<(int)g[u].size();i++){
			int j=g[u][i];
			auto [v,w]=e[j];
			if(w&&h[v]==h[u]+1){
				int d=self(self,v,min(res,w));
				e[j].w-=d;
				e[j^1].w+=d;
				res-=d;
				if(res==0)return val;
			}
		}
		return val-res;
	};
	int ans=0;
	while(bfs()){
		cur.assign(n+1,0);
		ans+=dfs(dfs,s,Max);
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