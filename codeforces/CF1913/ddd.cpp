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
constexpr int mod = 998244353;
using mint =ModInt<mod>;

void solve(){
	int n; cin >> n;
	vector<int>a(n + 1);
	vector st(21, vector<pair<int, int>>(n + 1));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st[0][i] = {a[i], i};
	}
	for(int s = 1; s <= 20; s++){
		for(int i = 1; i + (1ll << s) <= n + 1; i++){
			st[s][i] = min(st[s - 1][i], st[s - 1][i + (1ll << (s - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int len = r - l + 1;
		int d = __lg(len);
		return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
	};
	auto dfs = [&](auto self, int l, int r) -> mint{
		int pos = get(l, r);
		mint d1 = 1, d2 = 1;
		if(pos != l)d1 = self(self, l, pos - 1);
		if(pos != r)d2 = self(self, pos + 1, r);
		mint ans = d1 * d2;
		if(l == 1 && r == n){

		}else if(l == 1){
			ans += d1;
		}else if(r == n){
			ans += d2;
		}else ans += d1 + d2 - 1;
		return ans;
	};
	cout << dfs(dfs, 1, n) << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}