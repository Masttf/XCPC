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

struct rolling_dsu {
  vi p, sz, st;
  vl tag;
  rolling_dsu(int n) {
    p.resize(n);
    iota(all(p), 0);
    sz.resize(n, 1);
    tag.resize(n, 0);
  }

  int root(int x) {
    if (x == p[x]) {
      return x;
    } else {
      return root(p[x]);
    }
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    tag[y] -= tag[x];
    p[y] = x;
    sz[x] += sz[y];
    st.pb(y);
  }

  int size() { return st.size(); }

  void roll_back(int last_size) {
    while ((int)st.size() != last_size) {
      int y = st.back();
      int x = p[y];
      sz[x] -= sz[y];
      tag[y] += tag[x];
      p[y] = y;
      st.pop_back();
    }
  }

  void push_tag(int x, int y) { tag[x] += y; }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vc<vc<pii>> t(n * 2);
  auto update = [&](int a, int b, int l, int r) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        t[l++].pb(a, b);
      }
      if (r & 1) {
        t[--r].pb(a, b);
      }
    }
  };

  rep(m) {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    --a, --b, --l;
    update(a, b, l, r);
  }

  rolling_dsu f(n);
  auto solve = [&](auto &solve, int p) -> void {
    if (p >= n * 2)
      return;
    int las = f.size();
    // debug(las);
    for (auto [a, b] : t[p]) {
      f.unite(a, b);
    }
    if (n <= p && p < n * 2) {
      // debug(f.root(0));
      f.push_tag(f.root(0), p - n + 1);
    }
    solve(solve, p * 2);
    solve(solve, p * 2 + 1);
    f.roll_back(las);
  };
  solve(solve, 1);

  assert(f.size() == 0);
  vl ANS = f.tag;
  // rep(n) { cout << ANS[i] << " \n"[i + 1 == n]; }
  unsigned long long res = 0;
  rep(n) res ^= ANS[i];
  debug(ANS);
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