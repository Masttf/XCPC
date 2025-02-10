#include<bits/stdc++.h>
//#define int long long
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
	int n,m,q;cin>>n>>m>>q;
	vector<vector<int>>g(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<int>>num(n+1);
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		num[x].push_back(i);
	}

	vector<int>dep(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	vector<vector<vector<int>>>val(25,vector<vector<int>>(n+1,vector<int>(10)));
	auto up = [&](vector<int>&res,vector<int>x,vector<int>y)->void{
		int l=0,r=0;
		for(int i=0;i<10;i++){
			if(x[l]==0)res[i]=y[r++];
			else if(y[r]==0)res[i]=x[l++];
			else if(x[l]>y[r])res[i]=y[r++];
			else res[i]=x[l++];
		}
		return ;
	};

	auto dfs = [&](auto self,int now,int father)->void{
		dep[now]=dep[father]+1;
		f[0][now]=father;
		for(int i=0;i<min(10,(int)num[father].size());i++){
			val[0][now][i]=num[father][i];
		}
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
			up(val[i][now],val[i-1][now],val[i-1][f[i-1][now]]);
		}
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	
	auto lca = [&](int a,int b)->vector<int>{
		if(dep[a]<dep[b])swap(a,b);
		vector<int>res1(10);
		for(int i=0;i<min(10,(int)num[a].size());i++){
			res1[i]=num[a][i];
		}
		vector<int>res2(10);
		for(int i=0;i<min(10,(int)num[b].size());i++){
			res2[i]=num[b][i];
		}
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b]){
				vector<int>temp=res1;
				up(res1,temp,val[i][a]);
				a=f[i][a];
			}
		}
		if(a==b)return res1;
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				vector<int>temp=res1;
				up(res1,temp,val[i][a]);
				temp=res2;
				up(res2,temp,val[i][b]);
				a=f[i][a];
				b=f[i][b];
			}
		}
		vector<int>ans(10);
		up(ans,res1,res2);
		vector<int>temp=ans;
		up(ans,temp,val[0][a]);
		return ans;
	};
	//lca(5,3);
	for(int i=1;i<=q;i++){
		int u,v,a;cin>>u>>v>>a;
		vector<int>ans=lca(u,v);
		int k=a;
		for(int i=0;i<min(10,a);i++){
			if(ans[i]==0){
				k=i;
				break;
			}
		}
		cout<<k<<' ';
		for(int i=0;i<k;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
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