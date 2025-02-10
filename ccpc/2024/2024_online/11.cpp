#include <bits/stdc++.h>

#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;

#define dbg(x...)             \
    do {                      \
        cout << #x << " -> "; \
        err(x);               \
    } while (0)
void err() { cout << endl << endl; }
template <class T, class... Ts>
void err(T arg, Ts... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}



void solve() {
    int n, k;
    cin >> n >> k;
    if(lowbit(n) <= k){
        cout << "Alice" << '\n';
        return ;
    }
    
    cout << "Bob" << '\n';
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
};