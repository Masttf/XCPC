#include <bits/stdc++.h>
using namespace std;
const int N = 156;

namespace AC {
const int SZ = N * 80;
int tot, tr[SZ][26];
int fail[SZ], idx[SZ], val[SZ];
int cnt[N];  // 记录第 i 个字符串的出现次数

void init() {
  memset(fail, 0, sizeof(fail));
  memset(tr, 0, sizeof(tr));
  memset(val, 0, sizeof(val));
  memset(cnt, 0, sizeof(cnt));
  memset(idx, 0, sizeof(idx));
  tot = 0;
}

void insert(string s, int id) {  // id 表示原始字符串的编号
  int u = 0;
  for (int i = 0; i< s.size(); i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];  // 转移
  }
  idx[u] = id;  // 以 u 为结尾的字符串编号为 idx[u]
}

queue<int> q;

void build() {
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] =
            tr[fail[u]][i];  // fail数组：同一字符可以匹配的其他位置
        q.push(tr[u][i]);
      } else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}

int query(string t) {  // 返回最大的出现次数
  int u = 0, res = 0;
  for (int i = 0; i<t.size(); i++) {
    u = tr[u][t[i] - 'a'];
    for (int j = u; j; j = fail[j]) val[j]++;
  }
  for (int i = 0; i <= tot; i++)
    if (idx[i]) res = max(res, val[i]), cnt[idx[i]] = val[i];
  return res;
}
}  // namespace AC

int n;
string a[N];
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  while (cin >> n) {
    AC::init();  // 数组清零
    for (int i = 1; i <= n; i++){
      cin >> a[i];
      AC::insert(a[i], i);  // 需要记录该字符串的序号
    }
    AC::build();
    string t;cin >> t;
    int x = AC::query(t);
    cout << x<< '\n';
    for (int i = 1; i <= n; i++)
      if (AC::cnt[i] == x) cout <<a[i] <<'\n';
  }
  return 0;
}