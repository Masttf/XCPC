#include<bits/stdc++.h>
#define int long long
using namespace std;
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
	vector<int>pre(n+1);
	auto bfs = [&]()->int{
		pre=vector<int>(n+1);
		vector<int>mx(n+1);
		mx[s]=INT_MAX;
		queue<pair<int,int>>q;
		q.push({s,mx[s]});
		while(!q.empty()){
			auto &[u,ww]=q.front();
			q.pop();
			for(auto i :g[u]){
				int v=e[i].v;
				int w=e[i].w;
				if(!mx[v]&&w){
					pre[v]=i;
					mx[v]=min(w,ww);
					q.push({v,mx[v]});
				}
			}
		}
		return mx[t];
	};
	int ans=0;
	int d;
	while(d=bfs()){
		ans+=d;
		for(int i=t;i!=s;i=e[pre[i]^1].v){
			e[pre[i]].w-=d;
			e[pre[i]^1].w+=d;
		}
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