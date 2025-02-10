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
    vector<int>a(n + 1), b(k + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= k; i++){
    	cin >> b[i];
    }
    int sum = 0;
    for(int i = 1; i <= k; i++){
    	sum += (1 << (k - 1)) * b[i];
    }
    int m = (1ll << (k - 1));
    vector<int> cnt(m);
    auto check = [&](__int128 x) -> bool{
    	vector<__int128> t(n + 1);
    	for(int i = 1; i <= n; i++){
    		t[i] = x * a[i];
    	}
    	for(int i = k; i >= 1; i--){
    		__int128 tot = b[i];
    		int lim = (1ll << (i - 1));
    		for(int j = 1; j <= n; j++){
    			if(tot == 0)break;
    			__int128 d = t[j] / lim;
    			d = min(tot, d);
    			t[j] -= lim * d;
    			tot -= d;
    		}
    		if(tot > 0){
    			for(int j = 0; j < lim; j++)cnt[j] = 0;
    			for(int j = 1; j <= n; j++){
    				if(t[j] >= lim){
    					while(1);
    				}
    				cnt[t[j]]++;
    			}
    			for(int j = lim - 1; j >= 1; j--){
    				if(tot == 0)break;
    				int tmp;
    				if(tot > cnt[j])tmp = cnt[j];
    				else tmp = tot;
    				cnt[j] -= tmp;
    				tot -= tmp;
    			}
    			int idx = 1;
    			for(int j = 0; j < lim; j++){
    				for(int K = 1; K <= cnt[j]; K++){
    					t[idx++] = j;
    				}
    			}
    			while(idx <= n){
    				t[idx++] = 0;
    			}
    		}
    		// dbg(i);
    		// for(int j = 1; j <= n; j++){
    		// 	cout << t[j] << ' ';
    		// }
    		// cout << endl;
    	}
    	__int128 mx = 0;
    	for(int i = 1; i <= n; i++){
    		mx = max(mx, t[i]);
    	}
    	if(mx > 0)return false;
    	return true;
    };
    int ans = 0;
    int l = 0, r = 1e18;
    while(l <= r){
    	// dbg(l, r);
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
    cin >> t;
    while(t--)solve();
    return 0;
}