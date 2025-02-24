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
    vector<int> p(n + 1);
    vector<int> need(n + 1), cost(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> p[i] >> need[i] >> cost[i];
    	if(i != 1)g[p[i]].push_back(i);
    }
    int ans = 0;
    vector<int> mi(n + 1);
    vector<int> num(n + 1);
    auto dfs = [&](auto self, int now) -> void{
    	mi[now] = cost[now];
    	for(auto v : g[now]){
    		self(self, v);
    		mi[now] = min(mi[now], mi[v]);
    		num[now] += num[v];
    	}
    	if(num[now] < need[now]){
    		ans += (need[now] - num[now]) * mi[now];
    		num[now] = need[now];
    	}
    };
    dfs(dfs, 1);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}