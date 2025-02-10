
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 2e6 + 5, mod = 998244353;
constexpr double eps = 1e-8;
#define fi first
#define se second
//#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

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

int n, m, c, col[N], root[N], pos1[N], pos2[N], tot, rt;

int tr[N * 32], ls[N * 32], rs[N * 32];
void update(int &u, int v, int l, int r, int p, int k){
    u = ++ tot;
    tr[u] = tr[v] + k;
    ls[u] = ls[v], rs[u] = rs[v];
    if(l == r)return;
    if(p <= mid)update(ls[u], ls[v], l, mid, p, k);
    else update(rs[u], rs[v], mid + 1, r, p, k);
}   

int query(int u, int l, int r, int p){
    if(l == r)return tr[u];
    if(p <= mid)return tr[rs[u]] + query(ls[u], l, mid, p);
    else return query(rs[u], mid + 1, r, p);
}

void Sakuya()
{
    cin >> n >> c >> m;
    for(int i = 1; i <= n; ++ i)cin >> col[i];

    for(int i = 1; i <= n; ++ i){
        if(!pos1[col[i]]){
        	update(root[i], root[i - 1], 1, n, i, 0);
            pos1[col[i]] = i;
        }else {
            if(!pos2[col[i]]){
                update(root[i], root[i - 1], 1, n, pos1[col[i]], 1);
                pos2[col[i]] = i;//出现了第二个才开始算第一个的贡献
            }else {
                update(rt, root[i - 1], 1, n, pos1[col[i]], -1);
                update(root[i], rt, 1, n, pos2[col[i]], 1);
                pos1[col[i]] = pos2[col[i]];
                pos2[col[i]] = i;
            }
        }
    }
    while(m --){
        int l, r;
        cin >> l >> r;
        cout << query(root[r], 1, n, l) << "\n";
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
