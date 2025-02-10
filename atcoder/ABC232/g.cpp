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
    int n, M; cin >> n >> M;
    vector<int> a(n + 1);
    vector<pair<int, int>> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
    	cin >> b[i].first;
    	b[i].second = i;
    }
    sort(b.begin() + 1, b.end());
    int N = 3 * n;
    vector<vector<pair<int, int>>> g(N + 1);
    for(int i = 2; i <= n; i++){
    	g[n + i].push_back({n + i - 1, 0});
    }
    for(int i = 1; i < n; i++){
    	g[2 * n + i].push_back({2 * n + i + 1, b[i + 1].first - b[i].first});
    }
    for(int i = 1; i <= n; i++){
    	g[n + i].push_back({b[i].second, b[i].first});
    	g[2 * n + i].push_back({b[i].second, 0});
    }
    for(int i = 1; i <= n; i++){
    	int l = 1, r = n;
    	int c = 0;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(a[i] + b[mid].first < M){
    			c = mid;
    			l = mid + 1;
    		}else r = mid - 1;
    	}
    	if(c)g[i].push_back({n + c, a[i]});
    	if(c + 1 <= n)g[i].push_back({2 * n + c + 1, a[i] + b[c + 1].first - M});
    }
    vector<int> dis(N + 1, Max);
    auto dij = [&]() -> void{
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    	dis[1] = 0;
        q.push({dis[1], 1});
        while(!q.empty()){
            auto [W, u] = q.top();
            q.pop();
            if(W > dis[u])continue;
            for(auto [v, w] : g[u]){
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    };
    dij();
    cout << dis[n] << '\n';
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