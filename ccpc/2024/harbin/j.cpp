#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;
// int mod = 998244353;
const int mod = 998244353;
const int modd = 1e9 + 7;
#define ll long long
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<db, db>
#define vct vector
#define vi vct<int>
#define vl vct<ll>
#define str string
#define mset multiset
#define pq priority_queue
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define of(i, l, r) for (int i = l; i >= r; i--)
#define fi first
#define se second
#define in insert
#define er erase
#define ct count
#define pb push_back
#define pf push_front
#define lowb lower_bound
#define upb upper_bound
#define sz size()
#define cl clear()
#define em empty()
#define be begin()
#define en end()
#define fr front()
#define bk back()
#define pp pop()
#define ppb pop_back()
#define ppf pop_front()
#define S s = " " + s
#define SS s[i] = " " + s[i]
#define all(g) g.be, g.en
#define mem(a, x) memset(a, x, sizeof(a))
#define sp(x) cout << fixed << setprecision(x)
#define M(x) x %= mod;if(x < 0) x += mod
#define ANS cout << ans << '\n'
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define rty return
#define ind " \n"[i == n]
#define jnd " \n"[j == n]
#define knd " \n"[k == n]
#define imd " \n"[i == m]
#define jmd " \n"[j == m]
#define kmd " \n"[k == m]
#define GG g[u].pb(v), g[v].pb(u)
#define GGG g[u].pb({v, w}), g[v].pb({u, w})
#define cmx(x, y) x = max(x, y)
#define cmi(x, y) x = min(x, y)
int bg = 1;
#define print(x...) if(bg) cout << #x << "=", oo(x);
void oo()
{
    cout << '\n';
}
template<class A, class...B>
void oo (A a, B...b)
{
    cout << a << ',';
    oo (b...);
}
const db pi = acos (-1.0);
// ax+by=(+-)g
// x=x0+b/g*k
// y=y0-a/g*k
ll exgcd (ll a, ll &x, ll b, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        rty a;
    }
    ll tt = exgcd (b, y, a % b, x);
    y -= a / b * x;
    rty tt;
}
ll gcd (ll a, ll b)
{
    rty b ? gcd (b, a % b) : a;
}
ll qp (ll a, ll b)
{
    ll s = 1;
    while (b > 0)
    {
        if (b & 1)
            s = (s * a) % mod;
        b >>= 1, a = (a * a) % mod;
    }
    rty s;
}
ll ny (ll a)
{
    // ll x, y;
    // if (exgcd(a, x, P, y) == 1)
    //     rty (x % P + P) % P;
    // else
    //     rty -1;
    rty qp (a, mod - 2);
}
//const int X = 1e6 + 5;
//ll fc[X], nn[X], ifc[X];
//void CC()
//{
//    fc[0] = nn[0] = ifc[0] = 1;
//    fo (i, 1, X - 2) fc[i] = fc[i - 1] * i % mod;
//    ifc[X - 2] = ny (fc[X - 2]);
//    of (i, X - 2 - 1, 1) ifc[i] = ifc[i + 1] * (i + 1) % mod;
//    fo (i, 1, X - 2) nn[i] = ifc[i] * fc[i - 1] % mod;
//}
//ll C (int n, int m)
//{
//    if (n < m || n < 0 || m < 0)
//        rty 0;
//    rty fc[n] * ifc[m] % mod * ifc[n - m] % mod;
//}
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
ll MAX = 0x3f3f3f3f3f3f3f3fll;
ll MIN = -MAX;
ll t, n, m, k, x, y, z, u, v, w, l, r, mid, tt, qq, ff, ok, T, mx, mi, op, pos, len, sum, ans;

void CL()
{
    ans = sum = len = ff = tt = ok = x = y = z = n = m = k = t = 0, mi = MAX, mx = MIN;
    rty;
}
const int N = 1e6 + 5;
ll a[N];
ll c[N];
pll b[N];
void solve()
{
    cin >> n >> m;
    fo (i, 1, n)
    {
        cin >> a[i];
        c[i] = a[i];
    }
    set<pll>st;
    fo (i, 1, m)
    {
        cin >> x >> t;
        b[i] = {x, t};
        st.in ({x, t});
    }
    fo (i, 1, n)
    {
        st.in ({1e18, i});
    }
    vl pos (m + 1, 1e18);
    map<ll, ll>mp;
    of (i, m, 1)
    {
        auto [x, t] = b[i];
        if (mp.ct (t) )
            pos[i] = mp[t];
        mp[t] = x;
    }
    ll now = 0;
    fo (i, 1, m)
    {
        auto [x, t] = b[i];
        while ( (*st.be).fi <= now) st.er (st.be);

        while (now < x && !st.em)
        {
            auto [x2, t2] = *st.be;
            ll use = min (x - now, a[t2]);
            a[t2] -= use;
            now += use;
            if (!a[t2])
                st.er (st.be);
        }
        if (now < x)
        {
            break;
        }
        a[t] = c[t];
        st.in ({pos[i], t});
    }
    fo (i, 1, n) now += a[i];
    cout << now << '\n';
    rty;
}

signed main()
{
    // bg = 0;
    // CC();
    // shai();
    // init();
    ios::sync_with_stdio (0), cin.tie (0), cout.tie (0);
    sp (12);
    cin >> T; while (T--)
    {
        CL();
        solve();
    }
    rty 0;
}