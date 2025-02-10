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
struct node{
	int l, d, k, c, v;
};
void solve(){
	int inf = LONG_LONG_MAX;
    int n, m; cin >> n >> m;
    vector<vector<node>> g(n + 1);
    for(int i = 1; i <= m; i++){
    	int l, d, k, c, u, v;
    	cin >> l >> d >> k >> c >> u >> v;
    	g[v].push_back({l, d, k, c, u});
    }
    vector<int> dis(n + 1);
    auto dij = [&]() -> void{
    	priority_queue<pair<int, int>> q;
    	dis[n] = inf;
    	q.push({dis[n], n});
    	while(!q.empty()){
    		auto [W, u] = q.top();
    		// dbg(u, W);
    		q.pop();
    		if(W < dis[u])continue;
    		for(auto [l, d, k, c, v] : g[u]){
    			if(dis[u] - c < l)continue;
    			int kk = (dis[u] - l - c) / d;
    			kk = min(kk, k - 1);
    			int val = l + kk * d;
    			if(dis[v] < val){
    				dis[v] = val;
    				q.push({dis[v], v});
    			}
    		}
    	}
    };
    dij();
    for(int i = 1; i < n; i++){
    	if(dis[i] == 0){
    		cout << "Unreachable\n";
    	}else cout << dis[i] << '\n';
    }
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