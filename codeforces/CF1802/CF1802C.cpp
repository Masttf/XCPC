#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
	int n, m;
	cin >> n >> m;
	cout << n * m << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {//可以得到容易一行相邻的异或就是（j）^j+1,^j^j+1就是0，只要i移的位置不影响j
			cout << (i << 10) + j << " \n"[j == m - 1];
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
