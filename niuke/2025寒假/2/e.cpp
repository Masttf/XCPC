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
    vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
    vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return max(st[d][l], st[d][r - (1 << d) + 1]);
	};
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	if(x == y){
    		cout << 0 << '\n';
    		continue;
    	}
    	int ans = 0;
    	int pos = x + 1;
    	int sum = a[x];
    	while(pos <= y){
    		int l = pos, r = y;
    		int res = r;
    		while(l <= r){
    			int mid = (l + r) >> 1;
    			if(get(pos, mid) > sum){
    				res = mid;
    				r = mid - 1;
    			}else l = mid + 1;
    		}
    		sum += pre[res - 1] - pre[pos - 1];
    		if(sum < a[res]){
    			ans += a[res] - sum;
    			sum = 2 * a[res];
    		}else sum += a[res];
    		pos = res + 1;
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
/*
-1 不如+1
prei-1 >= ai
如果 prei-1 < ai
那么乘2
ai 只有1e9
最多log次
那么如何快速找到 修改的位置？
区间max > pre i 
?
但是如果+上
*/