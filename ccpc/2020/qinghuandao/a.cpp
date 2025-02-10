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
    int a, b; cin >> a >> b;
    if(a < 2){
    	cout << "0/1\n";
    	return ;
    }
    int tot = (a + b);
    int res = tot * (tot - 1) / 2;
    int ans = a * (a - 1) / 2;
    int d = __gcd(res, ans);
    ans /= d;
    res /= d;
    cout << ans << '/' << res << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}