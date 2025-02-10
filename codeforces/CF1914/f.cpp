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
void solve(){
	int n;cin>>n;
	vector<vector<int>>g(n+1);
	for(int i=2;i<=n;i++){
		int u;cin>>u;
		g[u].push_back(i);
		g[i].push_back(u);
	}
	vector<int>sz(n+1);
	int ans=0;
	auto dfs = [&](auto self,int now,int father)->void{
		sz[now]=1;
		int sum=0;
		int mx=0;
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			sum+=sz[v];
			mx=max(mx,sz[v]);
		}
		if(g[now].size()>=3||(g[now].size()==2&&now==1)){
			int res=sum-mx;
			if(res<=mx){
				ans+=res;
				sz[now]+=mx-res;
			}else{
				int d=sum%2;
				ans+=(sum-d)/2;
				sz[now]+=d;
			}
		}else sz[now]+=sum;
		//dbg(now,ans,sum,mx);
	};
	dfs(dfs,1,0);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
/*
6
4
1 2 1
2
1
5
5 5 5 1
7
1 2 1 1 3 3
7
1 1 3 2 2 4
7
1 2 1 1 1 3
*/
