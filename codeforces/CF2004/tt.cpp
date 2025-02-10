
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 5e5 + 5, mod = 998244353;
constexpr double eps = 1e-8;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int ksm(int a, int b){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
int n, m, ans;
int a[N], b[N], bn, k;

struct Node{
    int tag, minn, cnt;
};

void Sakuya()
{
    cin >> n;
    k = 3;
    ans = 0;
    for(int i = 1; i <= n; ++ i)cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    bn = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; ++ i){
        a[i] = lower_bound(b + 1, b + 1 + bn, a[i]) - b;
    }
    // for(int i = 1; i <= n; ++ i){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";

    vector<vector<int>>pos(n + 1);
    for(int i = 1; i <= n; ++ i){
        pos[a[i]].emplace_back(i);
    }

    vector c(n + 2, vector<tuple<int, int, int>>());
    for(int i = 1; i <= n; ++ i){
        int siz = pos[i].size();
        for(int j = 0; j < siz; ++ j){
            int nxt = n + 1;
            // int pre = 0;
            int now = pos[i][j];
            if(j != siz - 1)nxt = pos[i][j + 1];
            // if(j != 0)pre = pos[i][j - 1];
            if(now != n){
                c[now].emplace_back(now + 1, n, 1); //左边界不能大于右边界
                c[now + 1].emplace_back(now + 1, n, -1); //撤销
            }
            // c[now - 1].emplace_back(0, now - 1, -1);
            if(j >= k){
                //dbg(i, pos[i][j - k], now);
                c[now].emplace_back(1, pos[i][j - k], 1); //k+1个数字的位置-n的位置区间不合法
                c[nxt].emplace_back(1, pos[i][j - k], -1); //撤销
                // c[pre].emplace_back(pos[i][j + k], n, -1);
            }
            int l = 1;

            if(j + 1 >= k){
                l = pos[i][j - k + 1] + 1;
            }
            c[now].emplace_back(l, now, 1);
            c[nxt].emplace_back(l, now, -1);
            // int r = n + 1;
            // if(j + k - 1 <= siz - 1){
            //     r = pos[i][j + k - 1] - 1;
            // }
            // if(now <= r)c[now].emplace_back(now, r, 1); //1个数字的位置到k个数字的位置-1的区间不合法
            // if(now <= r)c[nxt].emplace_back(now, r, -1); //撤销
            // if(now <= r)c[pre].emplace_back(now, r, -1);
        }
    }

    vector<Node>tr(n * 4);
    auto pushdown = [&](int u) -> void{
        if(tr[u].tag){
            tr[u << 1].tag += tr[u].tag;
            tr[u << 1 | 1].tag += tr[u].tag;
            tr[u << 1].minn += tr[u].tag;
            tr[u << 1 | 1].minn += tr[u].tag;
            tr[u].tag = 0;
        }
        return;
    };

    auto pushup = [&](Node x, Node y) -> Node{
        Node res = {0, 0, 0};
        res.minn = min(x.minn, y.minn);
        if(x.minn == res.minn)res.cnt += x.cnt;
        if(y.minn == res.minn)res.cnt += y.cnt;
        return res;
    };

    auto build = [&](auto self, int u, int l, int r) -> void{
        if(l == r){
            tr[u].minn = 0;
            tr[u].cnt = 1;
            return;
        }
        self(self, u << 1, l, mid);
        self(self, u << 1 | 1, mid + 1, r);
        tr[u] = pushup(tr[u << 1], tr[u << 1 | 1]);
    };

    auto update = [&](auto self, int u, int l, int r, int x, int y, int val) -> void{
        if(x <= l && y >= r){
            tr[u].tag += val;
            tr[u].minn += val;
            return;
        }
        pushdown(u);
        if(x <= mid)self(self, u << 1, l, mid, x, y, val);
        if(y > mid)self(self, u << 1 | 1, mid + 1, r, x, y, val);
        tr[u] = pushup(tr[u << 1], tr[u << 1 | 1]);
    };

    build(build, 1, 1, n);
    for(int i = 1; i <= n; ++ i){
        for(auto [l, r, val] : c[i]){
            update(update, 1, 1, n, l, r, val);
        }
        if(tr[1].minn == 0)ans += tr[1].cnt;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();

}
