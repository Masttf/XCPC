#include<bits/stdc++.h>//树上差分dfs序实现
//两点之间的最短路上的所有点都加1，等价于a到根节点所有的点加1，b到根节点所有加1
//lca（a，b）-1，公共祖先的父节点-1，，这个相当于于前缀从底到上
//如何查询这个节点加了多少次等于它子节点的和
//很显然只有它的子节点才会使它增加
//为什么树上差分是逆向的，因为dfs只有在后序位置才能得到子树的信息
//为什么没有在ed位置进行修改，因为这个点的作用范围只在子树的区间内，没有跨区间操作
//而树上前缀和，需要的是根节点到该点的距离，需要跨区间所以需要在ed位置消除影响
#define int long long
using namespace std;
const int maxn=1e5+5;
vector<pair<int,int>>g[maxn];
int f[maxn][25],deep[maxn],st[maxn],ed[maxn],idx,t[maxn<<1],id[maxn];
void dfs(int now,int father){
	deep[now]=deep[father]+1;
	st[now]=++idx;
	f[now][0]=father;
	for(int i=1;i<=deep[now];i++)f[now][i]=f[f[now][i-1]][i-1];
	for(auto x:g[now]){
		int v=x.first;
		int d=x.second;
		if(v!=father){
			dfs(v,now);
			id[v]=d;
		}
	}
	ed[now]=++idx;
	return ;
}
int lca(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(deep[a]-(1LL<<i)>=deep[b])a=f[a][i];
	}
	if(a==b)return a;
	for(int i=20;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i],b=f[b][i];
		}
	}
	return f[a][0];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		int fa=lca(a,b);
		//cout<<fa<<'\n';
		int pa=f[fa][0];
		t[st[a]]++;
		t[st[b]]++;
		t[st[fa]]--;
		t[st[pa]]--;
	}
	for(int i=1;i<=2*n;i++)t[i]+=t[i-1];
	int ans=-1;
	for(int i=1;i<=n;i++){
		//cout<<t[ed[i]]-t[st[i]-1]<<'\n';
		if(t[ed[i]]-t[st[i]-1]==m)ans=max(ans,id[i]);
	}
	cout<<ans;
	return 0;
}
/*
6 2
1 2
2 3
4 3
2 5
6 5
3 6
4 5

4
 */
