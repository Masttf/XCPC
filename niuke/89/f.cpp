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
	int n,m;cin>>n>>m;
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>vis(n+1,Max);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	vector<int>mi1(n+1,Max),mi2(n+1,Max);
	for(int i=1;i<=m;i++){
		int x,t;cin>>x>>t;
		t*=2;
		if(mi1[x]>=t)mi2[x]=mi1[x],mi1[x]=t;
		else mi2[x]=min(mi2[x],t);
		vis[x]=min(vis[x],t);
	}
	int ans=1e18;
	for(int i=1;i<=n;i++){
		ans=min(ans,mi2[i]);
		if(vis[i]!=Max)q.push({vis[i],i});
	}
	vector<int>vvs(n+1);
	while(!q.empty()){
		auto [w,u]=q.top();
		q.pop();
		if(vvs[u])continue;
		vvs[u]=1;
		for(auto v:g[u]){
			if(vis[v]>vis[u]+2){
				if(vis[v]!=Max)ans=min(ans,vis[v]);
				vis[v]=vis[u]+2;
				q.push({vis[v],v});
			}else if(vis[v]==vis[u]){
				ans=min(ans,vis[u]+1);
			}else if(vis[v]==vis[u]+2)ans=min(ans,vis[u]+2);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}