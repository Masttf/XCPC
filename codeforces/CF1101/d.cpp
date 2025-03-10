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
    vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int N = 2e5;
	vector<int> vis(N + 1);
	vector<vector<int>> prims(N + 1);
	for(int i = 2; i <= N; i++){
		if(vis[i])continue;
		for(int j = i; j <= N; j += i){
			vis[j] = 1;
			prims[j].push_back(i);
		}
	}
	int ans = 0;
	vector<vector<int>> mx(n + 1);
	for(int i = 1; i <= n; i++){
		mx[i].assign(prims[a[i]].size(), 1);
	}
	auto dfs = [&](auto self, int now, int father) -> void{
		int siz = prims[a[now]].size();
		if(siz > 0)ans = max(ans, 1ll);
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
			int siz2 = prims[a[v]].size();
			for(int i = 0; i < siz; i++){
				for(int j = 0; j < siz2; j++){
					if(prims[a[now]][i] == prims[a[v]][j]){
						ans = max(ans, mx[now][i] + mx[v][j]);
						mx[now][i] = max(mx[v][j] + 1, mx[now][i]);
					}
				}
			}
		}
	};
	dfs(dfs, 1, 0);
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
/*
枚举一个点然后log算出它的贡献？
gcd最多递减log次
ai的范围只到2e5
gcd的值最多也就2e5
不为1，只要判断质数即可
不同的质数就几个就会超过2e5 logN

*/