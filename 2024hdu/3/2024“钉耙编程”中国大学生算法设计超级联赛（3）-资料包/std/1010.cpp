#include <bits/stdc++.h>
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

const int B = 400;
int near[50002];
int mndiv[50002];

void solve() {
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i <= N; i++) {
    near[i] = INF;
    mndiv[i] = INF;
  }

  vi ocr(N + 1, -1);
  vc<vi> q(Q * 2);
  auto upd = [&](int l, int r, int X) {
    for (l += Q, r += Q; l < r; l /= 2, r /= 2) {
      if (l & 1)
        q[l].pb(X), l++;
      if (r & 1)
        r--, q[r].pb(X);
    }
  };
  rep(Q) {
    int o, X;
    cin >> o >> X;
    if (o == 0) {
      assert(ocr[X] != -1);
      upd(ocr[X], i, X);
    }
    if (o == 0)
      ocr[X] = -1;
    else
      ocr[X] = i;
  }
  rep(N + 1) if (ocr[i] != -1) upd(ocr[i], Q, i);
  vi ANS(Q);

  vi s;
  int cur = INF;
  auto solve = [&](auto &solve, int p) {
    if (p >= Q * 2)
      return;
    vc<pii> which_near;
    vc<pii> which_div;
    int lst = cur;
    for (auto x : q[p]) {
      if (sz(s) < B) {
        for (auto y : s) {
          cmin(cur, x / y + x % y); // (x, ?)
          cmin(cur, y / x + y % x); // (?, x)
        }
      } else {
        if (near[x] < INF)
          cmin(cur, x);
        for (int r = 0; r < cur && r < x; r++) { // (x, ?)
          int z = x - r;
          cmin(cur, mndiv[z] + r);
        }
        for (int d = 0; d < cur && d * x <= N; d++) { // (?, x)
          int z = d * x;
          int y = near[z];
          if (y < z + d) {
            cmin(cur, d + y - z);
          }
        }
      }
      s.pb(x);
      for (int i = 0; i <= B && i < x; i++) {
        if (near[x - i] > x) {
          which_near.pb(x - i, near[x - i]);
          near[x - i] = x;
        }
      }
      for (int i = 1; i <= B && x * i <= N; i++) {
        if (mndiv[x * i] > i) {
          which_div.pb(x * i, mndiv[x * i]);
          mndiv[x * i] = i;
        }
      }
    }
    if (p >= Q) {
      ANS[p - Q] = cur;
    }
    solve(solve, p * 2);
    solve(solve, p * 2 + 1);
    int sz = sz(q[p]);
    while (sz--)
      s.pop_back();
    reverse(all(which_near));
    for (auto [x, y] : which_near) {
      near[x] = y;
    }
    reverse(all(which_div));
    for (auto [x, y] : which_div) {
      mndiv[x] = y;
    }
    cur = lst;
  };
  solve(solve, 1);
  rep(Q) {
    if (ANS[i] > N)
      ANS[i] = -1;
    cout << ANS[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--)  solve();
  return 0;
}
