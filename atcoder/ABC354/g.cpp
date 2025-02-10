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
struct Max_Flow{
    //#define int long long
    static constexpr int inf = 1e18;
    struct node{
        int v, w;
    };
    int n;
    vector<node> e;
    vector<vector<int>> g;
    vector<int> h, cur;
    Max_Flow(int n){
        init(n);
    }
    void add(int u, int v, int w){
        g[u].push_back(e.size());
        e.push_back({v, w});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs (int s, int t){
        h.assign(n, -1);
        queue<int> q;
        h[s]=0;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto i : g[u]){
                auto [v, w] = e[i];
                if(h[v] == -1 && w){
                    h[v] = h[u] + 1;
                    if(v == t){
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int val){
        if(u == t)return val;
        int res = val;
        for(auto &i = cur[u]; i < (int)g[u].size(); i++){
            int j = g[u][i];
            auto [v, w] = e[j];
            if(w > 0 && h[v] == h[u] + 1){
                int d = dfs(v, t, min(res, w));
                e[j].w -= d;
                e[j ^ 1].w += d;
                res -= d;
                if(res == 0)return val;
            }
        }
        return val - res;
    }
    int flow(int s, int t){
        int ans = 0;
        while(bfs(s, t)){
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
    vector<int> mincut(){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(h[i] != -1)res.push_back(i);
        }
        return res;
    }
    vector<int> get_mincut_edge(){
        vector<int> res;
        for(int i = 0; i < e.size(); i += 2){
            int u = e[i + 1].v;
            int v = e[i].v;
            if(h[u] != -1 && h[v] == -1){
                res.push_back(u);
            }
        }
        return res;
    }
};
constexpr int inf = 1e18;
void solve(){
    int n; cin >> n;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += val[i];
    int s = 0, t = 2 * n + 1;
    Max_Flow flow(t + 1);
    for(int i = 1; i <= n; i++){
        flow.add(s, i, val[i]);
        flow.add(n + i, t, val[i]);
    }
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i] == a[j]){
                flow.add(i, n + j, inf);
                continue;
            }
            if(a[i].find(a[j]) != -1){
                flow.add(i, n + j, inf);
            }
            if(a[j].find(a[i]) != -1){
                flow.add(j, n + i, inf);
            }
		}
	}
	ans -= flow.flow(s, t);
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