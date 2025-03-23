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
        vector<long long> d(n);
        for (auto &x : d) cin >> x;
        sort(d.rbegin(), d.rend());
        int m = n / (k + 1);
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            ans += d[i];
        }
        cout << ans << '\n';
    }

    return 0;
}