#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
vector<int>g[maxn];
int ans[maxn];
int deep[maxn],d1[maxn];
void dfs(int now,int father){
	deep[now]=deep[father]+1;
	for(auto x:g[now]){
		if(x!=father)dfs(x,now);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n-1;i++){//如果k大于直径那么所有的点都是孤立的否则直径两个端点一定在一个连通块中
		//那么找其他点能否加入这个连通块
		//某个点到直径端点的距离是最远的
		//如果到端点的距离都大于k那么他就是孤立的点
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int x=max_element(deep+1,deep+1+n)-deep;
	dfs(x,0);
	int y=max_element(deep+1,deep+1+n)-deep;
	for(int i=1;i<=n;i++)d1[i]=deep[i];
	dfs(y,0);
	for(int i=1;i<=n;i++){
		ans[max(d1[i],deep[i])]++;//这些是孤立点
	}
	ans[0]=1;//算上端点的连通块
	ans[d1[y]]-=1;//减去端点的连通块
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
