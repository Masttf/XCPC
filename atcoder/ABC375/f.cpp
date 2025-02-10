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
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<array<int, 3>> a(m + 1);
    for(int i = 1; i <= m; i++){
    	cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector dis(n + 1, vector<int>(n + 1, Max));
    for(int i = 1; i <= n; i++)dis[i][i] = 0;
    vector<array<int, 3>> Q(q + 1);
    vector<int> ans(q + 1, -1);
    vector<int> limit(m + 1);
    for(int i = 1; i <= q; i++){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int x; cin >> x;
    		Q[i] = {ty, x, x};
    		limit[x] = 1;
    	}else{
    		int x, y; cin >> x >> y;
    		Q[i] = {ty, x, y};
    	}
    }
    auto run = [&](int x) -> void{
    	auto [u, v, w] = a[x];
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				dis[j][k] = min(dis[j][k], dis[min(j, u)][max(j, u)] + dis[min(v, k)][max(v, k)] + w);
				dis[j][k] = min(dis[j][k], dis[min(j, v)][max(j, v)] + dis[min(u, k)][max(u, k)] + w);
			}
		}
    };
    for(int i = 1; i <= m; i++){
    	// dbg(i);
    	if(!limit[i]){
    		auto [u, v, w] = a[i];
    		dis[u][v] = w;
    		dis[v][u] = w;
    	}
    }
    for(int k = 1; k <= n; k++){
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= n; j++){
    			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    		}
    	}
    }
    // dbg("????");
    for(int i = q; i >= 1; i--){
    	auto [ty, l, r] = Q[i];
    	if(ty == 1){
    		run(l);
    	}else{
    		ans[i] = dis[l][r];
    	}
    }
    for(int i = 1; i <= q; i++){
    	if(ans[i] == -1)continue;
    	if(ans[i] == Max)cout << -1 << '\n';
    	else cout << ans[i] << '\n';
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