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
constexpr int Max = 1e18;
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
    vector<int> val(n + 1);
    vector<int> W(n + 1);
    vector<pair<int, int>> mm(n + 1);
    auto dfs1 = [&](auto self, int now, int father) -> void{
    	for(auto [v, w] : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		W[now] += W[v] + w;
    		if(val[v] - 2 * W[v] - w < mm[now].first){
    			mm[now].second = mm[now].first;
    			mm[now].first = val[v] - 2 * W[v] - w;
    		}else mm[now].second = min(mm[now].second, val[v] - 2 * W[v] - w);
    	}
    	val[now] = 2 * W[now] + mm[now].first;
    };
    dfs1(dfs1, 1, 0);
    int ans = Max;
    auto dfs2 = [&](auto self, int now, int father) -> void{
    	int tot = sum;
    	ans = min(ans, 2 * tot + mm[now].first);
    	int temp = val[now];
    	int t2 = W[now];
    	for(auto [v, w] : g[now]){
    		if(v == father)continue;
    		W[now] = tot - W[v] - w;
    		if(val[v] - 2 * W[v] - w == mm[now].first){
    			val[now] = 2 * W[now] + mm[now].second;
    		}else{
    			val[now] = 2 * W[now] + mm[now].first;
    		}
    		if(val[now] - 2 * W[now] - w < mm[v].first){
                mm[v].second = mm[v].first;
                mm[v].first = val[now] - 2 * W[now] - w;
            }else  mm[v].second = min(mm[v].second, val[now] - 2 * W[now] - w);
    		self(self, v, now);
    		val[now] = temp;
    		W[now] = t2;
    	}
    };
    dfs2(dfs2, 1, 0);
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