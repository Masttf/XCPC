#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int dfn=0;
	vector<int>st(n+1);
	vector<int>ed(n+1);
	vector<int>res(2*n+1);
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector f(21,vector<int>(n+1));
	vector<int>dep(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		st[now]=++dfn;
		res[dfn]=a[now];
		f[0][now]=father;
		dep[now]=dep[father]+1;
		for(int i=1;(1<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
		}
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
		ed[now]=++dfn;
		res[dfn]=-a[now];
	};

	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1<<i)>=dep[b])a=f[i][a];
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

	int tot=0;
	vector<int>root(2*n+1);
	vector t(2,vector<int>((n+1)*65));
	vector cnt(2,vector<int>((n+1)*65));
	auto ins = [&](int u,int v,int x,int val)->void{
		for(int i=30;i>=0;i--){
			t[0][u]=t[0][v];
			t[1][u]=t[1][v];
			int d=(x>>i)&1;
			t[d][u]=++tot;
			u=t[d][u];
			v=t[d][v];
			cnt[0][u]=cnt[0][v]+val;
			cnt[1][u]=cnt[1][v]+max(0,val);
		}
	};

	auto query = [&](int u,int v,int x,int k)->int{
		int res=0;
		for(int i=30;i>=0;i--){
			int d=(x>>i)&1;
			d^=1;
			if(cnt[k][t[d][u]]-cnt[k][t[d][v]]){
				res+=1<<i;
			}else d^=1;
			u=t[d][u];
			v=t[d][v];
		}
		return res;
	};

	
	dfs(dfs,1,0);
	
	root[0]=++tot;
	ins(root[0],root[0],0,1);
	for(int i=1;i<=2*n;i++){
		root[i]=++tot;
		if(res[i]>0)ins(root[i],root[i-1],res[i],1);
		else ins(root[i],root[i-1],-res[i],-1);
	}
	
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		if(t==1){
			int x,y;cin>>x>>y;
			//dbg(i,in[x],out[x]);
			cout<<query(root[ed[x]],root[st[x]-1],y,1)<<'\n';
		}else{
			int u,v,x;cin>>u>>v>>x;
			int fa=lca(u,v);
			int ans=0;
			//dbg(u,v,fa);
			ans=max(ans,query(root[max(st[u],st[fa])],root[min(st[u],st[fa])-1],x,0));
			ans=max(ans,query(root[max(st[v],st[fa])],root[min(st[v],st[fa])-1],x,0));
			cout<<ans<<'\n';			
		}
		//dbg(i,"ok");
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}