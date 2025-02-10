#include <bits/stdc++.h>
using namespace std;

inline void work() {
    int n, L, D; cin >> n >> L >> D;
    int cnt = 0, mn = 1e9, mx = 0, a1;
    cin >> a1;
    for (int i = 2; i <= n; ++i) {
        int a; cin >> a;
        if (a < L) ++cnt;
        if (a < mn) mn = a;
        if (a > mx) mx = a;
    }
    if (a1 >= L) {
        if (cnt < 3) {puts("No"); return;}
        if (a1 - mn <= D) {puts("No"); return;}
        puts("Yes"); return;
    } else {
        if (mx - mn <= D) {puts("No"); return;}
        if (cnt < 2) {puts("No"); return;}
        puts("Yes"); return;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) work();
    return 0;
}
