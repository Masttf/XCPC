#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> P(N), A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }
    
    sieve(N);
    
    std::vector<int> f(N + 1, -1);
    
    std::vector<bool> vis(N);
    
    std::vector<int> ans(N);
    
    for (int i = 0; i < N; i++) {
        if (vis[i]) {
            continue;
        }
        std::vector<int> c;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            c.push_back(j);
            j = P[j];
        }
        const int L = c.size();
        
        std::vector<int> ps;
        int x = L;
        while (x > 1) {
            int p = minp[x];
            int v = 1;
            while (x % p == 0) {
                x /= p;
                v *= p;
                ps.push_back(v);
            }
        }
        
        int k = -1;
        for (int i = 0; i < L; i++) {
            bool ok = true;
            for (auto p : ps) {
                if (f[p] != -1 && i % p != f[p]) {
                    ok = false;
                }
            }
            if (ok && (k == -1 || A[c[i]] < A[c[k]])) {
                k = i;
            }
        }
        assert(k != -1);
        for (int i = 0; i < L; i++) {
            ans[c[i]] = A[c[(i + k) % L]];
        }
        for (auto p : ps) {
            f[p] = k % p;
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
    
    return 0;
}