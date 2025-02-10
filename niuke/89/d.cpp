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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	int n,m,q,s;cin>>n>>m>>q>>s;
	vector g(n+1,vector<int>());
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>d(n+1,Max);
	vector<int>vis(n+1);
	auto dijkstra = [&]()->void{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		d[s]=0;
		q.push({d[s],s});
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
	dijkstra();
	vector<int>cnt(5005);
	for(int i=1;i<=n;i++)cnt[d[i]]++;
	vector<int>res(1);
	for(int i=1;i<=5000;i++){
		if(cnt[i])res.push_back(cnt[i]);
	}
	n=res.size()-1;
	vector dp(n+5,vector<int>(5005,0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5000;j++){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=1;j<=5000;j++){
			dp[i][j]+=dp[i-1][j-1]*res[i]%mod;
			dp[i][j]%=mod;
		}
	}
	for(int _=1;_<=q;_++){
		int k;cin>>k;
		cout<<dp[n][k]<<'\n';
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