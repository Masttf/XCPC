#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n, m, a, b; cin >> n >> m >> a >> b;
	if(n == 1){
		cout << m << '\n';
		return ;
	}
	if(m == 1){
		cout << n << '\n';
		return ;
	}
	int ans = n * 2 + m * 2 - 4;
	int sum = 0;
	if(a != 1 && a != n){
		sum = max({sum, m - 2});
	}
	if(b != 1 && b != m){
		sum = max({sum, n - 2}); 
	}
	cout << ans + sum << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
} 