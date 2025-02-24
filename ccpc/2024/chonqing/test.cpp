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
double eps = 1e-11;
void solve(){
	int ppmax, a, b, c, d, e, f;
	cin >> ppmax >> a >> b >> c >> d >> e >> f;
	int sum = a + b + c + d + e + f;
	double acc = (300 * a + 300 * b + 200 * c + 100 * d + 50 * e) * 1.0 / (3 * sum);
	double tmp = (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) * 1.0 / (320 * sum);
	double pp = max(0.0, tmp - 0.8) * 5 * ppmax;
	// cout << fixed << setprecision(18) << pp << "\n";
	cout << fixed << setprecision(2) << round(acc) << "% ";
	cout << fixed << setprecision(0) << round(pp) << '\n';
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