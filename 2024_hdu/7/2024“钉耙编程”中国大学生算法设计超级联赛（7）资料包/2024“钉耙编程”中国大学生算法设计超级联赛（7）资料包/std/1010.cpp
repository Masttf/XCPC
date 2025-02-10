#include <bits/stdc++.h>
#define int long long
 
void solve() {
    int n, x, k; std::cin >> n >> x >> k;
    std::vector<int> a(n+1);
    for(int i=1; i<=n; i++) std::cin >> a[i];
    int ans = 0;
    std::priority_queue<int> q;
    for(int i=1; i<=n; i++) {
        x -= a[i];
        q.push(a[i]);
        if(k && x <= 0) {
            x += q.top();
            q.pop();
            k--;
        }
        if(x <= 0) break;
        else ans = i;
    }
    std::cout << ans << "\n";
}
 
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    int _; std::cin >> _;
    while(_--) solve();
    return 0;
}
