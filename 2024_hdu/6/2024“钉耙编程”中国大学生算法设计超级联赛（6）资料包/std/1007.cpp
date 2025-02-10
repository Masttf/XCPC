#include<bits/stdc++.h>
#define ll long long
#define ssz(x) ((int)x.size())
using namespace std;
const int N=3e5+5,mod=998244353;
int n,m,a[N],rt,dp[N],vis[N],rev[N],st[N],top=0,fa[N];
vector<int>g[N];
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
void Add(int&x,int y){
	((x+=y)>=mod)&&(x-=mod);
}
int ksm(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=mul(ret,a);
		a=mul(a,a);
		b>>=1;
	}
	return ret;
}
void dfs(int u,int Fa){
	dp[u]=1;
	fa[u]=Fa;
	for(int v:g[u]){
		if(v==Fa)continue;
		dfs(v,u);
		dp[u]=mul(dp[u],add(dp[v],1));
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],rev[a[i]]=i;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rt=rev[0];
	dfs(rt,0);
	int ans=dp[rt],now=ans;
	vis[rt]=1;
	for(int i=1;i<n;i++){
		int u=rev[i];
		if(!vis[u]){
			top=0;
			int v=u;
			do{
				st[++top]=v;
				v=fa[v];
			}while(!vis[v]);
			while(top){
				int x=st[top--];
				vis[x]=1;
				now=mul(now,ksm(add(dp[x],1),mod-2));
				now=mul(now,dp[x]);
			}
		}
		Add(ans,now);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}