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
const int base = 131;
ull pw[1048576];

void solve() {
  string A, B;
  cin >> A >> B;
  int N = sz(A);
  A = A + A;
  vc<ull> P(N * 2 + 1);
  rep(i, N + N) P[i + 1] = P[i] * base + A[i];
  auto rangeP = [&](int l, int r) { return P[r] - P[l] * pw[r - l]; };

  map<ull, int> mp;
  rep(i, N) mp[rangeP(i, i + N)] = 1;
  int M = sz(B);
  vc<ull> Q(M + 1);
  rep(i, M) Q[i + 1] = Q[i] * base + B[i];

  auto rangeQ = [&](int l, int r) { return Q[r] - Q[l] * pw[r - l]; };

  int ANS = 0;
  rep(i, M) if (i + N <= M) ANS += mp[rangeQ(i, i+N)];

  cout << ANS << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  pw[0] = 1;
  rep(i, 1, 1048576) pw[i] = pw[i - 1] * base;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}