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
	cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; ++i) std::cin >> v[i];
	int l = -1, r = -1, x = -1, y = -1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(v[i][j] == 'x') {
				if(l == -1 and x == -1) l = i, x = j;
				r = i, y = j;
			}
		}
	}
	// if()
	// dbg(l, r, x, y);
	n = r - l + 1;
	m = y - x + 1;
	int k = std::gcd(n, m);
	n /= k;
	m /= k;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			std::cout <<  'x';
		}
		std::cout << '\n';
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