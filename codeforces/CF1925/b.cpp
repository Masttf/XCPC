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
    int x, n; cin >> x >> n;
    int mx = x / n;
    int ans = 1;
    for(int i = 1; i * i <= x; i++){
    	if(x % i == 0){
    		if(i <= mx) ans = max(ans, i);
    		if(x / i <= mx){
    			ans = max(ans, x / i);
    		}
    	}
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