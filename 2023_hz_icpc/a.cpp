#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::map<std::string, int> mp;
	std::vector<std::array<std::vector<int>, 26>> v;
	{
		std::string name;
		char problem;
		int time;
		std::string statue;
		for(int i = 0; i < n; ++i) {
			std::cin >> name >> problem >> time >> statu;
			auto it = mp.find(name);
			if(it == mp.end()) {
				mp[name] = v.size();
				v.emplace_back(new array<std::vector<int>, 26>);
				v[problem - 'A'].push_back();
			}
		}

	}


}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	std::cin >> T;
	while(T--) solve();
	return 0;
}