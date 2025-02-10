#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int f[maxn],g[maxn];
bool vis[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector<int>res[maxn];
vector<int>ans;
bool unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return false;
	f[fa]=fb;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int u,v;
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=1;i<=m;i++){//建图
		cin>>u>>v;
		res[u].push_back(v);
		res[v].push_back(u);
	}
	int k;cin>>k;
	for(int i=1;i<=k;i++)cin>>g[i],vis[g[i]]=1;//看那些星球被破坏
	for(int i=0;i<n;i++){//初始的星球的连通块
		if(vis[i])continue;
		int sz=res[i].size();
		for(int j=0;j<sz;j++){
			if(vis[res[i][j]])continue;
			unit(i,res[i][j]);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		if(find(i)==i)cnt++;
	}
	ans.push_back(cnt);
	while(k){
		vis[g[k]]=0;
		int sz=res[g[k]].size();
		cnt++;//建星球
		for(int j=0;j<sz;j++){
			if(vis[res[g[k]][j]])continue;
			if(unit(g[k],res[g[k]][j]))cnt--;//如果相连说明连通块减1
		}
		ans.push_back(cnt);
		k--;
	}
	int l=ans.size();
	for(int i=l-1;i>=0;i--)cout<<ans[i]<<'\n';
	return 0;
}
