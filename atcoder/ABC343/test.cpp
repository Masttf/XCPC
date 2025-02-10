
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 3e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)
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

int n, m, a[N];

struct Node{
    int maxn1, maxn2, cnt1, cnt2; 
}tr[N << 2];

void pushup(int u){
    tr[u] = {0, 0, 0, 0};
    int maxn = max(tr[u << 1].maxn1, tr[u << 1 | 1].maxn1);
    tr[u].maxn1 = maxn;
    if(tr[u << 1].maxn1 == maxn)tr[u].cnt1 += tr[u << 1].cnt1;
	if(tr[u << 1 | 1].maxn1 == maxn)tr[u].cnt1 += tr[u << 1 | 1].cnt1;
    vector<PII>v(4);
    v.emplace_back(tr[u << 1].maxn1, tr[u << 1].cnt1);
    v.emplace_back(tr[u << 1].maxn2, tr[u << 1].cnt2);
    v.emplace_back(tr[u << 1 | 1].maxn1, tr[u << 1 | 1].cnt1);
    v.emplace_back(tr[u << 1 | 1].maxn2, tr[u << 1 | 1].cnt2);
    int maxnn = 0;
    for(int i = 0; i < 4; ++ i){
        if(v[i].fi == maxn)continue;
        maxnn = max(maxnn, v[i].fi);
    }
    tr[u].maxn2 = maxnn;
    for(int i = 0; i < 4; ++ i){
        if(v[i].fi == maxnn){
            tr[u].cnt2 += v[i].se;
        }
    }
}

void update(int u, int l, int r, int p, int z){
    if(l == r){
        tr[u].maxn1 = z;
        tr[u].cnt1 = 1;
        tr[u].maxn2 = 0;
        tr[u].cnt2 = 0;
        return;
    }
    if(p <= mid)update(u << 1, l, mid, p, z);
    else update(u << 1 | 1, mid + 1, r, p, z);
    pushup(u);
}

Node merge(Node x, Node y){
    Node res = {0, 0, 0, 0};
    
    int maxn = max(x.maxn1, y.maxn1);
    res.maxn1 = maxn;
    if(x.maxn1 == maxn)res.cnt1 += x.cnt1;
    if(y.maxn1 == maxn)res.cnt1 += y.cnt1;

    vector<PII>v(4);
    v.emplace_back(x.maxn1, x.cnt1);
    v.emplace_back(y.maxn1, y.cnt1);
    v.emplace_back(x.maxn2, x.cnt2);
    v.emplace_back(y.maxn2, y.cnt2);

    int maxnn = 0;
    
    for(int i = 0; i < 4; ++ i){
        if(v[i].fi == maxn)continue;
        maxnn = max(maxnn, v[i].fi);
    }

    res.maxn2 = maxnn;

    for(int i = 0; i < 4; ++ i){
        if(v[i].fi == maxnn)res.cnt2 += v[i].se;
    }

    return res;
}

Node query(int u, int l, int r, int x, int y){
    dbg(l,r);
    if(x <= l && y >= r){
        return tr[u];
    }
    Node res = {0, 0, 0, 0};
    if(x <= mid)res = merge(res, query(u << 1, l, mid, x, y));
    if(y > mid)res = merge(res, query(u << 1 | 1, mid + 1, r, x, y));
    dbg(l,r,res.maxn1,res.cnt1,res.maxn2,res.cnt2);
    return res;
}

void build(int u, int l, int r){
    if(l == r){
        tr[u].maxn1 = a[l];
        tr[u].cnt1 = 1;
        tr[u].maxn2 = 0;
        tr[u].cnt2 = 0;
        return;
    }
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void Sakuya()
{
    cin >> n >> m;  

    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }  

    build(1, 1, n);
    for(int i = 1; i <= m; ++ i){
        int op, l, r, p, x;
        cin >> op;
        if(op == 1){
            cin >> p >> x;
            update(1, 1, n, p, x);
        }else {
            cin >> l >> r;
            Node ans = query(1, 1, n, l, r);
            cout << ans.cnt2 << "\n";
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