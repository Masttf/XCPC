#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int W = 1000;
mt19937_64 rng(time(0));

void solve() {
  int n, w;
  cin >> n >> w;
  assert(1 <= n && n <= 1000);
  vector<array<int, 5>> A(n);
  for (auto &a : A) {
    a[0] = 0;
    for (int i = 1; i <= 4; i++) {
      cin >> a[i];
    }
  }
  shuffle(A.begin(), A.end(), rng);
  vector<vector<long long>> dp(2, vector<long long>(w + 1, INF));
  vector<vector<int>> vis(2, vector<int>(w + 1, -1));
  int p = 1, q = 0;
  dp[q][0] = 0, vis[q][0] = 0;
  for (int i = 0; i < n; i++, p ^= 1, q ^= 1) {
    auto a = A[i];
    long long L = 1ll * w * (i + 1) / n - W;
    long long R = 1ll * w * (i + 1) / n + W;
    L = max(L, 0LL);
    R = min(R, (long long)w);
    for (int j = L; j <= R; j++) {
      if (vis[q][j] == i) {
        for (int k = 0; k <= 4; k++) {
          if (j + k <= w && dp[p][j + k] >= dp[q][j] + a[k]) {
            dp[p][j + k] = dp[q][j] + a[k];
            vis[p][j + k] = i + 1;
          }
        }
      }
    }
  }
  cout << dp[q][w] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;

  while (T--) {
    solve();
  }

  return 0;
}
