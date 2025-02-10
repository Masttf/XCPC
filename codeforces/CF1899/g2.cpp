#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
// int mod = 998244353;
// int modd = 1e9 + 7;
const int mod = 998244353;
const int modd = 1e9 + 7;
#define ll long long
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<db, db>
#define iter set<int>::iterator
#define lter set<ll>::iterator
#define vct vector
#define str string
#define mset multiset
#define umap unordered_map
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define of(i, l, r) for (int i = l; i >= r; i--)
#define inl inline
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
#define ppb pop_back()
#define ppf pop_front()
#define popf(x) x.er(x.be)
#define S s = " " + s
#define SS s[i] = " " + s[i]
#define all(g) g.be, g.en
#define lbt(x) ((x) & (-x))
#define mem(a, x) memset(a, x, sizeof(a))
#define sp(x) fixed << setprecision(x)
#define M(x) x %= mod, x += mod, x %= mod
#define ANS cout << ans << '\n'
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define print(x) cout << #x << '=' << x << '\n';
#define printt(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << '\n';
#define ied " \n"[i == n]
#define jed " \n"[j == n]
#define ked " \n"[k == n]
#define GG g[u].pb(v), g[v].pb(u)
const db pi = acos (-1.0);
// ax+by=gcd
// x=x0+b/gcd*k
// y=y0+a/gcd*k
inl ll exgcd (ll a, ll &x, ll b, ll &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll tt = exgcd (b, y, a % b, x);
	y -= a / b * x;
	return tt;
}
inl ll gcd (ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd (b, a % b);
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
	return s;
}
ll ny (ll a)
{
	// ll x, y;
	// if (exgcd(a, x, mod, y) == 1)
	//     return (x % mod + mod) % mod;
	// else
	//     return -1;
	return qp (a, mod - 2);
}
// const int X = 1e6 + 5;
// ll fc[X], nn[X], NN[X];
// void CC()
// {
//     fc[0] = nn[0] = NN[0] = 1;
//     fo(i, 1, X - 2) fc[i] = fc[i - 1] * i % mod;
//     NN[X - 2] = ny(fc[X - 2]);
//     of(i, X - 2 - 1, 1) NN[i] = NN[i + 1] * (i + 1) % mod;
//     fo(i, 1, X - 2) nn[i] = NN[i] * fc[i - 1] % mod;
// }
// ll C(int n, int m)
// {
//     if (n < m || n < 0 || m < 0)
//         return 0;
//     return fc[n] * NN[m] % mod * NN[n - m] % mod;
// }
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
ll MAX = 0x3f3f3f3f3f3f3f3fll;
ll MIN = -MAX;
ll t, n, m, k, x, y, z, u, v, w, l, r, mid;
ll tt, qq, ff, ok, T;
ll mx, mi, op, pos, len, sum, ans;

void CL()
{
	ans = sum = ff = tt = ok = mx = x = y = z = n = m = k = t = 0, mi = MAX;
	return;
}
const int N = 1e6 + 5;
int a[N], c[N];
//ll b[N], c[N];
//ll f[N], vis[N];
str s, ss;
vct<int> g[100005];
int ID;
int id[N], siz[N];
void dfs (int u, int f)
{
	id[u] = ++ID;
	siz[u] = 1;
	for (auto v : g[u])
	{
		if (v != f)
		{
			dfs (v, u);
			siz[u] += siz[v];
		}
	}
}
#define ul tr[u].l
#define ur tr[u].r
#define pl tr[p].l
#define pr tr[p].r
int Id;
int rt[N];
struct R
{
	int l, r, s;
} tr[N * 17];
void add (int &u, int p, int x, int l, int r)
{
	u = ++Id;
	tr[u] = tr[p], tr[u].s++;
	if (l == r)
		return;
	int m = l + r >> 1;
	if (x <= m)
		add (ul, pl, x, l, m);
	else
		add (ur, pr, x, m + 1, r);
}
int Q (int u, int p, int x, int l, int r)
{
	if (l == r)
		return tr[p].s - tr[u].s;
	int m = l + r >> 1;
	if (x <= m)
		return Q (ul, pl, x, l, m);
	else
		return Q (ur, pr, x, m + 1, r) + tr[pl].s - tr[ul].s;
} // 小于等于k个数 1, 不同个数 2
int find (ll x) { return lowb (c + 1, c + 1 + m, x) - c; }
// int p[N], nxt[N]; // 2
int QQ (int l, int r, int x)
{
	x = upb (c + 1, c + 1 + m, x) - c - 1; // 删c[], 1 2
	return Q (rt[l - 1], rt[r], x, 0, m);
}
void solve()
{
	cin >> n >> qq;
	fo (i, 1, n)
	{
		g[i].cl;
	}
	fo (i, 1, n) rt[i] = 0;
	fo (i, 1, ID) tr[i].s = 0;
	ID = Id = 0;
	ID = m = 0;
	fo (i, 1, n - 1)
	{
		cin >> u >> v;
		GG;
	}
	dfs (1, 0);
	fo (i, 1, n)
	{
		cin >> a[i];
		a[i] = id[a[i]], c[i] = a[i];
	}
	sort (c + 1, c + 1 + n);
	fo (i, 1, n) if (i == 1 || c[i - 1] < c[i]) c[++m] = c[i];
	for(int i=1;i<=n;i++){
		cout<<i<<' '<<c[i]<<'\n';
	}
	fo (i, 1, n) add (rt[i], rt[i - 1], find (a[i]), 0, m); // nxt[i], 2
	while (qq--)
	{
		cin >> l >> r >> x;
		ll L, R;
		L = id[x];
		R = id[x] + siz[x] - 1;
		if (QQ (l, r, R) - QQ (l, r, L - 1) )
		{
			YES;
		}
		else
		{
			NO;
		}
	}
	return;
}

int main()
{
	// CC();
	// Euler();
	ios::sync_with_stdio (0), cin.tie (0), cout.tie (0);
	cin >> T; while (T--)
	{
		CL();
		solve();
	}
	return 0;
}