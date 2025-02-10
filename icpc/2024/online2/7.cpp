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
constexpr int mod = 998244353;
int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
void solve(){
	int x, y; cin >> x >> y;
	int a, b, c; cin >> a >> b >> c;
	int p0 = a * qmi(a + b, mod - 2) % mod;
	int p1 = b * qmi(a + b, mod - 2) % mod;
	auto dfs = [&](auto self, int x, int y) -> int{
		if(x == 1)return qmi(p0, y);
		if(x == y)return p0;
		if(x > y){
			int cnt = x / y;
			int d = x % y;
			if(d == 0){
				cnt--;
				d += y;
			}
			int res = self(self, d, y) * qmi(p1, cnt) % mod;
			int ff = p0 * ((1 - qmi(p1, cnt) + mod) % mod) % mod * qmi(1 - p1, mod - 2) % mod;
			ff = (ff + mod) % mod;

			return (ff + res) % mod;
		}else{
			int cnt = y / x;
			int d = y % x;
			if(d == 0){
				cnt--;
				d += x;
			}
			return qmi(p0, cnt) * self(self, x, d) % mod;
		}
	};
	int res = (dfs(dfs, x, y)%mod + mod) % mod;
	cout << res << '\n';
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