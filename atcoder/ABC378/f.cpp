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
    vector<vector<int>> g(n + 1);
    vector<int> du(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	du[u]++;
    	du[v]++;
    }
    vector<array<int, 4>> dp(n + 1);
    vector<array<int, 4>> fdp(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		if(du[v] == 3){
    			dp[now][3] += dp[v][3] + fdp[v][3];
    			dp[now][2] += dp[v][2] + fdp[v][2];
    		}
    		fdp[now][min(3ll, du[v])]++;
    	}
    };
    dfs(dfs, 1, 0);
    int ans = 0;
    auto dfs1 = [&](auto self, int now, int father) -> void{
    	if(du[now] == 2){
    		ans += dp[now][2];
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		if(du[v] == 3){
    			dp[now][3] -= dp[v][3] + fdp[v][3];
    			dp[now][2] -= dp[v][2] + fdp[v][2];
    		}
    		fdp[now][min(3ll, du[v])]--;
    		fdp[v][min(3ll, du[now])]++;
    		if(du[now] == 3){
    			dp[v][3] += dp[now][3] + fdp[now][3];
    			dp[v][2] += dp[now][2] + fdp[now][2];
    		}
    		
    		self(self, v, now);
    		if(du[now] == 3){
    			dp[v][3] -= dp[now][3] + fdp[now][3];
    			dp[v][2] -= dp[now][2] + fdp[now][2];
    		}
    		fdp[now][min(3ll, du[v])]++;
    		fdp[v][min(3ll, du[now])]--;
    		if(du[v] == 3){
    			dp[now][3] += dp[v][3] + fdp[v][3];
    			dp[now][2] += dp[v][2] + fdp[v][2];
    		}
    	}
    };
    dfs1(dfs1, 1, 0);
    ans /= 2;
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