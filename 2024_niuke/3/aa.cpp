#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, L, R;
	std::cin >> n >> L >> R;
	std::vector<int> h(n + 1);
	for(int i = 1; i <= n; ++i) std::cin >> h[i], h[i] = (h[i] - 1) / 2;
	int mx = *std::max_element(h.begin() + 1, h.end());
	std::vector<int> but(mx + 1);
	int num0 = 0;
	for(int i = 1; i <= n; ++i) {
		if(h[i] == 0) ++num0;
		else but[h[i]]++;
	}
	while(1) {
		if(but.back() >= L)
	}


}