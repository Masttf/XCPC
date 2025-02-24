#include <bits/stdc++.h>
using namespace std;
#define int long long

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
struct node{
	int u,v,w;
	bool operator <(const node&y)const{
		return w>y.w;
	}
};
void solve() {
	int n,m;cin>>n>>m;
	vector<vector<int>>g(n+m+1);
	for(int i=1;i<=n+m;i++){
		int u,v;cin>>u>>v;
		u++;
		v++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector dp(n+m+1,vector<int>(2));
	auto dfs = [&](auto self,int now,int father)->void{
		dp[now][1]=1;
		for(auto v:g[now]){
			if(v<=n||v==father)continue;
			self(self,v,now);
			dp[now][0]+=dp[v][1];
			dp[now][1]+=min(dp[v][0],dp[v][1]);
		}
	};
	for(int i=1;i<=n;i++)dfs(dfs,i,0);
	vector f(n+1,vector<int>(2));
	f[1][0]=INT_MAX;
	f[1][1]=dp[1][1];
	for(int i=2;i<=n;i++){
		f[i][0]=f[i-1][1]+dp[i][0];
		f[i][1]=min(f[i-1][1],f[i-1][0])+dp[i][1];
	}
	f[n][0]=min(f[n-1][1],f[n-1][0])+dp[n][0];
	
	int ans=min(f[n][0],f[n][1]);
	//dbg(ans);
	f=vector<vector<int>>(n+1,vector<int>(2));
	f[1][0]=dp[1][0];
	f[1][1]=INT_MAX;
	for(int i=2;i<=n;i++){
		f[i][0]=f[i-1][1]+dp[i][0];
		f[i][1]=min(f[i-1][1],f[i-1][0])+dp[i][1];
	}
	ans=min({ans,f[n][0],f[n][1]});
	//dbg(ans);
	f=vector<vector<int>>(n+1,vector<int>(2));
	f[n][0]=INT_MAX;
	f[n][1]=dp[n][1];
	for(int i=n-1;i>=1;i--){
		f[i][0]=f[i+1][1]+dp[i][0];
		f[i][1]=min(f[i+1][1],f[i+1][0])+dp[i][1];
	}
	ans=min({ans,f[1][0],f[1][1]});
	//dbg(ans);
	cout<<ans<<'\n';
	return ;
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T = 1;
	//cin >> T;
	while (T--) solve();
	return 0;
}
