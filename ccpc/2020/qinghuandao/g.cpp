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
    int n, k; cin >> n >> k;
    if(k == 1 || k >= 32){
    	cout << n << '\n';
    	return ;
    }
    int ans = 0;
    int l = 1;
    for(int i = 1; i <= n && l <= n; i++){
    	int r = 1;
    	for(int j = 1; j <= k; j++){
    		r = r * (i + 1);
    		if(r > n)break;
    	}
    	r--;
    	r = min(r, n);
    	int tot  = r / i - (l - 1) / i;
    	ans += tot;
    	l = r + 1;
    }
    cout << ans << '\n';
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