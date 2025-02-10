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
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    }
    int ans = -1;
    vector<int> dis(n + 1);
    vector<int> vis(n + 1);
    auto bfs = [&]() -> void{
    	queue<int>q;
    	q.push(1);
    	dis[1] = 1;
    	vis[1] = 1;
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		for(auto v : g[u]){
    			if(v == 1){
    				// dbg(u);
    				if(ans == -1 || ans > dis[u]){
    					ans = dis[u];
    				}
    			}
    			if(!vis[v]){
    				vis[v] = 1;
    				dis[v] = dis[u] + 1;
    				q.push(v);
    			}
    		}
    	}
    };
    bfs();
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