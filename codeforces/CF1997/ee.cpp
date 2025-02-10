//
/*
By:Luckyblock
*/
#include <bits/stdc++.h>
#define LL long long
const int kN = 3e5 + 10;
//=============================================================
int n, q, a[kN];
std::vector<int> val[kN], f[kN];
//=============================================================
namespace bit {
  #define lowbit(x) ((x)&(-x))
  const int kNode = kN;
  int lim, t[kNode];
  void init(int lim_) {
    lim = lim_;
  } 
  void insert(int p_, int val_) {
    for (int i = p_; i <= lim; i += lowbit(i)) {
      t[i] += val_;
    }
  }
  int sum(int p_) {
    int ret = 0;
    for (int i = p_; i; i -= lowbit(i)) ret += t[i];
    return ret;
  }
  int query(int l_, int r_) {
    if (l_ > r_) return 0;
    return sum(r_) - sum(l_ - 1);
  }
}
void init() {
  bit::init(n);
  for (int i = 1; i <= n; ++ i) {
    val[a[i]].push_back(i);
    bit::insert(i, 1);
    f[i].push_back(0), f[i].push_back(1);
  }
 
  for (int round = 1; round <= n; ++ round) {
    for (int k = 1; round * k < n && ((int) f[k].size() > round); ++ k) {
      int p = f[k][round], next = n + 1;
      if (p == n + 1) continue;
      for (int l = p + k, r = n; l <= r; ) {
        int mid = (l + r) >> 1;
        if (bit::query(p, mid - 1) >= k) {
          next = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      f[k].push_back(next);
    }
    for (auto p: val[round]) bit::insert(p, -1);
  }
 
  for (int k = 1; k <= n; ++ k) f[k].push_back(n + 1);
}
//=============================================================
int main() {
  //freopen("1.txt", "r", stdin);
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> q;
  for (int i = 1; i <= n; ++ i) std::cin >> a[i];
  init();
 
  while (q --) {
    int i, x; std::cin >> i >> x;
    int p = std::upper_bound(f[x].begin(), f[x].end(), i) - f[x].begin() - 1;
    std::cout << (p > a[i] ? "NO" : "YES") << "\n";
  }
  return 0;
}