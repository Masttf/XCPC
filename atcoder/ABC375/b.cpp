#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    double ans = 0;
    int n; cin >> n;
    int x1 = 0, y1 = 0;
    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	ans += sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    	x1 = x;
    	y1 = y;
    }
    ans += sqrt(x1 * x1 + y1 * y1);
    cout << fixed << setprecision(10) << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}