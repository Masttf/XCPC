#include<bits/stdc++.h>
#define int long long
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
struct node{
	int u,v,w;
	bool operator <(const node&y)const{
		return w<y.w;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>ff(n+1);
	for(int i=1;i<=n;i++)ff[i]=i;
	auto find = [&](auto self,int x)->int{
		return ff[x]==x?x:ff[x]=self(self,ff[x]);
	};
	vector<node>e;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end());
	vector<int>vis(m);
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=0;i<m;i++){
		auto [u,v,w]=e[i];
		int fa=find(find,u);
		int fb=find(find,v);
		if(fa==fb)continue;
		ff[fa]=fb;
		vis[i]=1;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>dep(n+1);
	vector<int>val(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	vector<vector<int>>mx(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father)->void{
		dep[now]=dep[father]+1;
		f[0][now]=father;
		mx[0][now]=val[father];
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
			mx[i][now]=max(mx[i-1][now],mx[i-1][f[i-1][now]]);
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			val[v]=w;
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		int ta=a;
		int res=val[a];
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b]){
				res=max(res,mx[i][a]);
				a=f[i][a];
			}
		}
		if(a==b){
			a=ta;
			res=val[a];
			for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>dep[b]){
					res=max(res,mx[i][a]);
					a=f[i][a];
				}
			}
			return res;
		}
		res=max(res,val[b]);
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				res=max(res,mx[i][a]);
				res=max(res,mx[i][b]);
				a=f[i][a];
				b=f[i][b];
			}
		}
		return res;
	};	
	int ans=0;
	for(int i=0;i<m;i++){
		if(vis[i])continue;
		auto [u,v,w]=e[i];
		int res=lca(u,v);
		if(res==w)ans++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}