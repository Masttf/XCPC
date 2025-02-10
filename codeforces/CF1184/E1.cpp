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
constexpr int Max=1e18;
struct node{
	int u,v,w,id;
	bool operator <(const node&y)const{
		return w<y.w;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<node>e(m+1);
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].id=i;
	}
	sort(e.begin()+2,e.end());
	vector<int>f(n+1);
	for(int i=1;i<=n;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	int sz=0;
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=2;i<=m;i++){
		auto [u,v,w,id]=e[i];
		int fa=find(find,u);
		int fb=find(find,v);
		if(fa==fb)continue;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		f[fa]=fb;
		sz++;
	}
	if(sz!=n-1){
		int res=1e9;
		cout<<res<<'\n';
		return ;
	}
	vector<int>dep(n+1);
	vector fa(25,vector<int>(n+1));
	vector fmax(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father,int w)->void{
		dep[now]=dep[father]+1;
		fa[0][now]=father;
		fmax[0][now]=w;
		for(int i=1;(1ll<<i)<dep[now];i++){
			fa[i][now]=fa[i-1][fa[i-1][now]];
			fmax[i][now]=max(fmax[i-1][now],fmax[i-1][fa[i-1][now]]);
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			self(self,v,now,w);
		}
	};
	dfs(dfs,1,0,0);
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		int mx=0;
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b]){
				mx=max(mx,fmax[i][a]);
				a=fa[i][a];
			}
		}
		if(a==b)return mx;
		for(int i=20;i>=0;i--){
			if(fa[i][a]!=fa[i][b]){
				mx=max({mx,fmax[i][a],fmax[i][b]});
				a=fa[i][a];
				b=fa[i][b];
			}
		}
		mx=max({mx,fmax[0][a],fmax[0][b]});
		return mx;
	};
	auto [u,v,w,id]=e[1];
	int res=lca(u,v);
	cout<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}