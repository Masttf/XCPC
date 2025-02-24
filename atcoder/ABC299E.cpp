#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2005;
vector<int>g[maxn];
int d[maxn][maxn];
int vis[maxn];
int n,m;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
vector<pair<int,int>>qusi;
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		d[s][i]=INT_MAX;
		vis[i]=0;
	}
	d[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int>root=q.top();
		q.pop();
		int u=root.second;
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(d[s][v]>d[s][u]+1){
				d[s][v]=d[s][u]+1;
				q.push({d[s][v],v});
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	int k;cin>>k;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=k;i++){
		int pp,dd;cin>>pp>>dd;
		for(int j=1;j<=n;j++){
			if(d[pp][j]==dd)vis[j]=1;
		}
		qusi.push_back({pp,dd});
	}
	if(k==0){
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
			if(i==1)cout<<1;
			else cout<<0;
		}
		return 0;
	}
	for(int i=0;i<k;i++){
		int pp=qusi[i].first,dd=qusi[i].second;
		for(int j=1;j<=n;j++){
			if(d[pp][j]<dd)vis[j]=0;
		}
	}
	int flag=1;
	for(int i=0;i<k;i++){
		int res=0;
		int pp=qusi[i].first,dd=qusi[i].second;
		for(int j=1;j<=n;j++){
			if(d[pp][j]==dd&&vis[j])res=1;
		}
		if(!res)flag=0;
	}
	if(flag){
		cout<<"Yes\n";
		for(int i=1;i<=n;i++)cout<<vis[i];
	}else cout<<"No";
	return 0;
}
