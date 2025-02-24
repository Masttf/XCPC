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
	int n;cin >>n;
	vector<vector<int>>g(n+1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>val(n + 1);
	for(int i = 1; i <= n; i++)cin >> val[i];
	vector<pair<int,int>>res(n + 1);
	res[0] = {0,1};
	auto dfs = [&](auto self, int now, int father) -> void{
		res[now].first = res[father].first * val[now] + 15ll*res[father].second;
		res[now].second = res[father].second * val[now];
		int d = __gcd(res[now].first,res[now].second);
		res[now].first/=d;
		res[now].second/=d;
		for(auto v : g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
	};
	dfs(dfs,1,0);
	pair<int, int> ans = {0,1};
	for(int i = 1; i <= n; i++){
		int d = (ans.second * res[i].second)/__gcd(ans.second,res[i].second);
		int d1=ans.first*(d/ans.second);
		int d2=res[i].first*(d/res[i].second);
		if(d2>d1)ans=res[i];
	}
	cout << ans.first << '/' << ans.second << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}