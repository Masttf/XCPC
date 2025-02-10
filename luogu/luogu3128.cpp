//树上差分从利用后缀位置遍历即可
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
vector<int>tree[maxn];
int deep[maxn],f[maxn][30],d[maxn];
void dfs(int x,int father){
	deep[x]=deep[father]+1;
	f[x][0]=father;
	for(int i=1;(1<<i)<=deep[x];i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(auto a:tree[x]){
		if(a!=father)dfs(a,x);
	}
	return ;
}
int lca(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	for(int i=19;i>=0;i--){
		if(deep[a]-(1<<i)>=deep[b]){
			a=f[a][i];
		}
	}
	if(a==b)return b;
	for(int i=19;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}
int ans=0;
void dfs2(int s,int father){
	for(auto a:tree[s]){
		if(a!=father){
			dfs2(a,s);
			d[s]+=d[a];
		}
	}
	ans=max(ans,d[s]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1,0);
	while(m--){
		int x,y;cin>>x>>y;
		int e=lca(x,y);
		d[x]++,d[y]++,d[e[f][0]]--,d[e]--;
	}
	dfs2(1,0);
	cout<<ans;
	return 0;
}
