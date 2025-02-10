#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ULL;
using LL = long long;
 
constexpr int N = 100 + 5, mod = 998244353;
constexpr double eps = 1e-8;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
 
#define fi first
#define se second
#define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)
 
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
 
int ksm(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int a[N];
int cost[N];
int n, m1, m2;
int ans;
void dfs(int now, int last, int sum){
    if(now == n + 1){
        if(sum != 0)return;
        vector<int>dp(m1 + 1, 0);
        for(int i = 1; i <= n; ++ i){
            for(int j = m1; j >= cost[i]; -- j){
                dp[j] = max(dp[j - cost[i]] + a[i], dp[j]);
            }
        }
        int res = 0;
        for(int i = 0; i <= m1; ++ i)res = max(res, dp[i]);
        // cout << res << "\n";
        ans = min(res, ans);
        return;
    }
    if(last * (n - now + 1) > sum)return;
    for(int i = last; i <= sum; ++ i){
        cost[now] = i;
        dfs(now + 1, i, sum - i);
        cost[now] = 0;
    }
}
 
void Sakuya()
{
    cin >> n >> m1 >> m2;
    ans = 1e18;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    dfs(1, 0, m2);
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