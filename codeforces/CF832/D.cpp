#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>>g(n+1);
	for(int i=2;i<=n;i++){
		int v;cin>>v;
		g[i].push_back(v);
		g[v].push_back(i);
	}

	vector<int>dep(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father)->void{
		dep[now]=dep[father]+1;
		f[0][now]=father;
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
		}
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b])a= f[i][a];
		}
		if(a==b)return a;
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				a=f[i][a];
				b=f[i][b];
			}
		}
		return f[0][a];
	};//对哦假设a为汇点，(dis(a,b)+dis(a,c)-dis(b,c))/2+1
	//b,c的汇点一定在这条a-b，a-c路径上
	auto get = [&](int a,int b,int c)->int{
		int fa=lca(a,c);
		int fb=lca(b,c);
		int fc=lca(a,b);
		int res=fa;
		if(dep[res]<dep[fb])res=fb;
		if(dep[res]<dep[fc])res=fc;
		int ans=1;
		int ff=lca(a,res);
		ans=max(ans,dep[a]-dep[ff]+dep[res]-dep[ff]+1);
		ff=lca(b,res);
		ans=max(ans,dep[b]-dep[ff]+dep[res]-dep[ff]+1);
		ff=lca(c,res);
		ans=max(ans,dep[c]-dep[ff]+dep[res]-dep[ff]+1);
		return ans;
	};
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		int ans=get(a,b,c);
		cout<<ans<<'\n';
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