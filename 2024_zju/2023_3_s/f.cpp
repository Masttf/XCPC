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
	int n,m;cin>>n>>m;
	vector<vector<array<int,4>>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v,t,p,c;cin>>u>>v>>t>>p>>c;
		g[u].push_back({v,t,p,c});
	}
	vector<double>d(n+1,Max);
	auto dijkstra = [&](int s)->void{
		priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>q;
		q.push({0,s});
		d[s]=0;
		while(!q.empty()){
			auto [ww,u]=q.top();
			q.pop();
			if(ww>d[u])continue;
			for(auto [v,t,p,c]:g[u]){
				if(d[v]>d[u]+c){
					d[v]=d[u]+c;
					q.push({d[v],v});
				}
				if(d[v]>(d[u]+t)*100*1.0/(100-p)){
					d[v]=(d[u]+t)*100*1.0/(100-p);
					q.push({d[v],v});
				}
			}
		}
	};
	dijkstra(1);
	if(d[n]==Max)cout<<-1<<'\n';
	else cout<<fixed<<setprecision(10)<<d[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}