//利用异或的性质拿到每个点到根节点的异或值
//两个相同异或等0所以在lca之前的点都不算
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
#define pii pair<int,int>
vector<pii>g[maxn];
int d[maxn];
bool vis[maxn];
void dfs(int x,int val){
	vis[x]=1;
	int sz=g[x].size();
	for(int i=0;i<sz;i++){
		int y=g[x][i].first;
		if(vis[y])continue;
		d[y]=val^g[x][i].second;
		dfs(y,d[y]);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0);
	int m;cin>>m;
	while(m--){
		int a,b;cin>>a>>b;
		cout<<(d[a]^d[b])<<'\n';
	}
	return 0;
}
