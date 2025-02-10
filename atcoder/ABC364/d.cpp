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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= q; i++){
    	int x, k; cin >> x >> k;
    	auto check = [&](int d) -> bool{
    		int l = x - d, r = x + d;
    		int len = upper_bound(a.begin() + 1, a.end(), r) - lower_bound(a.begin() + 1, a.end(), l);
    		return len >= k;
    	};
    	int l = 0, r = max(abs(x - a[1]), abs(a[n] - x));
    	int ans = -1;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(check(mid)){
    			ans = mid;
    			r = mid - 1;
    		}else l = mid + 1;
    	}
    	cout << ans << '\n';
    }
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