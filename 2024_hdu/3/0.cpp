#include <bits/stdc++.h>

#define int long long 

void solve () {
	int n, m;
	std::cin >> n >> m;
	bool ok = 1;
	int l = 0, r = 1e18, lastT = 0;
	int pos = 0;
	// std::cout << "-------" << ok << '\n';
	auto move = [&](int p, int q) ->void {
		int dis = std::abs(p - pos);
		int ch_time = q - lastT;
		if(dis > ch_time) ok = 0;
		r = std::min(r, q - dis + 1);
		if((ch_time - dis) % 2 == 1) ++l; 
		if(l > r) ok = 0;
	};
	while(m--) {
		// std::cout << ok << '\n';
		// std::cout << "-------" << ok << '\n';

		int op, p, q;
		std::cin >> op;
		if(op == 0) {
			std::cin >> p >> q;
			move(p, q);
		} else if(op == 2) {
			if(!ok) std::cout << "bad\n";
			else if(r >= 1e10) std::cout << "inf\n";
			else std::cout << r << '\n';
		} else {
			if(!ok) std::cout << "bad\n";
			else std::cout << l << '\n';
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	std::cin >> T;
	while(T--) solve();
	return 0;
}