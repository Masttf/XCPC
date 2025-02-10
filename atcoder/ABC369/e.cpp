#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
void solve(){
    int n, m; cin >> n >> m;
    vector<array<int, 3>>edge(m + 1);
    vector g(n + 1, vector<int>(n + 1, Max));
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    	edge[i] = {u, v, w};
    }
    for(int i = 1; i <= n; i++)g[i][i] = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int q; cin >> q;
    while(q--){
    	int k; cin >> k;
    	int res = Max;
        vector<int> t(k);
        vector<int> vis(k);
    	for(int j = 0; j < k; j++) cin >> t[j];
    	auto dfs = [&](auto self, int now, int last, int sum) -> void{
            // dbg(now, last, sum);
            if(now == k){
                if(last != n)sum += g[last][n];
                res = min(res, sum);
                return ;
            }
            for(int i = 0; i < k; i++){
                if(vis[i])continue;
                vis[i] = 1;
                auto [u, v, w] = edge[t[i]];
                if(v != last)self(self, now + 1, v, sum + g[last][u] + w);
                if(u != last)self(self, now + 1, u, sum + g[last][v] + w);
                vis[i] = 0;
            }
        };
        dfs(dfs, 0, 1, 0);
        cout << res << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}