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
constexpr int inf = 1e18;
constexpr int N = 1005;
void solve(){
    int n; cin >> n;
    int s1, s2; cin >> s1 >> s2;
    vector g1(n + 1, vector<int>());
    vector g2(n + 1, vector<int>());
    int m1; cin >> m1;
    for(int i = 1; i <= m1; i++){
    	int u, v; cin >> u >> v;
    	g1[u].push_back(v);
    	g1[v].push_back(u);
    }
    int m2; cin >> m2;
    for(int i = 1; i <= m2; i++){
    	int u, v; cin >> u >> v;
    	g2[u].push_back(v);
    	g2[v].push_back(u);
    }
    // dbg("yes", s1, s2, m1, m2);
    vector dis(n + 1, vector<int>(n + 1, inf));
    auto dij = [&]() -> void{
    	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    	dis[s1][s2] = 0;
    	q.push({dis[s1][s2], s1, s2});
    	while(!q.empty()){
    		auto [w, u1, u2] = q.top();
    		q.pop();
    		if(w > dis[u1][u2])continue;
    		// dbg(u1, u2, w);
    		for(auto v1 : g1[u1]){
    			for(auto v2 : g2[u2]){
    				int d = abs(v1 - v2);
    				if(w + d < dis[v1][v2]){
    					dis[v1][v2] = w + d;
    					q.push({dis[v1][v2], v1, v2});
    				}
    			}
    		}
    	}
    };
    dij();
    int ans = inf;
    vector<bitset<N>> to1(n + 1), to2(n + 1);

    for(int i = 1; i <= n; i++){
    	for(auto v1 : g1[i]){
    		to1[i][v1] = 1;
    	}
    	for(auto v2 : g2[i]){
    		to2[i][v2] = 1;
    	}
    }
    for(int i = 1; i <= n; i++){
    	bitset<N> tmp = to1[i] & to2[i];
    	if(tmp.count()){
    		// dbg(i, i, dis[i][i]);
    		ans = min(ans, dis[i][i]);
    	}
    }
    if(ans == inf)cout << -1 << '\n';
    else cout << ans << '\n';
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
无限次，也就是要去到一个代价和是0
相同编号

*/