//Mercy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e4 + 7, K = 1e2 + 7, INF = 0x3f3f3f3f;
int n, k, dp[N];

struct Day {
    int t, f;

    bool operator<(const Day &tmp) const {
        return t < tmp.t;
    }
} d[N];

struct Pass {
    int p, d, c;
} p[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].t >> d[i].f;
        d[i].t++;
    }
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= k; i++) cin >> p[i].p >> p[i].d >> p[i].c;
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + d[i + 1].f);
        for (int j = 1; j <= k; j++) {
            int to = i + p[j].d;
            int l = i + 1, r = n, res = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (d[mid].t <= d[i + 1].t + p[j].p - 1) {
                    res = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            to = min(to, res);
            dp[to] = min(dp[to], dp[i] + p[j].c);
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
    return 0;
}