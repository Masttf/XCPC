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
using pii = pair<int, int>;
void solve(){
    int n, m, K; cin >> n >> m >> K;
    K--;
    vector<vector<pair<int, int>>>g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    vector dp(n + 1, vector<int>(1 << K, Max));
    for(int i = 1; i <= K; i++){
        dp[i][1 << (i - 1)] = 0;
    }
    auto dijsktra = [&](int s) -> void{
        priority_queue<pii, vector<pii>, greater<pii>>q;
        for(int i = 1; i <= n; i++){
            if(dp[i][s] != Max){
                q.push({dp[i][s], i});
            }
        }
        while(!q.empty()){
            auto [val, u] = q.top();
            q.pop();
            if(val > dp[u][s])continue;
            for(auto [v, w] : g[u]){
                if(dp[v][s] > val + w){
                    dp[v][s] = val + w;
                    q.push({dp[v][s], v});
                }
            }
        }
    };
    for(int i = 1; i < (1 << K); i++){
        for(int s = i; s != 0; s = i & (s - 1)){
            for(int j = 1; j <= n; j++){
                dp[j][i] = min(dp[j][i], dp[j][s] + dp[j][i ^ s]);
            }
        }
        dijsktra(i);
    }
    for(int i = K + 1; i <= n; i++){
        cout << dp[i][(1 << K) - 1] << '\n';
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