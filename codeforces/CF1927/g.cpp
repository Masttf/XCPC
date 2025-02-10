#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = std::max(pre[i], std::min(n, i + a[i]));
    }
    
    std::vector<int> dp(n + 1, n);
    for (int i = 0, x = 0; ; i = pre[i + 1], x++) {
        dp[i] = x;
        if (i == n) {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - a[j] + 1 <= i) {
                int cur = j + 1;
                int mx = 0;
                for (int k = i; k < j; k++) {
                    mx = std::max(mx, std::min(n, k + a[k]));
                }
                for (int k = j + 1, x = dp[i] + 1; ; k = mx, x++) {
                    while (cur <= k && cur < n) {
                        mx = std::max(mx, std::min(n, cur + a[cur]));
                        cur++;
                    }
                    dp[k] = std::min(dp[k], x);
                    if (mx <= k) {
                        break;
                    }
                }
            }
        }
    }
    
    std::cout << dp[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}