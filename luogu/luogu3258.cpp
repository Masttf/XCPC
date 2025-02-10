//树剖
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
vector<int>g[maxn];
int t[maxn<<1],n,f[maxn],sz[maxn],top[maxn],son[maxn],dfn[maxn];
int deep[maxn],tot;
int rountine[maxn];
void dfs1(int u,int father){
	deep[u]=deep[father]+1;
	f[u]=father;
	sz[u]=1;
	for(auto v:g[u]){
		if(v==father)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
	return ;
}
void dfs2(int u,int t){
	dfn[u]=++tot;
	top[u]=t;
	if(!son[u])return ;
	dfs2(son[u],t);
	for(auto v:g[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
	return ;
}
void updata(int x,int y){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])swap(x,y);
		t[dfn[top[x]]]++;
		t[dfn[x]+1]--;
		x=f[top[x]];
	}
	if(deep[x]<deep[y])swap(x,y);
	t[dfn[y]]++;
	t[dfn[x]+1]--;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>rountine[i];
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	vector<int>ans(n+1);
	for(int i=2;i<=n;i++){
		updata(rountine[i-1],rountine[i]);
		ans[rountine[i]]--;
	}
	for(int i=1;i<=n;i++)t[i]+=t[i-1];
	for(int i=1;i<=n;i++){
		ans[i]+=t[dfn[i]];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
/*dfs序
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
vector<int>g[maxn];
int t[maxn<<1],n,f[maxn][25];
int deep[maxn],st[maxn],ed[maxn],tot;
int rountine[maxn];
void dfs(int u,int father){
	deep[u]=deep[father]+1;
	st[u]=++tot;
	f[u][0]=father;
	for(int i=1;(1LL<<i)<deep[u];i++)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==father)continue;
		dfs(v,u);
	}
	ed[u]=++tot;
}
int lca(int a,int b){
	if(deep[a]<deep[b])swap(a,b);
	for(int i=20;i>=0;i--){
		if(deep[a]-(1LL<<i)>=deep[b])a=f[a][i];
	}
	if(a==b)return a;
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
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>rountine[i];
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	vector<int>ans(n+1);
	for(int i=2;i<=n;i++){
		int fa=lca(rountine[i-1],rountine[i]);
		t[st[rountine[i-1]]]++;
		t[st[rountine[i]]]++;
		t[st[fa]]--;
		t[st[f[fa][0]]]--;
		ans[rountine[i]]--;
	}
	for(int i=1;i<=2*n;i++)t[i]+=t[i-1];
	for(int i=1;i<=n;i++){
		ans[i]+=t[ed[i]]-t[st[i]-1];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
 */
