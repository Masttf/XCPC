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
	std::cin >> n ;
	if(n == 1) std::cout << "1 2\n";
	else if(n == 2) std::cout << "1 2\n1 3\n";
	else {
		std::vector<std::set<int>> v(n / 3 + 10);
		std::vector<int> last(n / 3 + 10);
		v[1].insert(2);
		v[1].insert(3);
		v[1].insert(4);
		last[1] = 4;

		for(int i = 2; i <= n / 3; ++i) {	
			for(int j = 1, cnt = 1; cnt <= 3; ++j) {
				if(j == i) continue;
				++cnt;
				v[j].erase(i);
				v[j].insert(++last[j]);
				v[i].insert(j);
			}
		}
		std::vector<std::pair<int, int>> ans;
		for(int i = 1; i <= n / 3; ++i) {
			for(auto j:v[i]) ans.push_back({std::min(i, j), std::max(i, j)});
		}
		for(int i = n / 3 * 3 + 1; i <= n; ++i) ans.push_back({1, ++last[1]});
		std::sort(ans.begin(), ans.end());
		for(auto [i, j]:ans) {
			std::cout << i << ' ' << j << '\n';
		}
 	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}