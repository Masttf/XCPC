#include<bits/stdc++.h>
// #define int long long
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
struct MCFGraph {
    //#define int long long
    static constexpr int inf = 1e9;
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> h, dis;
    vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                auto[v, c, f] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != inf;
    }
    MCFGraph(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int c, int f) {
        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }
    pair<int, int> flow(int s, int t) {
        int flow = 0;
        int cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return {flow, cost};
    }
};
constexpr int maxn = 1e5 + 5;
array<int, 3> res[maxn];
int tot = 0;
vector<int> prim;
bool vis[maxn];
void init(){
    for(int i = 2; i < maxn; i++){
        if(!vis[i]){
            vis[i] = 1;
            prim.push_back(i);
        }
        for(int j = 0; prim[j] * i < maxn; j++){
            vis[i * prim[j]] = 1;
            if(i % prim[j] == 0)break;
        }
    }
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<int, int> mp;
    int t = n;
    vector<int>p(40);
    vector<int>pw(40);
    int sz = 0;
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        sz = 0;
        int num = 0;
        auto dfs = [&](auto self, int step, int now, int w) -> void{
            if(num > n)return ;
            if(step > sz){
                if(!mp.count(now))mp[now] = ++t;
                num++;
                res[++tot] = {i, mp[now], w - cnt};
                return ;
            }
            self(self, step + 1, now, w);
            for(int j = 1; j <= pw[step]; j++){
                now *= p[step];
                self(self, step + 1, now, w + j);
            }
        };
        int x = a[i];
        p.assign(40, 0);
        pw.assign(40, 0);
        for(auto j : prim){
            if(j > x)break;
            if(x % j == 0){
                p[++sz] = j;
                while(x % j == 0){
                    pw[sz]++;
                    x /= j;
                    cnt++;
                }
            }
        }
        if(x != 1){
            p[++sz] = x;
            pw[sz] = 1;
            cnt++;
        }
        dfs(dfs, 1, 1, 0);
    }
    t++;
    int s = 0;
    MCFGraph f(t + 1);
    for(int i = 1; i <= n; i++){
        f.addEdge(s, i, 1, 0);
    }
    for(auto [x, y] : mp){
        f.addEdge(y, t, 1, 0);
    }
    for(int i = 1; i <= tot; i++){
        auto [u, v, w] = res[i];
        f.addEdge(u, v, 1, w);
    }
    auto [flow, cost] = f.flow(s, t);
    cout << -cost << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    // cin >> t;
    while(t--)solve();
    return 0;
}