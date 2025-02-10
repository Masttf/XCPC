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
	int val,id,k;
	bool operator <(const node&y)const{
		return val>y.val;
	}
};
void solve(){
	int n,m;cin>>n>>m;
	vector g(n+1,vector<pair<int,int>>());
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>s(n+1);
	int mx=0;
	for(int i=1;i<=n;i++)cin>>s[i],mx=max(mx,s[i]);
	vector dp(n+1,vector<int>(mx+1,LONG_LONG_MAX));
	auto dijkstra = [&]()->void{
		vector vis(n+1,vector<int>(mx+1));
		priority_queue<node>q;
		q.push({0,1,s[1]});
		dp[1][s[1]]=0;
		while(!q.empty()){
			auto [val,id,k]=q.top();
			q.pop();
			if(vis[id][k])continue;
			//dbg(id,k,dp[id][k]);
			vis[id][k]=1;
			for(auto [v,w]:g[id]){
				if(s[v]>k){
					if(dp[v][k]>dp[id][k]+k*w){
						dp[v][k]=dp[id][k]+k*w;
						q.push({dp[v][k],v,k});
					}
				}else{
					if(dp[v][s[v]]>dp[id][k]+k*w){
						dp[v][s[v]]=dp[id][k]+k*w;
						q.push({dp[v][s[v]],v,s[v]});
					}
				}
			}
		}
	};
	dijkstra();
	int ans=LONG_LONG_MAX;
	for(int i=1;i<=mx;i++){
		ans=min(ans,dp[n][i]);
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