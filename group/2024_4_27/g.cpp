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
	int d;
	std::cin >> d;
	std::vector<std::pair<int, int>> res;
	for(int i = 1; i * i + i < 2 * d; ++i) {
		int mid = 2 * d - i * i - i;
		if(mid % (2 * i) == 0) res.push_back({mid / (2 * i), mid / (2 * i) + i});
	} 
	std::sort(res.begin(), res.end(), std::greater<>());
	res.erase(std::unique(res.begin(), res.end()), res.end());
	std::cout << res.size() << '\n';
	for(auto [i, j] : res) {
		std::cout << i << ' ' << j << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}