#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node {
	int x, y, z;
};
void solve(){
	vector<node> v(8);
	for(int i = 0; i < 8; ++i) {
		std::cin >> v[i].x >> v[i].y >> v[i].z;
	}
	auto check=[&](int p) ->bool {
		map<int, int> mp;
		for(int i = 0; i < 8; ++i) {
			if(p == i) continue;
			int dis = (v[p].x - v[i].x) * (v[p].x - v[i].x) + (v[p].y - v[i].y) * (v[p].y - v[i].y) + (v[p].z - v[i].z) * (v[p].z - v[i].z);
			mp[dis] ++;
		}
		if(mp.size() < 3) return false;
		auto i1 = mp.begin();
		auto i2 = ++mp.begin();
		auto i3 = ++++mp.begin();
		if(i1->second == 3 and i2->second == 3 and i3->second == 1 and i1->first * 2 == i2->first and i1->first * 3 == i3->first) return true;
		return false;
	};
	for(int i = 0; i < 8; ++i) {
		if(!check(i)) {
			std::cout << "NO\n";
			return ;
		}
	}
	std::cout << "YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}