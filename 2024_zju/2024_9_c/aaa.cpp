
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> ans(n + 1);

    auto check = [&](int mid)->bool {
        if(std::abs(a[1] - a.front()) > mid) return false;
        std::vector<std::pair<int, int>> v(n + 1);
        v[1] = {a.front() - mid, a.front() + mid};
        for(int i = 2; i < n; ++i) {
            bool l = a[i - 1] - mid <= a[i] and a[i] <= a[i - 1] + mid, r = v[i - 1].first <= a[i] and a[i] <= v[i - 1].second;
            if(l and r) {
                v[i] = {std::min(v[i - 1].first, a[i - 1] - mid), std::max(v[i - 1].second, a[i - 1] + mid)};
            } else if(l) {
                v[i] = v[i - 1];
            } else if(r) {
                v[i] = {a[i - 1] - mid, a[i - 1] + mid};
            } else return false;
        }
        int node = 0;
        for(int i = n - 1; i >= 2; --i) {
            if(!node) {
                if(a[i - 1] - mid <= a[i] and a[i] <= a[i - 1] + mid) ans[i] = 0;
                else ans[i] = 1, node = i;
            } else {
                if((a[i - 1] - mid <= a[i] and a[i] <= a[i - 1] + mid) and (v[i - 1].first <= a[node] and a[node] <= v[i - 1].second)) ans[i] = 0;
                else ans[i] = 1, node = i;
            }

        }
        return true;
    };


    int l = 0, r = 1e9, Ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, Ans = mid;
        else l = mid + 1 ;
    }

    std::cout << Ans << '\n';
    for(int i = 2; i < n; ++i) {
        ans[i] ^= ans[i - 1];
    }
    // for(int i = 1; i <= n; ++i) std::cout << ans[i];
    for(int i = 1; i < n; ++i) 
        std::cout << "LR"[ans[i]];
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
