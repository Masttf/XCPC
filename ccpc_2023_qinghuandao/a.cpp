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
std::set<std::pair<int, int>> s;
void solve(){
	int n, k;
	std::cin >> n >> k;
	int p = 1;
	for(int i = 1; i < n; ++i) {
		if(p > k) return ;
		std::cout << i << ' ' << i << '\n';
		s.insert({i, i});
		p++;
		if(p > k) return ;
		std::cout << i << ' ' << i + 1 << '\n';
		s.insert({i, i + 1});
		p++;
		if(p > k) return ;
	}
	std::cout << n << ' ' << n << '\n';
	s.insert({n, n});
	p++;
	if(p > k) return ;
	std::cout << n << ' ' << 1 << '\n';
	s.insert({n, 1});
	p++;
	if(p > k) return ;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(!s.count({i, j})) {
				std::cout << i << ' ' << j << '\n';
				p++;
				if(p > k) return ;
			}
		}
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