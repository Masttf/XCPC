#include<bits/stdc++.h>

#define int long long

using namespace std;

const int P = 1000000007;

int ksm(int x, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int x = n * n - n + 1;
    int y = n;
    
    cout << x % P * ksm(n, P - 2) % P << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);   
    
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
    
    return 0;
}