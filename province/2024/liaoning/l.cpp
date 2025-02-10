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
    int k; cin >> k;
    int l = 2024, r = 2e18;
    auto get = [&](int year) -> int{
    	int res = 0;
    	res += year;
    	int p = 1;
    	for(int i = 0; ; i++, p *= 100){
    		if(p > year)break;
    		res -= year / (p * 4) - year / (p * 100);
    	}
    	// res -= year / 4 - year / 100;

    	return res;
    };
    int ans = -1;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(get(mid) - get(2024) >= k){
    		ans = mid;
    		r = mid - 1;
    	}else l = mid + 1;
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