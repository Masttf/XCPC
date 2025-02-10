//首先lca需要有深度所以应该先dfs一遍
//然后初始化每个节点的二进制的祖先节点
//然后把两个节点设为同高，注意浅的节点可能是深的节点的父亲节点
//然后一起跳逐步逼近
#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
vector<int>tree[maxn];
int f[maxn][25],deep[maxn];
void dfs(int x,int father){
	deep[x]=deep[father]+1;
	f[x][0]=father;
	for(int i=1;(1<<i)<=deep[x];i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	int sz=tree[x].size();
	for(int i=0;i<sz;i++){
		if(tree[x][i]!=father){
			dfs(tree[x][i],x);
		}
	}
	return ;
}
int lca(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(deep[a]-(1<<i)>=deep[b]){
			a=f[a][i];
		}
	}
	if(a==b)return b;
	for(int i=20;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i],b=f[b][i];
		}
	}
	return f[a][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,s,m;cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(s,0);
	while(m--){
		int a,b;cin>>a>>b;
		cout<<lca(a,b)<<'\n';
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
vector<pair<int,int>>h[maxn];
vector<int>tree[maxn];
int f[maxn],ans[maxn];
bool vis[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs(int x){
	vis[x]=1;
	int sz=tree[x].size();
	for(int i=0;i<sz;i++){
		int y=tree[x][i];
		if(!vis[y]){
			dfs(y);
			f[y]=x;
		}
	}
	int l=h[x].size();
	for(int i=0;i<l;i++){
		int y=h[x][i].first;
		if(vis[y]){
			ans[h[x][i].second]=find(y);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,s;cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		f[i]=i;
		int x,y;cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	f[n]=n;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		h[x].push_back({y,i});
		h[y].push_back({x,i});
	}
	dfs(s);
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
 */
