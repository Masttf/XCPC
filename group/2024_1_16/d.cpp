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
void solve(){
	int n,m;cin>>n>>m;
	int s,t;cin>>s>>t;
	vector g(n+1,vector<pair<int,int>>());
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>mx(n+1),cost(n+1);
	for(int i=1;i<=n;i++){
		cin>>mx[i]>>cost[i];
	}
	vector e(n+1,vector<int>());
	auto bfs = [&](int x)->void{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
		vector<int>vis(n+1);
		vector<int>d(n+1,1e18);
		d[x]=0;
		q.push({d[x],x});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto [v,w]:g[u]){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					q.push({d[v],v});
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(i==x)continue;
			if(d[i]<=mx[x]){
				e[x].push_back(i);
				//dbg(x,i,d[i]);
			}
		}
	};
	for(int i=1;i<=n;i++)bfs(i);

	auto dijkstra = [&]()->int{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
		vector<int>d(n+1,1e18);
		d[s]=0;
		q.push({d[s],s});
		while(!q.empty()){
			auto [ww,u]=q.top();
			q.pop();
			if(ww>d[u])continue;
			for(auto v:e[u]){
				if(d[v]>d[u]+cost[u]){
					d[v]=d[u]+cost[u];
					q.push({d[v],v});
				}
			}
		}
		if(d[t]==1e18)return -1;
		else return d[t];
	};
	cout<<dijkstra()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}