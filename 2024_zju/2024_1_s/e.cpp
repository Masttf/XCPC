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
void solve(){
	int n;cin>>n;
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	vector<int>dep(n+1);
	vector f(25,vector<int>(n+1));
	vector<unsigned>val(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		f[0][now]=father;
		dep[now]=dep[father]+1;
		for(int i=1;(1<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			val[v]=w;
			self(self,v,now);
		}
	};
	dfs(dfs,1,0);
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1<<i)>=dep[b]){
				a=f[i][a];
			}
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
	vector p(70,vector<unsigned>(70));
	p[1][1]=1;
	p[2][1]=1;
	p[2][2]=1;
	p[3][1]=2;
	p[3][2]=3;
	p[3][3]=2;
	for(int i=4;i<=65;i++){
		for(int j=1;j<i;j++){
			p[i][j]+=2*p[i-1][j];
		}
		for(int j=2;j<=i;j++){
			p[i][j]+=2*p[i-1][j-1];
		}
		for(int j=2;j<i;j++){
			p[i][j]-=2*p[i-2][j-1];
		}
	}
	auto get = [&](int u,int v,int fa)->int{
		vector<int>res;
		while(u!=fa){
			res.emplace_back(val[u]);
			u=f[0][u];
		}
		int l1=res.size();
		while(v!=fa){
			res.emplace_back(val[v]);
			v=f[0][v];
		}
		reverse(res.begin()+l1,res.end());
		unsigned ans=0;
		int sz=res.size();
		for(int i=0;i<sz;i++){
			ans+=p[sz][i+1]*res[i];
		}
		return ans;
	};
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		int fa=lca(u,v);
		int d=dep[u]+dep[v]-2*dep[fa];
		if(d>65||u==v){
			cout<<0<<'\n';
		}else{
			cout<<get(u,v,fa)<<'\n';
		}
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