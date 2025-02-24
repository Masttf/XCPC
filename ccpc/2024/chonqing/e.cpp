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
    vector<vector<int>> g(n + 1);
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    if(n == 1){
    	cout << val[1] << '\n';
    	return ;
    }
    for(int i = 1; i <= n; i++){
    	sort(g[i].begin(), g[i].end(), [&](int x, int y) -> bool{
    		return val[x] > val[y];
    	});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(g[i].size() >= 2){
    		ans = max(ans, val[i]);
    	}
    }
    // dbg(ans);
    vector<int> res;
    for(int i = 1; i <= n; i++){
    	if(g[i].size() == 1){
    		res.push_back(val[i]);
    	}
    }
    sort(res.begin(), res.end(), greater<>());
    if(res.size() >= 2)ans = max(ans, res[1]);
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