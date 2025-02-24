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
template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	//ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
	ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
	ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
	bool operator == (const ModInt &a) const { return x == a.x; };
	bool operator != (const ModInt &a) const { return x != a.x; };
	void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
	void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
	void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }			
	void operator /= (const ModInt &a) { *this = *this / a; }
	friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }			
	friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
	friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
	friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
	friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
constexpr int mod = 998244353, maxn = 255;
using mint = ModInt<mod>;
mint dp[maxn][maxn][maxn];
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	// for(int s = 1; s <= n; s++){
	// 	dp[s][s][s] = 1;
	// 	for(int i = 1; i <= s - 1; i++){
	// 		for(int j = 1; j <= s - 1; j++){
	// 			for(int k = 1; k <= s - 1; k++){
	// 				dp[s][s][s] += dp[i][j][k];
	// 				if(a[s] == a[i]){
	// 					dp[s][j][k] += dp[i][j][k];
	// 					dp[i][s][k] += dp[i][j][k];
	// 					dp[i][j][s] += dp[i][j][k];
	// 					dp[s][s][k] += dp[i][j][k];
	// 					dp[s][j][s] += dp[i][j][k];
	// 					dp[i][s][s] += dp[i][j][k];
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// mint ans = 0;
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		for(int k = 1; k <= n; k++){
	// 			ans += dp[i][j][k];
	// 		}
	// 	}
	// }
	// cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] + dp[i][j][k - 1]
				 - dp[i][j - 1][k - 1] - dp[i - 1][j][k - 1] - dp[i -1][j - 1][k]
				 +dp[i - 1][j- 1][k -1];
				 if(a[i] == a[j] && a[j] == a[k])dp[i][j][k] += dp[i - 1][j - 1][k - 1] + 1;
			}
		}
	}
	cout << dp[n][n][n] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}