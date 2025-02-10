#include <bits/stdc++.h>

using namespace std;
#define int long long


void solve() {
	int n;
	cin >> n;
	vector<set<string>> mp(26);
	vector<int> p(26);
	for(int i = 1; i <= n; ++i) {
		string name, status;
		char problem;
		cin >> name >> problem >> status;
		// cout << i << endl;
		int id = problem - 'A';
		if(status == "accepted" && !mp[id].count(name)) {
			p[id]++;
			mp[id].insert(name);
			// cout << name << endl;
		}
	}
	int mx = *max_element(p.begin(), p.end());
	// cout << mx << endl;
	for(int i = 0; i < 26; ++i) {
		if(p[i] == mx) {
			std::cout << (char)(i + 'A') << '\n';
			return ;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}