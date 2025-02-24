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
    vector <int> du (n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	du[u]++;
    	du[v]++;
    }
    priority_queue<pair<int,int>>q;
    for (int i = 1;i <= n;i++) {
    	q.push({val[i],i});
    }
    if (n == 1) {
    	cout << val[1] << '\n';
    	return ;
    }
    vector <int> vis(n + 5);
    int ans = 0,ok = 0;
    while (!q.empty()) {
    	auto [v,p] = q.top();
    	q.pop();
    	if (du[p] == 1) {
    		if (vis[g[p][0]] || ok) {
    			ans = v;
    			break;
    		}
            ok = 1;
    		vis[g[p][0]] = 1;
    	}
    	else {
    		ans = v;
    		break;
    	}
    }
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