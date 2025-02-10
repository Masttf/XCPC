#include <bits/stdc++.h>

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(auto &i:a) std::cin >> i;

    int ans = 0;
    for(int i = n - 2; i >= 0; --i) {
        if(a[i] > a[i + 1]) {
            int k = (a[i] + a[i + 1] - 1) / a[i + 1];
            if(a[i] % a[i + 1] == 0) a[i] = a[i + 1];
            else a[i] /= k;
            ans += k - 1;
        }
    }
    std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}