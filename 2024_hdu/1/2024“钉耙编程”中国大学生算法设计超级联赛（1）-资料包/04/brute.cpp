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


#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;

const int B = 300;
void solve() {
  int n, m;
  cin >> n >> m;
  int cnt = (n - 1) / B + 1;
  vi L(cnt), R(cnt);
  rep(cnt) {
    L[i] = i * B;
    R[i] = (i + 1) * B;
  }
  R.back() = n;
  vc<vc<array<int, 2>>> full(cnt);
  vc<vc<array<int, 2>>> part(n);
  rep(m) {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    --a, --b, --l, --r;
    int tl = l / B;
    int tr = r / B;
    if (tl == tr) {
      rep(j, l, r + 1) part[j].pb(array<int, 2>{a, b});
    } else {
      rep(j, l, R[tl]) part[j].pb(array<int, 2>{a, b});
      rep(j, tl + 1, tr) full[j].pb(array<int, 2>{a, b});
      rep(j, L[tr], r + 1) part[j].pb(array<int, 2>{a, b});
    }
  }
  vl can(n), ans(n);
  vc<vi> e(n);
  vi vis(n), leader(n);
  auto calc = [&]() {
    rep(n) {
      int parent = leader[i];
      ans[i] += can[parent];
    }
  };
  dsu f;
  auto rebuild = [&](int id) {
    f = dsu(n);
    rep(n) {
      can[i] = 0;
    } 
    for (const auto &[a, b] : full[id]) {
      f.merge(a, b);
    }
    rep(n) {
      leader[i] = f.leader(i);
    }
  };
  rep(t, cnt) {
    rebuild(t);
    int S = leader[0];
    rep(i, L[t], R[t]) {
      for (auto &[a, b] : part[i]) {
        a = leader[a];
        b = leader[b];
        if (a != b) {
          e[a].pb(b);
          e[b].pb(a);
        }
      }
      vi q{S};
      rep(j, sz(q)) {
        int a = q[j];
        if (vis[a]) {
          continue;
        }
        vis[a] = 1;
        can[a] += i + 1;
        for (auto b : e[a]) {
          if (!vis[b]) {
            q.pb(b);
          }
        }
      }
      for (auto &[a, b] : part[i]) {
        e[a].clear();
        e[b].clear();
      }
      for (auto a : q) {
        vis[a] = 0;
      }
    }
    calc();
  }
  // rep(n) cout << ans[i] << " \n"[i + 1 == n];
  unsigned long long res = 0;
  rep(n) res ^= ans[i];
  cout << res << "\n";
  debug(clock());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
