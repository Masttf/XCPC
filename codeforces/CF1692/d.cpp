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
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int N = n * 3;
    vector g(N + 1, vector<pair<int, int>>());
    for(int i = 1; i <= n; i++){
    	g[i + n].push_back({i, 0});
    	g[i + 2 * n].push_back({i, 0});
    }
    vector<int> stk;
    for(int i = 1; i <= n; i++){
    	while(!stk.empty() && a[stk.back()] > a[i]){
    		stk.pop_back();
    	}
    	if(!stk.empty()){
    		dbg(stk.back(), i);
    		g[stk.back()].push_back({i + n, 1});
    		g[stk.back() + n].push_back({i + n, 0});
    	}
    	stk.push_back(i);
    }
    stk.clear();
    for(int i = 1; i <= n; i++){
    	while(!stk.empty() && a[stk.back()] < a[i]){
    		stk.pop_back();
    	}
    	if(!stk.empty()){
    		dbg(stk.back(), i);
    		g[stk.back()].push_back({i + 2 * n, 1});
    		g[stk.back() + 2 * n].push_back({i + 2 * n, 0});
    	}
    	stk.push_back(i);
    }
    vector<int> dis(N + 1, inf);
    vector<int> vis(N + 1);
    deque<int> q;
    q.push_back(1);
    dis[1] = 0;
    while(!q.empty()){
    	int u = q.front();
    	q.pop_front();
    	if(vis[u])continue;
    	vis[u] = 1;
    	for(auto [v, w] : g[u]){
    		if(dis[v] > dis[u] + w){
    			dis[v] = dis[u] + w;
    			if(w == 0)q.push_front(v);
    			else q.push_back(v);
    		}
    	}
    }
    cout << dis[n] << '\n';
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