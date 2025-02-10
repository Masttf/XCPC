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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>>g(n + 1);
    vector<int>du(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, -w});
    	du[v]++;
    }
    vector<int> ans(n + 1, Max);
    auto bfs = [&](int s) -> void{
    	ans[s] = 0;
    	queue<int>q;
    	q.push(s);
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		for(auto [v, w] : g[u]){
    			if(ans[v] != Max)continue;
    			ans[v] = ans[u] + w;
    			q.push(v);
    		}
    	}
    };
    for(int i = 1; i <= n; i++){
    	if(ans[i] == Max){
    		bfs(i);
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
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