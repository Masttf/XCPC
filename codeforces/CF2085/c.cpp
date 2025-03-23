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
    int x, y;cin >> x >> y;
    if (x == y) {
        cout << -1 << '\n';
        return ;
    }
    auto get = [&](int val, int bit) -> int{
    	return (val >> bit) & 1;
    };
    int ans = 0;
    for (int i = 0;i <= 40;i++) {
        if (get(x, i) && get(y, i)) {
            ans += (1ll << i);
            x += (1ll << i);
            y += (1ll << i);
        }
    }
    if ((x >> 41) & 1 && (y >> 41) & 1) {
        int suma = 0,sumb = 0;
        for (int i = 0;i <= 39;i++) {
        	for(int k = 0; k <= 60; k++){
		    	get(x, k);
		    	get(y, k);
		    }
            if (get(x, i)) suma += (1ll << i);
            if (get(y, i)) sumb += (1ll << i);
        }
        cout << ans - max({0ll, suma, sumb}) << '\n';
        return ;
    }
    for(int i = 0; i <= 60; i++){
    	get(x, i);
    	get(y, i);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}