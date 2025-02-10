#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
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
	// ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { 
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod); 
	}
	ModInt operator - (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator * (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator / (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator == (const ModInt &a) const {
		return x == a.x;
	}
	bool operator != (const ModInt &a) const {
		return x != a.x;
	}
	void operator += (const ModInt &a) {
		x += a.x;
		if (x >= mod) x -= mod;
	}
	void operator -= (const ModInt &a) {
		x -= a.x;
		if (x < 0) x += mod;
	}
	void operator *= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
	}			
	void operator /= (const ModInt &a) {
		*this = *this / a;
	}
	friend ModInt operator + (int y, const ModInt &a){
		int x0 = y + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	friend ModInt operator - (int y, const ModInt &a){
		int x0 = y - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}			
	friend ModInt operator * (int y, const ModInt &a){
		return ModInt(1LL * y * a.x % mod);
	}
	friend ModInt operator / (int y, const ModInt &a){
		return ModInt(y) / a;
	}
	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}
	friend istream &operator>>(istream &is, ModInt &t){
		return is >> t.x;
	}						
				
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
using mint = ModInt<mod>;
constexpr int maxn = 1e5 + 5;
mint f[maxn], inv[maxn];
void init(){
	f[0] = 1;
	for(int i = 1; i < maxn; i++){
		f[i] = f[i - 1] * i;
	}
	inv[maxn - 1] = f[maxn - 1].inv();
	for(int i = maxn - 1; i >= 1; i--){
		inv[i - 1] = inv[i] * i;
	}
};
mint C(int n, int m){
	if(n < 0 || m > n)return 0;
	return f[n] * inv[m] * inv[n - m];
}
void solve(){
    int m, n; cin >> m >> n;
    vector<int> id(m + 1);
    int tot = 0;
    for(int l = 1, r; l <= m; l = r + 1){
    	r = m / (m / l);
    	id[m / l] = ++tot;
    }
    vector val(tot + 1, vector<int>(m + 1, -1));
    vector<mint> res(m + 1); 
    auto dp = [&](auto self, int i, int j) -> mint{
    	if(i <= 1)return 0;
    	if(j <= 2 || i > j) return 0;
    	if(val[id[j]][i] != -1)return mint(val[id[j]][i]);
    	mint ans = 0;
    	res.assign(j + 1, 0);
    	for(int k = 1; k <= j; k++){
    		if(k == 1) res[k] = C(j - 1, i);
    		else res[k] = C(j / k, i);
    	}
    	for(int k = j; k >= 1; k--){
    		for(int p = 2 * k; p <= j; p += k){
    			res[k] -= res[p];
    		}
    	}
    	ans += res[1] * i;
    	for(int k = 2; k <= j; k++){
    		ans += (res[k] - C(j / k - 1, i - 1)) * i;
    	}
    	for(int k = 2; k <= j; k++){
    		ans += self(self, i - 1, j / k);
    	}
    	val[id[j]][i] = ans.val();
    	return ans;
    };
    mint ans = dp(dp, n, m) + dp(dp, n - 1, m);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}