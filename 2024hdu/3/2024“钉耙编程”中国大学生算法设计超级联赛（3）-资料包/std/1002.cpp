#include<bits/stdc++.h>
#define N 200009
using namespace std;
typedef long long ll;
int head[N],tot,c[N],v[N];
int L[N*32],R[N*32];
ll tr[N*32],la[N*32];
int top,n,T[N]; 
ll dp[N],sm;
int vi[N];
struct edge{
	int n,to;
}e[N<<1];
inline void add(int u,int v){
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot;
}
void pushd(int u){
	if(L[u])tr[L[u]]+=la[u],la[L[u]]+=la[u];
	if(R[u])tr[R[u]]+=la[u],la[R[u]]+=la[u];
	la[u]=0;
}
int merge(int u,int v,int l,int r,ll &ans){
	if(!u||!v)return u+v;
	if(l==r)ans=max(ans,tr[u]+tr[v]+sm);
	pushd(u);
	pushd(v);
	int mid=(l+r)>>1;
	tr[u]=max(tr[u],tr[v]);
	L[u]=merge(L[u],L[v],l,mid,ans);
	R[u]=merge(R[u],R[v],mid+1,r,ans);
	return u;
}
void upd(int &u,int l,int r,int x,ll y){
	if(!u)u=++top;
	tr[u]=y;
	if(l==r)return;
	int mid=(l+r)>>1; 
	if(x<=mid)upd(L[u],l,mid,x,y);
	else upd(R[u],mid+1,r,x,y);
}
void dfs(int u,int fa){
	ll sum=0;
	vi[u]=1;
	for(int i=head[u];i;i=e[i].n)if(e[i].to!=fa){	
		int v=e[i].to;
		dfs(v,u);
		sum+=dp[v];
	}
	dp[u]=sum;
	sm=sum;
	upd(T[u],1,n,c[u],v[u]);
	for(int i=head[u];i;i=e[i].n)if(e[i].to!=fa){	
		int v=e[i].to;
		tr[T[v]]-=dp[v];
		la[T[v]]-=dp[v];
		T[u]=merge(T[u],T[v],1,n,dp[u]);
	}
	tr[T[u]]+=sm;
	la[T[u]]+=sm;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int TT;
	cin>>TT;
	while(TT--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>c[i];
		}
		for(int i=1;i<=n;++i){
			cin>>v[i];
		}
		int u,v;
		for(int i=1;i<n;++i){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		
	   	dfs(1,0);
	    cout<<dp[1]<<endl;
	    for(int i=0;i<=top;++i){
	    	L[i]=R[i]=tr[i]=la[i]=0;
	    }
		tot=top=0;
		for(int i=0;i<=n;++i){
			head[i]=T[i]=dp[i]=0;
		}
	}
	return 0;
}

