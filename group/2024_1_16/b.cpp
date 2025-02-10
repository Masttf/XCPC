#include<bits/stdc++.h>
//#define int long long
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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector g(n+1,vector<pair<int,int>>());
	for(int i=2;i<=n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	vector<int>ans(n+1);
	vector<set<pair<int,int>>>res(n+1);
	for(int i=2;i<=n;i++)res[i].insert({a[i],i});
	int cnt=1;
	int nw=1;
	auto dfs = [&](auto self,int now,int father,int k)->void{
		if(!res[now].empty()){
			for(int i=1;i<=k;i++){
				if(res[now].empty())break;
				auto it=res[now].begin();
				res[now].erase(it);
				//dbg(now,father,it->second,i,now);
				if(father==1)ans[it->second]=nw,cnt++;
				else res[father].insert(*it);
			}
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			self(self,v,now,w);
		}
	};
	while(cnt<n){
		dfs(dfs,1,0,0);
		nw++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}