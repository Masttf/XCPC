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
    int n, m, k; cin >> n >> m >> k;
    int K = min(50ll, k);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    }
    int ok = 1;
    vector dis(K + 1, vector<int>(n + 1));
    auto bfs = [&](int color) -> void{
    	for(int i = 1; i <= K; i++){
    		for(int j = 1; j <= n; j++){
    			dis[i][j] = 0;
    		}
    	}
    	queue<pair<int, int>> q;
    	for(int i = 1; i <= n; i++){
    		if(a[i] == color){
    			dis[1][i] = i;
    			q.push({1, i});
    		}
    	}
    	while(!q.empty()){
    		auto [d, u] = q.front();
    		q.pop();
    		if(d >= K) continue;
    		for(auto v : g[u]){
    			if(dis[d + 1][v] == 0){
    				dis[d + 1][v] = dis[d][u];
    				q.push({d + 1, v});
    			}else if(dis[d + 1][v] != dis[d][u]){
    				dis[d + 1][v] = -1;
    			}
    			if(a[v] == color && dis[d + 1][v] != v) ok = 0;
    		}
    	}
    };

    for(int i = 1; i <= 50; i++){
    	bfs(i);
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
/*
3
3 2 2
1 2 1
1 2
2 3
3 3 2
1 2 1
1 2
2 3
1 3
3 3 50
1 1 2
1 2
2 3
1 3
*/