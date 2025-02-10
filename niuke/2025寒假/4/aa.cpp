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
	ModInt(int x = 0) : x(x < 0 ? x % mod + mod : x % mod) {}
	// ModInt(long long x) : x(int(x < 0 ? x % mod + mod : x % mod)) {} 
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
constexpr int mod = 1e9 + 7;
using mint = ModInt<mod>;
void solve(){
    int n; cin >> n;
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
    	a[i] = {l, r};
    }
    mint ans = 0;
    for(int i = 1; i < n; i++){
    	mint res = 0;
    	auto [l, r] = a[i];
    	auto [l2, r2] = a[i + 1];
    	if(l > l2)swap(l, l2), swap(r, r2);
    	int rr = min(r, l2 - 1);
    	int len = (r2 - l2 + 1);
    	int a1 = ((l2 - l) + (r2 - l)) * len / 2;
    	int ar = ((l2 - rr) + (r2 - rr)) * len / 2;
    	res += (a1 + ar) * (rr - l + 1) / 2;
    	auto cal1 = [&](mint a1, mint an, int n) -> mint{
    		return (a1 + an) * n * mint(2).inv();
    	};
    	auto cal2 = [&](mint x) -> mint{
			return x * (x + 1) * (x - 1) * mint(3).inv();
		};
    	if(r > r2){
    		rr = r2 + 1;
    		res += cal1(cal1(rr - l2, rr - r2, len), cal1(r - l2, r - r2, len), r - rr + 1);
    		res += cal2(r2 - l2 + 1);
    	}else if(r >= l2){
    		res += cal2(r - l2 + 1);
    		// dbg(res);
    		len = (r2 - (r + 1) + 1);
    		res += cal1(cal1(r + 1 - l2, r2 - l2, len), cal1(1, r2 - r, len), r - l2 + 1);
    		// dbg(res);
    	}
    	
    	// mint sum = 0;
    	// for(int j = l; j <= r; j++){
    	// 	for(int k = l2; k <= r2; k++){
    	// 		sum += abs(j - k);
    	// 	}
    	// }
    	// dbg(res, sum);
    	ans += res * mint(1ll * (r2 - l2 + 1) * (r - l + 1)).inv();
    }
    cout << ans << '\n';
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
/*
期望 等于值 * 概率
次数就是 （r - l + 1）的和
每两个数产生的值和
怎么做这个呢 不能枚举
交集该怎么算
令$a_n = n - 1$, $S_n = \sum_{i=1}^{i=n} a_i$, $C_n = \sum_{i=1}^{i=n}S_i$ 求$C_n$的通项公式 
$C_n = n * (n - 1) * (n + 1) / 6$
*/