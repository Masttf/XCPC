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
	int n, k; cin >> n >> k;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++){
		int x; cin >> x;
		g[x].push_back(i + 1);
	}
	auto check = [&](int x) -> bool{
		int cnt = 0;
		vector<int> sz(n + 1);
		auto dfs = [&](auto self, int now) -> void{
			sz[now] = 1;
			for(auto v : g[now]){
				self(self, v);
				sz[now] += sz[v];
			}
			if(sz[now] > x){
				cnt++;
				sz[now] = 0;
			}
		};
		dfs(dfs, 1);
		return cnt <= k;
	};
	int l = 0, r = n;
	int ans = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid -1;
		}else l = mid + 1;
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}