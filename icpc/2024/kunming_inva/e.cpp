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
	int n, K; cin >> n >> K;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> pre(n + 1), suf(n + 5);
	for(int i = 1; i <= n; i++){
		pre[i] = __gcd(pre[i - 1], a[i]);
	}
	for(int i = n; i >= 1; i--){
		suf[i] = __gcd(suf[i + 1], a[i]);
	}
	vector<int>b(n + 1);
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		b[i] = a[i] + K;
		st[0][i] = b[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = __gcd(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return __gcd(st[d][l], st[d][r - (1ll << d) + 1]);
	};
	int ans = pre[n];
	for(int i = 1; i <= n; i++){
		// dbg(i);
		int now = i;
		int g = b[i];
		while(now <= n){
			//dbg(now, g);
			int l = now, r = n;
			int res = now;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(get(i, mid) == g){
					res = mid;
					l = mid + 1;
				}else r = mid - 1;
			}
			//dbg(res, suf[res + 1]);
			ans = max(ans, __gcd(__gcd(pre[i - 1], suf[res + 1]), g));
			now = res + 1;
			g = get(i, now);
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