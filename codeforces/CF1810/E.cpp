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
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u); 
    }
    vector<int> vis(n + 1), v(n + 1);
    auto run = [&](int s, int k) -> int{
    	int cnt = 0;
    	set<pair<int, int>> q;
    	q.insert({a[s], s});
    	while(!q.empty() && (*q.begin()).first <= cnt){
    		auto [w, u] = *q.begin();
    		q.erase(q.begin());
    		v[u] = k;
    		vis[u] = 1;
    		cnt++;
    		for(auto V : g[u]){
    			if(v[V] == k)continue;
    			q.insert({a[V], V});
    		}
    	}
    	return cnt == n;
    };
    int ok = 0;
    int tot = 0;
    for(int i = 1; i <= n; i++){
    	if(a[i] == 0 && !vis[i]){
    		tot++;
    		ok |= run(i, tot);
    	}
    }
    if(ok)cout << "YES\n";
    else cout << "NO\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}