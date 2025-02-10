#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int inf = 1e18;
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };
    
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    
    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n+1, {});
        cur.resize(n+1);
        h.resize(n+1);
    }
    
    bool bfs(int s, int t) {
        h.assign(n+1, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < (int)g[u].size(); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n+1, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
    
    std::vector<bool> minCut() {
        std::vector<bool> c(n+1);
        for (int i = 1; i <= n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    
    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>f(n+1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=a[i])f[i]=max(f[i],f[j]+1);
        }
    }
    int mx=*max_element(f.begin()+1,f.end());
    if(mx==1){
        cout<<1<<'\n'<<n<<'\n'<<n<<'\n';
        return ;
    }
    MaxFlow<int> g1(2*n+1);
    for(int i=1;i<=n;i++){
        g1.addEdge(i,i+n,1);
        if(f[i]==1){
            g1.addEdge(0,i,1);
        }
        if(f[i]==mx){
            g1.addEdge(i+n,2*n+1,1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]&&f[j]+1==f[i]){
                g1.addEdge(j+n,i,1);
            }
        }
    }
    int res1=g1.flow(0,2*n+1);
    MaxFlow<int> g2(2*n+1);
    for(int i=1;i<=n;i++){
        if(i==1||i==n){
            g2.addEdge(i,i+n,inf);
        }else g2.addEdge(i,i+n,1);
        if(f[i]==1){
            if(i==1||i==n)g2.addEdge(0,i,inf);
            else g2.addEdge(0,i,1);
        }
        if(f[i]==mx){
            if(i==1||i==n)g2.addEdge(i+n,2*n+1,inf);
            else g2.addEdge(i+n,2*n+1,1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]&&f[j]+1==f[i]){
                g2.addEdge(j+n,i,1);
            }
        }
    }
    int res2=g2.flow(0,2*n+1);
    cout<<mx<<'\n'<<res1<<'\n'<<res2<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}