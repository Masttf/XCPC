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
constexpr int Max=1e18;
void solve(){
	int n,m,k,s;cin>>n>>m>>k>>s;
	int p,qq;cin>>p>>qq;
	vector<vector<int>>g(n+1);
	vector<int>vis(n+1);
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		vis[x]=2;
	}
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>d1(n+1);
	auto bfs = [&]()->void{
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(vis[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(vis[v])continue;
				vis[v]=1;
				d1[v]=d1[u]+1;
				q.push(v);
			}
		}
	};
	bfs();
	vector<int>dis(n+1,Max);
	auto dij = [&]()->void{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		dis[1]=0;
		q.push({dis[1],1});
		while(!q.empty()){
			auto [ww,u]=q.top();
			q.pop();
			if(dis[u]<ww)continue;
			for(auto v:g[u]){
				if(vis[v]==2)continue;
				int cost=p;
				if(d1[v]<=s)cost=qq;
				if(dis[v]>dis[u]+cost){
					dis[v]=dis[u]+cost;
					q.push({dis[v],v});
				}
			}
		}
	};
	dij();
	if(d1[n]<=s)dis[n]-=qq;
	else dis[n]-=p;
	cout<<dis[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}