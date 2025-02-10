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
    vector<vector<int>>g(n + 1, vector<int>(n + 1));
    vector<vector<int>>h(n + 1, vector<int>(n + 1));
    int m; cin >> m;
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u][v] = 1;
    	g[v][u] = 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	h[u][v] = 1;
    	h[v][u] = 1;
    }
    vector<vector<int>>val(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = i + 1; j <= n; j++){
    		cin >> val[i][j];
    		val[j][i] = val[i][j];
    	}
    }
    // for(int i = 1; i <= n; i++){
    // 	for(int j = 1; j <= n; j++){
    // 		cout << val[i][j] << ' ';
    // 	}
    // 	cout << endl;
    // }
    int ans = 1e18;
    vector<int>res(n + 1);
    for(int i = 1; i <= n; i++)res[i] = i;
    do{
    	// for(int i = 1; i <= n; i++){
    	// 	cout << res[i] << ' ';
    	// }
    	// cout << endl;
    	int rst = 0;
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= n; j++){
    			int a = res[i];
    			int b = res[j];
    			if(g[i][j] != h[a][b])rst += val[a][b];
    		}
    	}
    	rst /= 2;
    	ans = min(ans, rst);
    }while(next_permutation(res.begin() + 1, res.end()));
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