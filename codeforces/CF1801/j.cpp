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
const int Max=1e18;
void solve(){
	int n,m,t;cin>>n>>m>>t;
	vector<int>a(n+1);
	for(int i=2;i<=n;i++)cin>>a[i];
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>d(n+1,Max);
	auto dij = [&]()->void{
		vector<int>vis(n+1);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		d[1]=0;
		q.push({d[1],1});
		while(!q.empty()){
			auto [w,u]=q.top();
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto v:g[u]){
				if(d[v]>d[u]+1){
					d[v]=d[u]+1;
					q.push({d[v],v});
				}
			}
		}
	};
	dij();
	for(int i=1;i<=n;i++)d[i]*=2;
	
	vector<int> dp(t+1);
	for(int i=2;i<=n;i++){
		for(int j=d[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-d[i]]+a[i]);
		}
	}
	for(int i=1;i<=t;i++){
		cout<<dp[i]<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}