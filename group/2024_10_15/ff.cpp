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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int mx = 0;
			for(int k = i + 1; k <= j - 1; k++){
				mx = max(mx, a[k]);
			}
			if(mx <= min(a[i], a[j])){
				dbg(i, j);
				// ans++;
			}
		}

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
		if(l > r)return 0;
		int d = __lg(r - l + 1);
		return max(st[d][l], st[d][r - (1 << d) + 1]);
	};
   	for(int i = 1; i <= n; i++){
   		int l = 1, r = i - 1;
   		int res = i;
   		// dbg(l, r);
   		while(l <= r){
   			int mid = (l + r) >> 1;
   			if(get(mid + 1, i - 1) <= min(a[mid], a[i])){
   				res = mid;
   				r = mid - 1;
   			}else l = mid + 1;
   		}
   		dbg(res, i);
   		ans += i - res;
   	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}