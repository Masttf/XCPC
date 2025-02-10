#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i <= n; i++){
		g[a[i]].push_back(i); 
	}
	vector<int> incircle(n + 1);
	vector<int> vis(n + 1);
	vector<int> sz(n + 1, 1);
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		int x = i;
		while(!vis[x]){
			vis[x] = 1;
			x = a[x];
		}
		vector<int> circle;
		while(!incircle[x]){
			incircle[x] = 1;
			circle.push_back(x);
			x = a[x];
		}
		const int cnt = circle.size();
		for(auto x : circle) sz[x] = cnt;
		auto dfs = [&](auto self, int now, int father) -> void{
			vis[now] = 1;
			ans += sz[now];
			for(auto v : g[now]){
				if(v == father || incircle[v])continue;
				sz[v] += sz[now];
				self(self, v, now);
			}
		};
		for(auto x : circle)dfs(dfs, x, 0);
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}