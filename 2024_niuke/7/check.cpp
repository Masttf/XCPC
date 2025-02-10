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
	freopen("1.out", "r", stdin);
	int T;
	std::cin >> T;
	assert(T == 200);
	int S = 5;
	std::vector<int> v(S + 1);
	std::iota(v.begin() + 1, v.end(), 1);
	std::reverse(v.begin() + 1, v.end());
	for(int i = 1; i <= S; ++i) std::cout << v[i] << ' ';
	std::cout << '\n';

	for(int i = 0; i < T; ++i) {
		int num;
		std::cin >> num;
		for(int j = 1; j <= num; ++j) {
			int x, y;
			std::cin >> x >> y;
			if((x == 0 or y == 0 or y > S or x > S)) dbg(x, y);
			if(v[x] > v[y])std::swap(v[x], v[y]);
		}
	}
	if(std::is_sorted(v.begin() + 1, v.end())) std::cout << "ok" << std::endl;
	else std::cout << "Wa" << std::endl;
	for(int i = 1; i <= S; ++i) {
		std::cout << v[i] << ' ';
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