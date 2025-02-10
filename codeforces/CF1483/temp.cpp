#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ULL;
using LL = long long;

mt19937_64 rd(time(0));
constexpr int N = 3e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

int min(int a, int b) { return a < b ? a : b; }
// int max(int a, int b) { return a > b ? a : b; }

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

int n, m, ans;
// int a[N];
void Sakuya()
{
    cin >> n;
    vector g(n + 1, vector<int>());
    vector<int>dp(n + 1);
    vector<int>dep(n + 1);
    for(int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto dfs = [&](auto self, int u, int f) -> void{
        dep[u] = dep[f] + 1;
        int maxn1 = 0, maxn2 = 0;
        for(auto v : g[u]){
            if(v == f)continue;
            self(self, v, u);
            if(maxn1 < dp[v]){
                maxn2 = maxn1;
                maxn1 = dp[v];
            }else if(maxn2 < dp[v]){
                maxn2 = dp[v];
            }
        }
        dp[u] = maxn1 + 1;
    };
    dfs(dfs, 1, 0);
    ans = *max_element(dep.begin() + 1, dep.end());
    auto dfs2 = [&](auto self, int u, int f, int mi, int mx) -> void{
        int mi1 = 1e9, mi2 = 1e9;
        int mx1 = 0, mx2 = 0;
        for(auto v : g[u]){
            if(v == f)continue;
            if(mx1 < dp[v] + dep[u]){
                mx2 = mx1;
                mx1 = dp[v] + dep[u];
            }else if(mx2 < dp[v] + dep[u]){
                mx2 = dep[u] + dp[v];
            }
            if(mi1 > dep[u] + dp[v]){
                mi2 = mi1;
                mi1 = dep[u] + dp[v];
            }else if(mi2 > dep[u] + dp[v]){
                mi2 = dep[u] + dp[v];
            }
        }
        for(auto v : g[u]){
            if(v == f)continue;
            int d = dp[v] + dep[u];
            int mii = mi;
            if(d == mi1)mii = min(mii, mi2);
            else mii = min(mii, mi1);
            int mxx = mx;
            if(d == mx1) mxx = max(mxx, mx2);
            else mxx = max(mxx, mx1);
            self(self, v, u, mii, mxx);
            int mxl = max(mx, dep[u] + 1);
            if(d == mx1)mxl = max(mxl, mx2);
            else mxl = max(mxl, mx1);

            int mil = mi;
            if(d == mi1) mil = min(mil, mi2);
            else mil = min(mil, mi1);
            ans = min(ans, max(mil + dp[v] - 1, mxl));
            // dbg(u, v, mi);
            
        }
        // dbg(u, ans);
    };
    dfs2(dfs2, 1, 0, 1e9, 0);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();

}