#include<bits/stdc++.h>
//#define int long long
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
	ModInt(long long x) : x(int(x % mod)) {} 
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
constexpr int mod = 998244353, maxn = 1e7 + 5;
using mint =ModInt<mod>;
mint f[maxn], inv[maxn];
void init(){
	f[0] = inv[0] = 1;
	for(int i = 1; i < maxn; i++){
		f[i] = f[i - 1] * i;
	}
	inv[maxn - 1] = f[maxn - 1].inv();
	for(int i = maxn - 2; i >= 1; i--){
		inv[i] = inv[i + 1] * (i + 1);
	}
}
void solve(){
	int n; cin >> n;
	vector<int> a(30);
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
		char t;
		int x; cin >> t >> x;
		a[t - 'a'] = x;
		sum += x;
		cnt += x & 1;
	}
	if(cnt == 0){
		mint p = f[sum / 2];
		for(int i = 0; i < 26; i++)p *= f[a[i]] * inv[a[i] / 2];
		p *= inv[sum];
		p = (1 - p) / mint(2);
		cout << p << '\n';
	}else if(cnt == 1){
		mint p = f[sum / 2];
		for(int i = 0; i < 26; i++)p *= f[a[i]] * inv[a[i] / 2];
		p *= inv[sum];
		p = (1 + p) / mint(2);
		cout << p << '\n';
	}else{
		cout << mint(2).inv() << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}