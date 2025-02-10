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
    int n, m; cin >> n >> m;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
   	vector<vector<pair<int, int>>>g(n + 1);
   	for(int i = 1; i <= m; i++){
   		int u, v, w; cin >> u >> v >> w;
   		g[u].push_back({v, w});
   		g[v].push_back({u, w});
   	}
   	vector<int> dis(n + 1, Max);
   	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
   	dis[1] = a[1];
   	q.push({dis[1], 1});
   	while(!q.empty()){
   		auto [ww, u] = q.top();
   		q.pop();
   		if(ww > dis[u])continue;
   		for(auto [v, w] : g[u]){
   			if(dis[v] > dis[u] + w + a[v]){
   				dis[v] = dis[u] + w + a[v];
   				q.push({dis[v], v});
   			}
   		}
   	}
   	for(int i = 2; i <= n; i++){
   		cout << dis[i] << " \n"[i == n];
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