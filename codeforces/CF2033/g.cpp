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
    vector<vector<int>>g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<array<int, 3>> p(n + 1);
    for(int i = 1; i <= n; i++){
    	p[i] = {i, i, 0};
    }
    vector f(21, vector<int>(n + 1));
    vector<int> dep(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	f[0][now] = father;
    	dep[now] = dep[father] + 1;
    	for(int i = 1; i <= 20; i++){
    		f[i][now] = f[i - 1][f[i - 1][now]];
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		array<int, 4> temp = {p[now][0], p[now][1], p[v][0], p[v][1]};
    		if(p[v][2] > p[now][2]){
    			p[now] = p[v];
    		}
    		for(int i = 0; i < 2; i++){
    			for(int j = 2; j < 4; j++){
    				int dis = dep[temp[i]] + dep[temp[j]] - 2 * dep[now];
    				if(dis > p[now][2]){
    					p[now] = {temp[i], temp[j], dis};
    				}
    			}
    		}
    	}
    	// dbg(now);
    	// dbg(p[now][0], p[now][1], p[now][2]);
    };
    dfs(dfs, 1, 1);

    auto lca = [&](int a, int b) -> int {
    	if(dep[a] < dep[b])swap(a, b);
    	for(int i = 20; i >= 0; i--){
    		if(dep[a] - (1ll << i) >= dep[b]){
    			a = f[i][a];
    		}
    	}
    	if(a == b)return a;
    	for(int i = 20; i >= 0; i--){
    		if(f[i][a] != f[i][b]){
    			a = f[i][a];
    			b = f[i][b];
    		}
    	}
    	return f[0][a];
    };
    auto getDis = [&](int x, int y) -> int{
    	int fa = lca(x, y);
    	return dep[x] + dep[y] - 2 * dep[fa];
    };
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int v, k; cin >> v >> k;
    	int fa = v;
    	for(int j = 20; j >= 0; j--){
    		if(k >> j & 1){
    			fa = f[j][fa];
    		}
    	}
    	// dbg(v, k, fa);
    	int ans = max(getDis(p[fa][0], v), getDis(p[fa][1], v));
    	cout << ans << ' ';
    }
    cout << '\n';
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