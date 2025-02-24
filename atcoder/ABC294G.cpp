#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=2e5+5;
vector<int>g[maxn];
int p1[maxn],p2[maxn],t[maxn*2];
int deep[maxn];
int f[maxn][25],k=0,n;
int gg[maxn][3];
void updata(int x,int kk){
	while(x<=2*n){
		t[x]+=kk;
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int res=0;
	while(x){
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
void dfs(int now,int father){
	p1[now]=++k;//p1记录dfs序的起始位置,p2记录dfs序的末位置
	deep[now]=deep[father]+1;
	f[now][0]=father;
	for(int i=1;(1LL<<i)<deep[now];i++)f[now][i]=f[f[now][i-1]][i-1];
	for(auto x:g[now]){
		if(x!=father)dfs(x,now);
	}
	p2[now]=++k;
	return ;
}
int lca(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(deep[a]-(1LL<<i)>=deep[b])a=f[a][i];
	}
	if(a==b)return  a;
	for(int i=20;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
		gg[i][0]=u,gg[i][1]=v,gg[i][2]=w;//记录边
	}
	dfs(1,0);
	for(int i=1;i<n;i++){
		if(deep[gg[i][0]]<deep[gg[i][1]])swap(gg[i][0],gg[i][1]);//变成子节点指向父节点
		int u=gg[i][0],w=gg[i][2];
		updata(p1[u],w),updata(p2[u],-w);
	}
	int q;cin>>q;
	while(q--){
		int t,x,y;cin>>t>>x>>y;
		if(t==1){
			int u=gg[x][0];
			updata(p1[u],y-gg[x][2]);
			updata(p2[u],gg[x][2]-y);
			gg[x][2]=y;
		}else{
			cout<<query(p1[x])+query(p1[y])-2*query(p1[lca(x,y)])<<'\n';
		}
	}
	return 0;
}
