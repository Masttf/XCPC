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
void solve(){
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	if(n == 1) {
		std::cout << "0\n";
		return ;
	}
	std::set<std::pair<int, int>> mp;
	int x = 0, y = 0;
	int bf = 0, f = 0;
	bool be = 0;
	int sz = s.size();
	int ok = 1;
	for(int j = 0; j < sz; j++) {
		char i = s[j];
		if(mp.count({x, y})) {
			std::cout << "-1\n";
			return ;
		}
		// dbg(x, y);
		mp.insert({x, y});
		// if(j == sz - 1){
		// 	dbg()
		// }
		if(j == sz - 1){
			if(x != 0 || y != -1)ok = 0;
		}
		if(i == 'R') ++f;
		else if(i == 'L') --f;
		f += 4;
		f %= 4;
		// dbg(f);
		if(f == 0) ++y;
		else if(f == 1) ++x;
		else if(f == 2) --y;
		else --x;
	}
	// dbg(bx, by, x, y);
	if(x == 0 and y == 0 and ok) std::cout << "1\n";
	else std::cout << "0\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}