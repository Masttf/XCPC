#include <bits/stdc++.h>

using namespace std;
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
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 3e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)
mt19937_64 rd(time(0));

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int ksm(int a, int b){
   int res = 1;
   while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Node{
    int op;
    int x;
}Q[N];

int n, k;
vector<int>tr[N << 2];
int last[N];
int a[N], b[N];
int tot, bn;
int fa[N];
int p[N], siz[N];
stack<PII>stk;
set<int>s;
int ans[N];
int find(int x){
    while(fa[x] != x)x = fa[x];
    return fa[x];
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y)return;
    if(siz[x] > siz[y])swap(x, y);
    // dbg(x, y);
    stk.emplace(x, y);
    siz[y] += siz[x];
    fa[x] = y;
}

void insert(int u, int l, int r, int x, int y, int val){
    if(x <= l && y >= r){
        tr[u].emplace_back(val);
        return;
    }
    if(x <= mid)insert(u << 1, l, mid, x, y, val);
    if(y > mid)insert(u << 1 | 1, mid + 1, r, x, y, val);
}

void dfs(int u, int l, int r){
    // dbg(l, r);
    int tp = stk.size();
    for(auto i : tr[u]){
        s.insert(i);
        auto it = s.find(i);
        ++ it;
        if(it != s.end()){
            if(b[*it] - b[i] <= k){
                merge(*it, i);
            }
        }
        -- it;
        if(it != s.begin()){
            -- it;
            if(b[i] - b[*it] <= k){
                merge(i, *it);
            }
        }
    }

    if(l == r){
        if(Q[l].op == 2){
            // dbg(Q[l].x, siz[find(Q[l].x)]);
            ans[l] = siz[find(Q[l].x)];
        }
    }else {
        dfs(u << 1, l, mid);
        dfs(u << 1 | 1, mid + 1, r);
    }

    for(auto i : tr[u])s.erase(i);
    while(stk.size() > tp){
        auto [x, y] = stk.top();stk.pop();
        siz[y] -= siz[x];
        fa[x] = x;
    }
}

void Sakuya()
{
    cin >> n >> k;

    for(int i = 1; i <= n; ++ i)siz[i] = 1, fa[i] = i;

    for(int i = 1; i <= n; ++ i){
        int op, x;
        cin >> op >> x;
        Q[i] = {op, x};
        if(op == 1)b[ ++ tot] = x;
    }
    sort(b + 1, b + 1 + tot);
    bn = unique(b + 1, b + 1 + tot) - b - 1;

    for(int i = 1; i <= n; ++ i){
        auto [op, x] = Q[i];
        // if(op == 1){
        //     Q[i].x = lower_bound(b + 1, b + 1 + bn, Q[i].x) - b;
        //     // cout << Q[i].x << "\n";
        // }
        Q[i].x = lower_bound(b + 1, b + 1 + bn, Q[i].x) - b;
    }

    for(int i = 1; i <= n; ++ i){
        auto [op, x] = Q[i];
        if(op == 1){
            if(!last[x])last[x] = i;
            else {
                // dbg(last[x], i - 1);
                insert(1, 1, n, last[x], i - 1, x);
                last[x] = 0;
            }
        }
    }

    for(int i = 1; i <= n; ++ i){
        if(last[i]){
            // dbg(last[i], n, i);
            insert(1, 1, n, last[i], n, i);
        }
    }

    dfs(1, 1, n);

    for(int i = 1; i <= n; ++ i){
        auto [op, x] = Q[i];
        if(op == 2){
            cout << ans[i] << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();

}