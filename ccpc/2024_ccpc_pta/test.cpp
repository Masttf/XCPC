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
using Pii = std::pair<int, int>;
void solve(){
	int n;
	std::cin >> n;
	vector<Pii> v(n);
	for(int i = 0; i < n; ++i) {
		std::cin >> v[i].first >> v[i].second;
	}
	std::sort(v.begin(), v.end());
	std::cout << "YES\n";
	for(int i = 0; i < n - 1; ++i) {
		std::cout << v[i].first << ' ' << v[i].second << '\n';
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