#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int ppmax, a, b, c, d, e, f;
	cin >> ppmax >> a >> b >> c >> d >> e >> f;
	int sum = a + b + c + d + e + f;
	int x = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) * 1000;
	int y = 3 * sum;
	int ans = x / y;
	if(ans % 10 >= 5)ans += 10;
	cout << ans / 1000 << '.';
	int D = ans % 1000 / 10;
	if(D <= 9)cout << 0;
	cout << D;
	cout << "% ";
	x = (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) - 8 * 32 * sum;
	y = 320 * sum;
	if(x <= 0){
		cout << 0 << '\n';
		return ;
	}
	x *= 50 * ppmax;
	int res = x / y;
	int ans2 = res / 10;
	if(res % 10 >= 5)ans2++;
	cout << ans2 << '\n';
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