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
    int n, k, z; cin >> n >> k >> z;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = a[1];
	int sum = a[1];
	int mx = 0;
	for(int i = 2, step = 1; i <= n && step <= k; i++, step++){
		mx = max(mx, a[i - 1] + a[i]);
		sum += a[i];
		int tot = (k - step) / 2;
		int d = sum + min(tot, z) * mx;
		int t = d;
		int rem = k - step - min(tot, z) * 2;
		if(tot < z && rem > 0)t = max(t, d + a[i - 1]);
		if(rem > 0)t = max(t, d + a[i + 1]);
		ans = max(ans, t);
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
/*
不能连续两次left

*/