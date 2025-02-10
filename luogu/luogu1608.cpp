#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2005;
int g[maxn][maxn];
int d[maxn];
int cnt[maxn];
bool vis[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>>q;
int n,m;
void dijkstra(){
	for(int i=1;i<=n;i++)d[i]=INT_MAX;
	d[1]=0;
	cnt[1]=1;
	q.push({0,1});
	while(!q.empty()){
		pair<int,int>root=q.top();
		q.pop();
		int u=root.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			int w=g[u][v];
			if(vis[v]||w==INT_MAX)continue;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				cnt[v]=cnt[u];
				q.push({d[v],v});
				//cout<<u<<' '<<v<<' '<<d[v]<<' '<<cnt[v]<<'\n';
			}else if(d[v]==d[u]+w){
				cnt[v]+=cnt[u];
				//cout<<u<<' '<<v<<' '<<cnt[v]<<'\n';
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			g[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
	}
	dijkstra();
	if(d[n]==INT_MAX)cout<<"No answer";
	else cout<<d[n]<<' '<<cnt[n];
	//cout<<cnt[6]<<' '<<cnt[7];
	return 0;
}
/*
  5 5
  1 2 1
  1 4 2
  2 3 1
  3 5 2
  4 5 2
  
 */
