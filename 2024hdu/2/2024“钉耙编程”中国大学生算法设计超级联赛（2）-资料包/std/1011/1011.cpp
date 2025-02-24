#include <bits/stdc++.h>

using namespace std;

const int N = 500000 + 5, SIGMA = 26;

const int MOD1 = 1e9 + 7, MOD2 = 998244353;
const int W1 = 37, W2 = 233;

int p1[N], p2[N];
int h1[N], h2[N];

int n, cnt = 0;
int son[N][SIGMA], fail[N], ep[N] , sum[N];
vector<int> G[N];

int insert(const string &s) {
  int u = 0;
  for (int i = 0; i < s.size(); i++) {
    int d = s[i] - 'a';
    if (!son[u][d]) son[u][d] = ++cnt;
    u = son[u][d];
  }
  return u;
}

void build() {
  queue<int> Q;
  for (int i = 0 ; i < SIGMA ; i++) {
    if (son[0][i]) Q.push(son[0][i]);
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = 0; i < SIGMA; i++) {
      if (son[u][i]) {
        fail[son[u][i]] = son[fail[u]][i];
        Q.push(son[u][i]);
      } else {
        son[u][i] = son[fail[u]][i];
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    G[fail[i]].push_back(i);
  }
}

void dfs(int u) {
  for (int v : G[u]) {
    dfs(v);
    sum[u] += sum[v];
  }
}

int get1(int l, int r) {
  return (1ll * h1[r] - 1ll * h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
}
int get2(int l, int r) {
  return (1ll * h2[r] - 1ll * h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
}
pair<int, int> get(int l, int r) { return make_pair(get1(l, r), get2(l, r)); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  p1[0] = p2[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    p1[i] = 1ll * p1[i - 1] * W1 % MOD1;
    p2[i] = 1ll * p2[i - 1] * W2 % MOD2;
  }

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    string A, C;
    vector<string> B(n), B1(n);
    cin >> A >> C;

    int r1 = 0, r2 = 0;
    for (int i = 0; i < C.size(); i++) {
      r1 = (1ll * r1 * W1 % MOD1 + C[i] - 'a' + 1) % MOD1;
      r2 = (1ll * r2 * W2 % MOD2 + C[i] - 'a' + 1) % MOD2;
    }
    auto r = make_pair(r1, r2);

    for (int i = 0; i < n; i++) {
      // std::cerr << cnt << std::endl;
      cin >> B[i] >> B1[i];
      h1[0] = h2[0] = 0;
      for (int j = 1; j <= B1[i].size(); j++) {
        h1[j] = (1ll * h1[j - 1] * W1 % MOD1 + B1[i][j - 1] - 'a' + 1) % MOD1;
        h2[j] = (1ll * h2[j - 1] * W2 % MOD2 + B1[i][j - 1] - 'a' + 1) % MOD2;
      }
      bool flag = false;
      for (int j = 1; j + C.size() - 1 <= B1[i].size(); j++) {
        if (get(j, j + C.size() - 1) == r) {
          flag = true;
          break;
        }
      }
      // if (flag) cerr << i + 1 << ":" << flag << endl;
      if (flag) {
        ep[i] = insert(B[i]);
      }
    }
    build();

    int u = 0;
    for (int i = 0; i < A.size() ; i++) {
      int d = A[i] - 'a';
      u = son[u][d];
      sum[u]++;
    }

    dfs(0);

    vector<int> ans;
    for (int i = 0 ; i < n ; i++) {
      if (ep[i] && sum[ep[i]] > 0) {
        ans.push_back(i);
      }
    }
    for (int i = 0 ; i < ans.size() ; i++) {
      cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
    }
    if (ans.empty()) {
      cout << '\n';
    }

    for (int i = 0 ; i < n ; i++) {
      ep[i] = 0;
    }
    for (int i = 0; i <= cnt; i++) {
      memset(son[i], 0, sizeof(son[i]));
      fail[i] = sum[i] = 0;

      G[i].clear();
      G[i].shrink_to_fit();
    }
    cnt = 0;
  }
  return 0;
}
/*
2
5
abcde a
a a
b a
c b
d a
e c
5
aaabbbccc xyz
ab xxxyzzzzyy
bccc aaaaxyza
abbbb xxxxyyz
aaaabbbcccc x
a xyzzzzzzzzz
*/