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
	int n,m;cin >> n >> m;
	if (n > m) {
		cout << n - m << '\n';
		return ;
	}
  	int l = 1,r;
  	int res = 1e18,ans = n - m;
  	m = m - 1;
  	while (l <= m) {
  		r = m / (m / l);
  		//dbg(l,r);
  		res = min(res,(m / l) * l);
  		l = r + 1;
  		if (l > n) break;
  	}
  	//dbg(res);
  	cout << res + ans << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}