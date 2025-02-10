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
    vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	b[i] = a[i];
    	sum += a[i];
    }
    int tot = k - sum;
    sort(b.begin() + 1, b.end(), greater<int>());
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
    	pre[i] = pre[i - 1] + b[i];
    }
    // for(int i = 1; i <= n; i++){
    // 	cout << b[i] << ' ';
    // }
    // cout << endl;
    auto check = [&](int x, int val) -> bool{
    	//dbg(x, val, tot);
    	int cnt = 0;
    	int l = 1, r = n;
    	int pos = -1;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(b[mid] < x){
    			pos = mid;
    			r = mid - 1;
    		}else l = mid + 1;
    	}
    	l = pos, r = n;
    	cnt = pos - 1;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		int cost = (mid - pos + 1) * x - (pre[mid] - pre[pos - 1]);
    		if(b[mid] <= val)cost -= x - val;
    		if(cost <= tot){
    			if(b[mid] <= val)cnt = mid - 1;
    			else cnt = mid;
    			l = mid + 1;
    		}else r = mid - 1;
    	}
    	return cnt <= m - 1;
    };
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
    	int l = a[i], r = a[i] + tot;
    	int res = -1;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		int ct = mid - a[i];
    		tot -= ct;
    		if(check(mid + 1, a[i])){
    			res = mid - a[i];
    			r = mid - 1;
    		}else l = mid + 1;
    		tot += ct;
    	}
    	ans[i] = res;
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
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