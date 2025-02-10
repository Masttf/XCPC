//首先单源最短路径起点一个，终点多个
//但是要返回即起点多个，终点一个，那么把图翻转一下又可以套用之前模板
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;
vector<pair<int ,int>>son[maxn];
vector<pair<int ,int>>son2[maxn];
bool vis[maxn];
int d[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
int n,m;
void bfs(){
	int s=1;
	d[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int>t=q.top();
		q.pop();
		if(vis[t.second])continue;
		vis[t.second]=1;
		int sz=son[t.second].size();
		for(int i=0;i<sz;i++){
			pair<int,int>y=son[t.second][i];
			if(d[y.second]>y.first+t.first){
				d[y.second]=y.first+t.first;
				q.push({d[y.second],y.second});
			}
		}
	}
	return ;
}
void bfs2(){
	int s=1;
	d[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int>t=q.top();
		q.pop();
		if(vis[t.second])continue;
		vis[t.second]=1;
		int sz=son2[t.second].size();
		for(int i=0;i<sz;i++){
			pair<int,int>y=son2[t.second][i];
			if(d[y.second]>y.first+t.first){
				d[y.second]=y.first+t.first;
				q.push({d[y.second],y.second});
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		son[u].push_back({w,v});
		son2[v].push_back({w,u});
	}
	for(int i=1;i<=n;i++)d[i]=INT_MAX;
	bfs();
	int sum=0;
	for(int i=1;i<=n;i++)sum+=d[i];
	for(int i=1;i<=n;i++)d[i]=INT_MAX,vis[i]=0;
	bfs2();
	for(int i=1;i<=n;i++)sum+=d[i];
	cout<<sum;
	return 0;
}
