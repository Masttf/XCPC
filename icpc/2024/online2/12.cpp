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
	int t; cin >> t;
	int tt = 1 + 8 * t;
	int d = sqrt(tt);
	while(d * d < tt)d++;
	while(d * d > tt)d--;
	int x = (1 + d) / 2;
	int a1 = (x * x - x + 2 * t);
	int a2 = (x * 2);
	int dd = __gcd(a1, a2);
	a1 /= dd;
	a2 /= dd;
	cout << a1 << ' ' << a2 << '\n';
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