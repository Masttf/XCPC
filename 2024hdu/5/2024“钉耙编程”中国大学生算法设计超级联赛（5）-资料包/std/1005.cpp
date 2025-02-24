#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+5;
struct edge{int to,nxt,idx;}edges[N<<1];
int n,head[N],cnt_edge,idx[N],dep[N],ans[N],par[N],fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void addEdge(int u,int v,int idx){
	edges[++cnt_edge]=(edge){v,head[u],idx};
	head[u]=cnt_edge;
}
#define to (edges[i].to)
void dfs(int x){
	for(int i=head[x];i;i=edges[i].nxt)if(to!=par[x]){
		dep[to]=dep[x]+1;
		idx[to]=edges[i].idx;
		par[to]=x;
		dfs(to);
	}
}
#undef to

void work(){
	cin>>n;
	cnt_edge=0;
	rep(i,1,n)fa[i]=i,head[i]=par[i]=idx[i]=0;
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v;
		addEdge(u,v,i);
		addEdge(v,u,i);
	}
	dfs(1);
	for(int d=n/2;d>=1;--d){
		int x=find(d);
		for(int j=d+d;j<=n;j+=d){
			int y=find(j);
			while(x!=y){
				if(dep[x]>dep[y])swap(x,y);
				ans[idx[y]]=d;
				fa[y]=find(par[y]);
				y=find(par[y]);
			}
		}
	}

	rep(i,1,n-2)cout<<ans[i]<<' ';
	cout<<ans[n-1]<<endl;
}
int main(){
    fastio;
    int size(256<<20);
	__asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    int tc;cin>>tc;
    while(tc--)work();
    exit(0);
}