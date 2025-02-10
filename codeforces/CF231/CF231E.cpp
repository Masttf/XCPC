#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void debug(){
	cout<<"YES"<<endl;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>e;
	vector<vector<int>>g(n+1,vector<int>());
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		e.push_back({u,v});
	}
	vector<int>dfn(n+1),low(n+1),instack(n+1),id(n+1),sz(n+1);
	stack<int>s;
	int tot=1;
	int cnt=1;
	auto tarjan = [&](auto tarjan,int x,int father)->void{
		dfn[x]=low[x]=tot++;
		instack[x]=1;
		s.push(x);
		for(auto v:g[x]){
			if(v==father)continue;
			if(!dfn[v]){
				tarjan(tarjan,v,x);
				low[x]=min(low[x],low[v]);
			}else if(instack[v]){
				low[x]=min(low[x],dfn[v]);
			}
		}
		if(dfn[x]==low[x]){
			int temp;
			do{
				temp=s.top();
				s.pop();
				instack[temp]=0;
				id[temp]=cnt;
				sz[cnt]++;
			}while(temp!=x);
			cnt++;
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i,0);
	}
	vector<vector<int>>adj(cnt,vector<int>());
	for(auto [u,v] :e){
		if(id[u]!=id[v]){
			u=id[u],v=id[v];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	vector<int>dep(cnt),val(cnt);
	vector<vector<int>>f(25,vector<int>(cnt));
	auto dfs = [&](auto dfs,int now,int father)->void{
		dep[now]=dep[father]+1;
		f[0][now]=father;
		for(int i=1;(1ll<<i)<=dep[now];i++)f[i][now]=f[i-1][f[i-1][now]];
		val[now]=val[father];
		if(sz[now]>1)val[now]++;
		for(auto v:adj[now]){
			if(v==father)continue;
			dfs(dfs,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1LL<<i)>=dep[b])a=f[i][a];
		}
		if(a==b)return a;
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				a=f[i][a];
				b=f[i][b];
			}
		}
		return f[0][a];
	};
	
	int q;cin>>q;
	while(q--){
		int u,v;cin>>u>>v;
		u=id[u];
		v=id[v];
		int p=lca(u,v);
		int d=val[u]-val[p]+val[v]-val[f[0][p]];
		cout<<qmi(2,d)<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
