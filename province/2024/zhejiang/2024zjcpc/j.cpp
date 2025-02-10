#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
struct node{
	int u,v,w;
	bool operator <(const node &y)const{
		return w<y.w;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector<node>e(m+1);
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e.begin()+1,e.end());
	vector<int>f(n+1);
	for(int i=1;i<=n;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	int ans=0;
	int sz=0;
	vector<int>vis(m+1);
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=1;i<=m;i++){
		auto [u,v,w]=e[i];
		int fa=find(find,u);
		int fb=find(find,v);
		if(fa==fb)continue;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		vis[i]=1;
		ans+=w;
		sz++;
		f[fa]=fb;
	}
	if(sz!=n-1){
		cout<<-1<<' '<<-1<<'\n';
		return ;
	}
	int res1=-1,res2=ans;
	vector<int>dep(n+1);
	vector<vector<int>>ff(25,vector<int>(n+1));
	vector<vector<int>>f1(25,vector<int>(n+1));
	vector<vector<int>>f2(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father,int w)->void{
		dep[now]=dep[father]+1;
		ff[0][now]=father;
		if(w%2==0)f2[0][now]=w;
		else f1[0][now]=w;
		for(int i=1;(1ll<<i)<dep[now];i++){
			ff[i][now]=ff[i-1][ff[i-1][now]];
			f1[i][now]=max(f1[i-1][now],f1[i-1][ff[i-1][now]]);
			f2[i][now]=max(f2[i-1][now],f2[i-1][ff[i-1][now]]);
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			self(self,v,now,w);
		}
		return ;
	};
	dfs(dfs,1,0,0);
	
	auto lca = [&](int a,int b)->pair<int,int>{
		int mi1=0,mi2=0;
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b]){
				mi1=max(mi1,f1[i][a]);
				mi2=max(mi2,f2[i][a]);
				a=ff[i][a];
			}
		}
		if(a==b)return {mi1,mi2};
		for(int i=20;i>=0;i--){
			if(ff[i][a]!=ff[i][b]){
				mi1=max(mi1,f1[i][a]);
				mi2=max(mi2,f2[i][a]);
				mi1=max(mi1,f1[i][b]);
				mi2=max(mi2,f2[i][b]);
				a=ff[i][a];
				b=ff[i][b];
			}
		}
		mi1=max(mi1,f1[0][a]);
		mi2=max(mi2,f2[0][a]);
		mi1=max(mi1,f1[0][b]);
		mi2=max(mi2,f2[0][b]);
		return {mi1,mi2};
	};	
	for(int i=1;i<=m;i++){
		auto [u,v,w]=e[i];
		if(vis[i])continue;
		auto [mi1,mi2]=lca(u,v);
		if(w%2==1&&mi2){
			int d=ans-mi2+w;
			if(res1==-1||res1>d)res1=d;
		}else if(w%2==0&&mi1){
			int d=ans-mi1+w;
			if(res1==-1||res1>d)res1=d;
		}
	}
	if(ans%2==0)swap(res1,res2);
	cout<<res1<<' '<<res2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}