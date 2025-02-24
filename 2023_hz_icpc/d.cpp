#include <bits/stdc++.h>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::mt19937 rnd(time(0));
	std::vector<int> a = {2,5,5,2};
	std::vector<int> b = {3,1,0,2};
	std::vector<int> w = {3,2,1,4};
	std::vector<int> l = {0,1,2,3};
	std::vector<double> ans(4);
	int T = 0;
	do {
		++T;
		std::vector ra = a;
		for(auto i:l) {
			if(ra[i] < ra[b[i]]) ra[i] += w[i], ans[i] = ra[i];
		}
	} while(std::next_permutation(l.begin(), l.end()));
	for(int i = 0; i < 4; ++i) {
		std::cout << ans[i] / T << ' ';
	}
	return 0;
}