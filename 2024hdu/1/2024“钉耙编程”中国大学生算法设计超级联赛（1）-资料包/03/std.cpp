#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

using ull = unsigned long long;
const int N = 500005;
int n;
ll A[N];
int p[N], rk[N];
int rt[N], ls[N * 60], rs[N * 60], cnt;
int c[N * 60];
ull t[N * 60];
void pull(int p) {
  t[p] = t[ls[p]] + t[rs[p]];
  c[p] = c[ls[p]] + c[rs[p]];
}
void upd(int l, int r, int &p, int x, ull v) {
  if (!p)
    p = ++cnt;
  assert(cnt < 60 * N);
  if (l == r) {
    c[p] = 1;
    t[p] = v;
    return;
  }
  int m = (l + r) / 2;
  if (x <= m)
    upd(l, m, ls[p], x, v);
  else
    upd(m + 1, r, rs[p], x, v);
  pull(p);
}

ull cur = 0;
ull ANS[N];

int merge(int x, int y, ull prev1, ull prev2) {
  if (!x || !y) {
    // if(prev1&&t[y])debug(prev1, t[y]);
    // if(prev2&&t[x])debug(prev2, t[x]);
    cur += prev1 * t[y];
    cur += prev2 * t[x];
    return x + y;
  }
  assert(cnt < 60 * N);
  int z = ++cnt;
  ls[z] = merge(ls[x], ls[y], prev1, prev2);
  rs[z] = merge(rs[x], rs[y], prev1 + c[ls[x]], prev2 + c[ls[y]]);
  pull(z);
  return z;
}

ull SUM[N], SUM2[N];
vi g[N];
void dfs(int u, int p) {
  upd(0, N, rt[u], rk[u], A[u] * A[u]);
  SUM[u] = A[u];
  SUM2[u] = A[u] * A[u];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      SUM[u] += SUM[v];
      SUM2[u] += SUM2[v];
      ANS[u] += ANS[v];
      cur = 0;
      // debug("merge",u+1,v+1);
      rt[u] = merge(rt[u], rt[v], 0, 0);
      ANS[u] += cur;
      // debug(u+1, v+1, cur);
    }
  }
}

void solve() {
  cin >> n;
  rep(n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  rep(n) cin >> A[i];
  rep(n) p[i] = i;
  sort(p, p + n, [&](int i, int j) { return A[i] < A[j]; });
  rep(n) rk[p[i]] = i;
  // rep(n) cout << A[i] << " \n"[i + 1 == n];
  // rep(n) cout << rk[i] << " \n"[i + 1 == n];
  dfs(0, -1);
  rep(u, n) {
    ANS[u] *= 2;
    ANS[u] += SUM2[u];
    ANS[u] -= SUM[u] * SUM[u];
  }
  // rep(n) { cerr << ANS[i] << " \n"[i + 1 == n]; }
  ull res = 0;
  rep(n) res ^= ANS[i];
  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
