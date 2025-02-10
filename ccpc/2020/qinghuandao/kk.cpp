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
    vector<int> f(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 2; i <= n; i++){
    	int x; cin >> x;
    	g[x].push_back(i);
    }
    vector<int> res;
    vector<int> dep(n + 1);
    int tot = 2 * (n - 1);
    int s = 0;
    auto dfs = [&](auto self, int now, int father) -> void{
    	
    	if(g[now].empty()){
    		// dbg(now, father, dep[now]);
    		res.push_back(dep[now]);
    		s += dep[now];
    	}
    	for(auto v : g[now]){
    		dep[v] = dep[now] + 1;
    		self(self, v, now);
    	}
    };
    dfs(dfs, 1, 0);
    int ans = 1e18;
    sort(res.begin(), res.end());
    int sum = 0;
    int sz = res.size() - 1;
    int last = 0;
    ans = s;
    // dbg(tot);
    for(int i = sz; i >= 0; i--){
    	last += res[i];
    	dbg(res[i]);
    	ans = min(ans, tot - last);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}