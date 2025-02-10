#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define lc (p << 1)
#define rc (p << 1 | 1)
const int N = 1e5 + 9;
#define int long long
struct tree
{
    ll l, r, val, add;
} a[4 * N];
void pushup(int p)
{
    a[p].val = a[lc].val | a[rc].val;
}
void pushdown(int p)
{
    if (a[p].add)
    {
        a[lc].val |= a[p].add, a[rc].val |= a[p].add;
        a[lc].add |= a[p].add, a[rc].add |= a[p].add;
        a[p].add = 0;
    }
}
void build(int p, int l, int r)
{
    a[p] = {l, r, 0, 0};
    if (l == r)
        return;
    int m = l + r >> 1;
    build(lc, l, m), build(rc, m + 1, r);
    pushup(p);
}
void updata(int p, int x, int y, ll k)
{
    if (x <= a[p].l && a[p].r <= y)
    {
        a[p].val |= k;
        a[p].add |= k;
        return;
    }
    pushdown(p);
    int m = a[p].l + a[p].r >> 1;
    if (x <= m)
        updata(lc, x, y, k);
    if (y > m)
        updata(rc, x, y, k);
    pushup(p);
}
ll query(int p, int x, int y)
{
    if (x <= a[p].l && a[p].r <= y)
        return a[p].val;
    pushdown(p);
    int m = a[p].l + a[p].r >> 1;
    ll res = 0;
    if (x <= m)
        res |= query(lc, x, y);
    if (y > m)
        res |= query(rc, x, y);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        build(1, 1, n);
        while (m--)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int x, y, c;
                cin >> x >> y >> c;
                updata(1, x, y, 1ll << c);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                ll t = query(1, l, r);
                int ans = 0;
                while (t)
                {
                    if (t & 1)
                        ans++;
                    t >>= 1;
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}