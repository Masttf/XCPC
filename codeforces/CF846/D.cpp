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
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<array<int, 3>>a(q + 1);
    for(int i = 1; i <= q; i++){
    	cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector v(n + 1, vector<int>(m + 1));
    vector pre(n + 1, vector<int>(m + 1));
    auto get = [&](int x, int y) -> int{
    	return pre[x + k - 1][y + k - 1] - pre[x - 1][y + k - 1] - pre[x + k - 1][y - 1] + pre[x - 1][y - 1];
    };
    auto check = [&](int t) -> bool{
    	// dbg(t);
    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j <= m; j++){
    			v[i][j] = pre[i][j] = 0;
    		}
    	}
    	for(int i = 1; i <= q; i++){
    		auto [x, y, time] = a[i];
    		if(time <= t)v[x][y] = 1;
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + v[i][j];
    		}
    	}
    	for(int i = 1; i + k - 1 <= n; i++){
    		for(int j = 1; j + k - 1 <= m; j++){
    			// dbg(i, j, get(i, j));
    			if(get(i, j) == k * k)return true;
    		}
    	}
    	return false;
    };
    int ans = -1;
    int l = 0, r = 1e9;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
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
    // cin >> t;
    while(t--)solve();
    return 0;
}