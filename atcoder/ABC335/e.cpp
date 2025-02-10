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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector g(n+1,vector<int>());
	vector<int>du(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>dp(n+1);
	auto bfs = [&]()->void{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		q.push({1,1});
		dp[1]=1;
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			for(auto v:g[u]){
				int d=dp[u]+(a[u]==a[v]?0:1);
				if(a[u]<=a[v]){
					if(d>dp[v]){
						dp[v]=d;
						q.push({dp[v],v});
					}
				}
			}
		}
	};
	bfs();
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}