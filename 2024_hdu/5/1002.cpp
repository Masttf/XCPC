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
	vector<int> a(n);
	for(int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a.begin(), a.end());
	if(a.front() == 1) {
		std::cout << n - 1 << '\n';
		return ;
	}
	std::multiset<int> s;
	for(int i = 0; i < n; ++i) s.insert(a[i]);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(a[i] % a[j] == 0) {
				s.erase(s.find(a[i]));
				break;
			}
		}
	}
	a.clear();
	for(auto i:s) a.push_back(i);
	int ans = n - (int)s.size();
	n = a.size();
	if(a.size() == 1) {
		std::cout << ans << '\n';
		return ;
	}
	int k = 0;
	for(int i = 1; i < n; ++i) k = std::gcd(k, a[i]);
	if(a.front() == k) {
		std::cout << ans + n - 1 << '\n';
	} else if(a.front() < k) {
		std::cout << ans + n << '\n';
	} else {
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				int k1 = a[j] % a[i];
				int g = 0;
				for(int k = 0; k < n; ++k) {
					if(k == j) continue;
					g = std::gcd(g, a[k]);
				}
				if(k1 == g or a[j] < g) {
					std::cout << ans + n << '\n';
					return ;
				}
			}
		}
		std::cout << ans + n + 1 << '\n';
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