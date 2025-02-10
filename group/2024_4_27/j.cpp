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
	int k,y;cin>>k>>y;
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[v].push_back({u,w});
	}
	auto bfs2 = [&]()->bool{
		queue<int>q;
		vector<int>vis(n+1);
		q.push(y);
		vis[y]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto [v,w]:g[u]){
				if(vis[v])return true;
				vis[v]=1;
				q.push(v);
			}
		}
		return false;
	};
	if(bfs2()){
		cout<<"YES\n";
		return ;
	}
	vector<int>mx(n+1);
	auto bfs = [&]()->void{
		queue<int>q;
		q.push(y);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto [v,w]:g[u]){
				mx[v]=max(mx[v],mx[u]+w);
				q.push(v);
			}
		}
	};
	bfs();
	int res=*max_element(mx.begin()+1,mx.end());
	if(res>=k)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}