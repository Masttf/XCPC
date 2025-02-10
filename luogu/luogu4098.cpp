
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

constexpr int N = 1e5 + 5, mod = 998244353;
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

int n, m;
int a[N];
int tr[N * 34][2], maxn;
int st[N][34], cnt, root[N], sum[N * 34], ans;
void update(int u, int v, int c){
    for(int i = 30; ~i; -- i){
        tr[v][0] = tr[u][0];
        tr[v][1] = tr[u][1];
        int now = (c >> i) & 1;
        tr[v][now] = ++ cnt;
        u = tr[u][now], v = tr[v][now];
        sum[v] = sum[u] + 1;
    }
}

int query(int y, int x, int z){
    int res = 0;
    for(int i = 30; ~i; -- i){
        int now = (z >> i) & 1;
        if(sum[tr[y][now ^ 1]] > sum[tr[x][now ^ 1]]){
            res += (1LL << i);
            x = tr[x][now ^ 1];
            y = tr[y][now ^ 1];
        }else {
            x = tr[x][now];
            y = tr[y][now];
        }
    }
    return res;
}

void Sakuya()
{
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        st[i][0] = a[i];
        maxn = max(maxn, a[i]);
    }
    root[0] = ++ cnt;
    update(0, root[0], 0);
    for(int i = 1; i <= n; ++ i){
        root[i] = ++ cnt;
        update(root[i - 1], root[i], a[i]);
    }

    for(int j = 1; j <= 20; ++ j){
        for(int i = 1; i + (1LL << j) - 1 <= n; ++ i){
            st[i][j] = max(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
        }
    }
 
    auto get = [&](int l, int r) -> int{
        int k = __lg(r - l + 1);
        return max(st[l][k], st[r - (1LL << k) + 1][k]);
    };

    for(int i = 1; i <= n; ++ i){
        int l, r;
        int l1 = -1, l2 = 1, r1 = -1, r2 = n;
        l = 1, r = i;
        while(l <= r){
            if(get(mid, i) > a[i]){
                l1 = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if(l1 != -1){
            l = 1, r = l1 - 1;
            while(l <= r){
                if(get(mid, l1 - 1) > a[i]){
                    l2 = mid;
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        
        l = i, r = n;
        while(l <= r){
            if(get(i, mid) > a[i]){
                r1 = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        if(r1 != -1){
             l = r1 + 1, r = n;
            while(l <= r){
                if(get(r1 + 1, mid) > a[i]){
                    r2 = mid;
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }
        }
       
        if(l1 == -1 && r1 == -1)continue;
        if(l1 != -1){
            l = l2;
            r = n;
            if(r1 != -1)r = r1 - 1;
            ans = max(ans, query(root[r], root[l - 1], a[i]));
        }
        if(r1 != -1){
            l = 1;
            r = r2;
            if(l1 != -1)l = l1 + 1;
            ans = max(ans, query(root[r], root[l - 1], a[i]));
        }
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