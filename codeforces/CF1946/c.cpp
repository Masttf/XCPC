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
	int n,k;cin>>n>>k;
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto check = [&](int x)->bool{
		vector<int>sz(n+1);
		int cnt=0;
		auto dfs = [&](auto self,int now,int father)->void{
			sz[now]=1;
			for(auto v:g[now]){
				if(v==father)continue;
				self(self,v,now);
				if(sz[v]>=x)cnt++;
				else sz[now]+=sz[v];
			}
		};
		dfs(dfs,1,0);
		if(sz[1]<x)cnt--;
		return cnt>=k;
	};
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
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