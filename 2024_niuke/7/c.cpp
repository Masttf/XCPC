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
// int XX = 0;
void print(const std::vector<int> &p) {
	// ++XX;
	assert(p.size() % 2 == 0);
	std::cout << p.size() / 2 << ' ' ;
	for(auto i : p) std::cout << i << ' ' ;
	std::cout << '\n';
}
void solve(){
	// freopen("1.out", "w", stdout);
	int n;
	std::cin >> n;
	int T = 200;
	std::cout << T << '\n';
	std::vector<int> x;
	for(int i = 1; i <= n / 2; ++i) {
		x.push_back(i);
		x.push_back(n - i + 1);
	}
	--T;
	print(x);
	x.clear();
	int D = std::__lg(n) + 2;
	std::vector<std::vector<int>> d(D);
	auto dfs = [&](auto self, int l, int r, int dep)->void{
		if(l == r) return ;
		int mid = l + r >> 1;
		int len = r - l + 1;
		for(int i = 0; i < len / 2; ++i) {
			d[dep].push_back(l + i);
			d[dep].push_back(mid + i + 1);
		}
		self(self, l, mid, dep + 1);
		self(self, mid + 1, r, dep + 1);
	};
	dfs(dfs, 1, n, 0);
	for(int i = 0; i < D; ++i) {
		if(!d[i].empty()) print(d[i]), --T;
	}
	std::mt19937_64 rnd(time(0));
	while(T--) {
		std::vector<int> mid(n / 2 * 2);
		std::iota(mid.begin(), mid.end(), 1);
		if(n % 2 == 1 and T % 2 == 1) {
			int pos = rnd() % n + 1;
			mid[pos] = n;
		}
		std::shuffle(mid.begin(), mid.end(), rnd);
		print(mid);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	// dbg(XX);
	return 0;
}