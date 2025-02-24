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
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int l = 0, r = std::sqrt(c);
	auto check = [&](int mid) -> double {
		double y = std::sqrt(c * c - mid * mid);
		
	};
	while(l <= r) {
		int mid = (l + r) >> 1;

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