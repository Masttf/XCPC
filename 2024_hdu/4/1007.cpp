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
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n), b(n);
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 1; i <= n; ++i) std::cin >> b[i];
	int T = std::sqrt(n);
	for(int i = 1; i <= T; ++i) {
		int k;
		std::cin >> k;
		int ans = 0;
		for(int j = 1; j <= n; ++j) {
			a[i] = std::max(a[i], b[(i + k) % n])
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