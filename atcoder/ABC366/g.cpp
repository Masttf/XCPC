#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector<i64> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u] |= 1LL << v;
        adj[v] |= 1LL << u;
    }
    
    std::vector<i64> ans(N);
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         std::cerr << (adj[i] >> j & 1);
    //     }
    //     std::cerr << "\n";
    // }
    int r = 0;
    for (int j = 0; j < N; j++) {
        for (int i = r; i < N; i++) {
            if (adj[i] >> j & 1) {
                std::swap(adj[i], adj[r]);
            }
        }
        if (~adj[r] >> j & 1) {
            continue;
        }
        for (int i = 0; i < N; i++) {
            if (i == r) {
                continue;
            }
            if (adj[i] >> j & 1) {
                adj[i] ^= adj[r];
            }
        }
        r++;
    }
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         std::cerr << (adj[i] >> j & 1);
    //     }
    //     std::cerr << "\n";
    // }
    // std::cerr << "r : " << r << "\n";
    
    std::vector<int> a(r);
    for (int i = 0; i < r; i++) {
        a[i] = __builtin_ctzll(adj[i]);
    }
    for (int j = 0; j < N; j++) {
        i64 s = 0;
        s ^= 1LL << j;
        bool ok = true;
        for (int i = 0; i < r; i++) {
            if (a[i] == j) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        for (int i = 0; i < r; i++) {
            if (adj[i] >> j & 1) {
                s ^= 1LL << a[i];
            }
        }
        for (int i = 0; i < N; i++) {
            if (s >> i & 1) {
                ans[i] |= 1LL << j;
            }
        }
    }
    if (std::find(ans.begin(), ans.end(), 0LL) != ans.end()) {
        std::cout << "No\n";
        return 0;
    }
    std::cout << "Yes\n";
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
    
    return 0;
}