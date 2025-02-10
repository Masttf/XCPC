#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 300005;
int a[maxn], ans[maxn];
void solve() {
	int n ;cin>>n;
	int mx = -INT_MAX, mi = INT_MAX;
	for (int i = 1; i <= n; i++)cin >> a[i], mx = max(mx, a[i]), mi = min(mi, a[i]);
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	int sum = 0;
	int f = 1;
	for (int i = 1; i <= n; i++) {
		if (abs(sum + a[l]) < mx - mi) {
			ans[i] = a[l];
			sum += a[l];
			l++;
		} else {
			ans[i] = a[r];
			sum += a[r];
			r--;
		}
		if (abs(sum) >= mx - mi) f = 0;
	}
	if (f) {
		cout << "YES\n";
		for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
		cout << '\n';
	} else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t ;cin>>t ;
	while (t--) {
		solve();
	}
	return 0;
}

