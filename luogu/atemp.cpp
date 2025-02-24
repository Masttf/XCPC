#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 1e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#define fi first
#define se second
// #define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int ksm(int a, int b){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int n, m;
int a[N], tr[N], L[N], R[N], timestamp, siz[N], dep[N];
vector<int>g[N], d[N];
vector<PII>res[N];
int fa[N][21], q, ans[N * 10];
void init(){
    for(int i = 1; i < N; ++ i){
        for(int j = i; j < N; j += i){
            d[j].emplace_back(i);
        }
    }
    for(int i = 1; i < N; ++ i){
        int siz = d[i].size();
        for(int j = 0; j < siz; ++ j){
            for(int k = j; k < siz; ++ k){
                if(lcm(d[i][j], d[i][k]) == i){
                    res[i].emplace_back(d[i][j], d[i][k]);
                }
            }
        }
    }
}

void update(int x, int z){
    while(x <= n){
        tr[x] += z;
        x += lowbit(x);
    }
}

int query(int x){
    int res = 0;
    while(x){
        res += tr[x];
        x -= lowbit(x);
    }
    return res;
}

void dfs(int u, int f){
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    L[u] = ++ timestamp;
    a[timestamp] = u;
    for(int i = 1; (1LL << i) <= dep[u]; ++ i){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for(auto v : g[u]){
        if(v == f)continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    R[u] = timestamp;
}

int LCA(int x, int y){
    if(dep[x] < dep[y])swap(x, y);
    for(int i = 20; ~i; -- i){
        if(dep[x] - (1LL << i) >= dep[y]){
            x = fa[x][i];
        }
    }
    if(x == y)return x;
    for(int i = 20; ~i; -- i){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void Sakuya()
{
    cin >> n;
    for(int i = 2; i <= n; ++ i){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    cin >> q;
    // for(int i = 1; i <= q; ++ i){
    //     cin >> Q[i].r >> Q[i].x;
    //     Q[i].id = i;
    // }

    // sort(Q + 1, Q + 1 + q, [&](Node a, Node b){return a.x < b.x;});
    vector<vector<PII>>Q(N);
    for(int i = 1; i <= q; ++ i){
        int r, x;
        cin >> r >> x;
        Q[x].emplace_back(r, i);
    }
    
    for(int i = 1; i <= 1e5; ++ i){
        //if(!Q[i].size())continue;
        for(auto [u, v] : res[i]){
            if(u > n || v > n)continue;
            if(u != v){
                int lca = LCA(u, v);
                update(L[lca], 2);
            }else {
                update(L[u], 1);
            }
        }
        for(auto [r, id] : Q[i]){
            ans[id] = query(R[r]) - query(L[r] - 1);
        }
    }
    for(int i = 1; i <= q; ++ i){
        cout << ans[i] << " ";
    }

    for(int i = 1; i < N; ++ i)tr[i] = 0;
    for(int i = 1; i <= n; ++ i)g[i].clear();
    timestamp = 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    for (cin >> T; T -- ; )
        Sakuya();

}