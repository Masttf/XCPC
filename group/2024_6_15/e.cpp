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

constexpr int N = 1e5 + 21;
void solve(){
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	int num = std::count(s.begin(), s.end(), '1');
	int mx = 1LL << k - 1;
	for(int i = 0; i <= std::min(n + k, (1LL << k) - 1); ++i) {
		std::bitset<20> bit(i);
		// dbg(bit.count());
		if(bit.count() + num == i) {
			// dbg(bit.count() + num, i);
			for(int j = k - 1; j >= 0; --j) {
				if(bit[j]) std::cout << 1;
				else std::cout << 0;
			}
			std::cout << '\n';
			return ;
		}
	}
	std::cout << "None\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}