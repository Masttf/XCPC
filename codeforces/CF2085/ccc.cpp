#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
    int x, y; 
    cin >> x >> y;
    if (x == y) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    while (true) {
        int mask = x & y;
        if (mask == 0) break;
        ans += mask;
        x += mask;
        y += mask;
        if (x == y) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}