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
bool isprime(int x) {
	if(x < 2) return false;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) return false;
	}
	return true;
}

void solve(){
	int x;
	std::cin >> x;
	// for(int i = x; i >= 2; --i) {
	// 	if(isprime(i)) {
	// 		std::cout << i << '\n';
	// 		return ;
	// 	}
	// }
	// std::cout << -1 << '\n';
	if(x >= 2) std::cout << 2 << '\n';
	else std::cout << -1 << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}