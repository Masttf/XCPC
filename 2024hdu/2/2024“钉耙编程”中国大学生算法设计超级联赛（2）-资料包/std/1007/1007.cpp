#include <bits/stdc++.h>

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

const int N = 50000 + 5 , D = 100 + 5;

u64 h[N] , hs[D][N];

int fa[D][N] , sz[D][N];
vector<int> son[D][N];

int get(int d , int x) {
  while (fa[d][x] != x) {
    x = fa[d][x] = fa[d][fa[d][x]];
  }
  return x;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int T;
  cin >> T;

  std::random_device rd;
  std::mt19937_64 gen(rd());

  while (T--) {
    int n , m , d , k;
    cin >> n >> m >> d >> k;

    for (int i = 1 ; i <= n ; i++) {
      fa[0][i] = i , sz[0][i] = 1 , son[0][i].push_back(i);
    }

    i64 ans = 0;
    for (int i = 1 ; i <= m ; i++) {
      int u , v;
      cin >> u >> v;
      int fu = get(0 , u);
      int fv = get(0 , v);
      if (fu == fv) continue;
      if (sz[0][fu] < sz[0][fv]) {
        swap(fu , fv) , swap(u , v);
      }
      ans += 1ll * sz[0][fu] * sz[0][fv];
      sz[0][fu] += sz[0][fv];
      fa[0][fv] = fu;
      for (auto x : son[0][fv]) {
        son[0][fu].push_back(x);
      }
      son[0][fv].clear();
      son[0][fv].shrink_to_fit();
    }
    for (int i = 1 ; i <= d + 1 ; i++) {
      for (int j = 1 ; j <= n ; j++) {
        hs[i][j] = gen();
      }
    }
    for (int i = 1 ; i <= d + 1 ; i++) {
      for (int j = 1 ; j <= n ; j++) {
        int p = get(0 , j);
        fa[i][j] = p , sz[i][j] = sz[0][p];
        h[j] += hs[i][p];
        if (j == p) {
          son[i][j] = son[0][j];
        }
      }
    }

    unordered_map<u64 , int> h_map;
    for (int i = 1 ; i <= n ; i++) {
      h_map[h[i]]++;
    }
    // cout << "ans:" << ans << endl;
    while (k--) {
      int u , v , w;
      cin >> u >> v >> w;
      int fu = get(w, u);
      int fv = get(w, v);
      if (fu == fv) {
        cout << ans << '\n';
        continue;
      }
      if (sz[w][fu] < sz[w][fv]) {
        swap(fu, fv), swap(u, v);
      }

      unordered_map<u64 , int> n_map;
      for (auto x : son[w][fv]) {
        h_map[h[x]]--;
        if (h_map[h[x]] == 0) {
          h_map.erase(h[x]);
        } else {
          ans -= h_map[h[x]];
        }
        h[x] += hs[w][fu] - hs[w][fv];
        n_map[h[x]]++;
        son[w][fu].push_back(x);
      }
      sz[w][fu] += sz[w][fv];
      fa[w][fv] = fu;

      son[w][fv].clear();
      son[w][fv].shrink_to_fit();
      for (auto [x, y] : n_map) {
        // cout << x << ' ' << y << ' ' << h_map[x] << endl;
        if (h_map.find(x) != h_map.end()) ans += 1ll * h_map[x] * y; 
        ans += 1ll * y * (y - 1) / 2;
      }
      for (auto [x , y] : n_map) {
        h_map[x] += y;
      }
      // for (int i = 1 ; i <= n ; i++) {
      //   cout << h[i] << ' ';
      // }
      // cout << '\n';
      cout << ans << '\n';
    }
    for (int i = 0 ; i <= d + 1 ; i++) {
      for (int j = 0 ; j <= n ; j++) {
        hs[i][j] = 0;
        fa[i][j] = sz[i][j] = 0;
        hs[i][j] = 0;
        son[i][j].clear();
        son[i][j].shrink_to_fit();
      }
    }
    for (int i = 0 ; i <= n ; i++) {
      h[i] = 0;
    }
    // std::cerr << h[383] << ' ' << h[113] << std::endl;
  }
  return 0;
}
/*
1
3 1 3 8
1 2
1 3 1
1 3 2
1 3 3
2 3 1
2 3 2
2 3 3
1 3 4
2 3 4
*/