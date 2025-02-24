#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	a.push_back(2 * n - 3);
	for(int i = 1; i < n; ++i) {
		a.push_back(2);
		a.push_back(-1);
	}
	a.push_back(1);
	for(auto i:a) std::cout << i << ' ';
	std::cout << '\n';

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	std::cin >> T;
	while(T--) solve();
	return 0;
}