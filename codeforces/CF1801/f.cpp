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
	int n, m;
	std::cin >> n >> m;
	int l = 1, r = n, ans = 1;
	auto fact(int p)->bool {
		int k = m / p * p;
		if(k < m) k += p;
		return k - m;
	};
	while(l <= r) {
		int L = (r - l) / 3 + l, R = (r - l) / 3 * 2 + l;
		if(fact(L) < fact(R)) r = R - 1;
		else l = L + 1;
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