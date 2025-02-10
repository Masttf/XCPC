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
    vector<vector<pair<int, int>>>g(n + 1);
    int sum = 0;
    for(int i = 1; i < n; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    	sum += w;
    }
    vector<int> dep(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	for(auto [v, w] : g[now]){
    		if(v == father)continue;
    		dep[v] = dep[now] + w;
    		self(self, v, now);
    	}
    };
    dfs(dfs, 1, 0);
    int rt = max_element(dep.begin() + 1, dep.end()) - dep.begin();
    dep[rt] = 0;
    dfs(dfs, rt, 0);
    cout << 2 * sum - *max_element(dep.begin() + 1, dep.end()) << '\n';
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