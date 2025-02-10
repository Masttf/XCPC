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
    int n, m, k; cin >> n >> m >> k;
    vector<array<int ,3>> a(m + 1);
    for(int i = 1; i <= m; i++){
    	int t, x, y; cin >> t >> x >> y;
    	a[i] = {-t, x, y};
    }
    sort(a.begin() + 1, a.end());
    int ok = 1;
    for(int i = 1; i <= m; i++){
    	if(a[i][1] != a[1][1])ok = 0;
    }
    if(ok){
    	cout << -1 << '\n';
    	return ;
    }
    vector<int>cnt(n + 1);
    auto check = [&](int lim) -> bool{
    	cnt.assign(n + 1, 0);
    	int res = lim;//现在的右边界
    	for(int i = 1; i <= m; i++){
    		auto [t, x, y] = a[i];
    		t = -t;
    		int need = lim - t + 2 - (y + k - 1) / k;
    		if(need > cnt[x]){
    			need -= cnt[x];
    			res -= need;
    			if(res + 1 < t)return false;
    			cnt[x] += need;
    		}
    	}
    	return true;
    };
    int ans = -1;
    int l = 0, r = 3e18;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}else r = mid - 1;
    }
    cout << ans << '\n';
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