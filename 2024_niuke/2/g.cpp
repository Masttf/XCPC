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
constexpr int mod = 1e9 + 7;
using mint =ModInt<mod>;
constexpr int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int N = 1000;

	vector val(N + 1, vector<pair<int,mint>>());
	for(int i = 1; i <= n; i++){
		int mask = 0;
		mint v = 1;
		for(int j = 0; j < 11; j++){
			while(a[i] % p[j] == 0){
				mask ^= (1 << j);
				if(!(mask >> j & 1)){
					v *= p[j];
				}
				a[i] /= p[j];
			}
		}
		//dbg(i, mask, v);
		assert(a[i] == 1 || a[i] > 32);
		val[a[i]].push_back({mask, v});
	}
	vector<mint> dp(1 << 12);
	dp[0] = 1;
	for(int i = 1; i <= N; i++){
		if(val[i].empty())continue;
		
		for(auto [mask, v] : val[i]){
			vector<mint> ndp = dp;
			if(i != 1)mask |= 1 << 11;
			for(int s = 0; s < (1 << 12); s++){
				int t = s ^ mask;
				mint res = dp[s] * v;
				int both = s & mask;
				for(int j = 0; j < 11; j++){
					if(both >> j & 1){
						res *= p[j];
					}
				}
				if(both >> 11 & 1) res *= i;
				ndp[t] += res;
			}
			dp = ndp;
		}
		for(int s = 1 << 11; s < (1 << 12); s++){
			dp[s] = 0;
		}
	}
	mint ans = dp[0] - 1;
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}