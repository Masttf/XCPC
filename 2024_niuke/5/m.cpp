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
	int c, a, b; cin >> c >> a >> b;
	pair<int, int>ans = {c, 2};
	pair<int, int>ans2 = {c * a - b, b};
	auto [x, y] = ans2;
	int d = __gcd(x, y);
	
	ans2.first /= d;
	ans2.second /= d;
	d = __gcd(c, 2ll);
	ans = {c / d, 2 / d};
	int lcm = ans.second * ans2.second / __gcd(ans.second, ans2.second);
	pair<int, int>res;
	int t1 = ans.first * lcm / ans.second;
	int t2 = ans2.first * lcm / ans2.second;
	if(t1 > t2)res = ans;
	else res = ans2;
	cout << res.first << '/' << res.second << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}