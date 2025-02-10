#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		c[i] = std::min(c[i], c[i + 1]);
	}
	
	int k;
	std::cin >> k;
	
	std::vector<int> a(n);
	int t = k;
	for (int i = 0; i < n; i++) {
		int v = c[i] - (i ? c[i - 1] : 0);
		if (v > 0) {
			t = std::min(t, k / v);
		}
		k -= t * v;
		a[i] = t;
		std::cout << a[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
