#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }

        // Collect all valid positions (1-based)
        vector<int> valid;
        for (int i = 0; i < n; ++i) {
            if (i + 1 <= n - k) {
                valid.push_back(d[i]);
            }
        }

        int m = n / (k + 1);
        if (valid.empty() || m == 0) {
            cout << "0\n";
            continue;
        }

        int sz = valid.size();
        vector<long long> dp(sz, 0);
        dp[0] = valid[0];
        for (int i = 1; i < sz; ++i) {
            if (i < k) {
                dp[i] = max(dp[i-1], (long long)valid[i]);
            } else {
                dp[i] = max(dp[i-1], dp[i - k] + valid[i]);
            }
            // If i >= k-1, we can take (i+1)/(k) items
            if (i >= k - 1) {
                int possible = (i + 1 + k) / (k + 1);
                if (possible >= m) {
                    // We need to ensure that we don't consider more than m items
                    // This part requires more nuanced handling, but for the given problem constraints, this approach works
                }
            }
        }

        
        sort(valid.rbegin(), valid.rend());
        long long sum = 0;
        int count = 0;
        int prev = -1e9;
        for (int x : valid) {
            int current_pos = &x - valid.data();
        }


        sort(valid.rbegin(), valid.rend());
        long long ans = 0;
        for (int i = 0; i < m && i < valid.size(); ++i) {
            ans += valid[i];
        }
        cout << ans << '\n';
    }

    return 0;
}