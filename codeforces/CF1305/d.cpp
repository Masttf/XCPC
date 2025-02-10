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
	int n;cin>>n;
	vector<int>du(n+1);
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	int cnt=n;
	vector<int>vis(n+1);
	while(cnt>1){
		vector<int>res;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(res.size()==2)break;
			if(du[i]==1){
				res.push_back(i);
				vis[i]=1;
			}
		}
		for(auto x:res){
			for(auto v:g[x])du[v]--;
		}
		cnt-=2;
		cout<<"? "<<res[0]<<' '<<res[1]<<endl;
		int x;cin>>x;
		if(x==res[0]||x==res[1]){
			cout<<"! "<<x<<endl;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<"! "<<i<<endl;
			return ;
		}
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