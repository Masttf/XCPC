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
constexpr int mod = 998244353;
using mint = ModInt<mod>;
constexpr int maxn = 5005;
mint f[maxn], inv[maxn];
void init(){
	f[0] = inv[0] = 1;
	for(int i = 1; i  < maxn; i++){
		f[i] = f[i - 1] * i;
	}
	inv[maxn - 1] = f[maxn - 1].inv();
	for(int i = maxn - 1; i >= 1; i--){
		inv[i - 1] = inv[i] * i;
	}
}
mint C(int n, int m){
	if(n < 0 || m > n)return 0;
	return f[n] * inv[m] * inv[n - m];
}
template<class T, 
	class Cmp = std::less<T>>
struct ST{
	int n, k;
	const Cmp cmp = Cmp();
	vector<vector<T>> st;
	ST(){}
	ST(const vector<T> &a){
		init(a);
	}
	void init(const vector<T> &a){
		n = a.size() - 1;
		k = __lg(n);
		st.resize(k + 1, vector<T>(n + 1));
		for(int i = 1; i <= n; i++){
			st[0][i] = a[i];
		}
		for(int s = 1; s <= k; s++){
			for(int i = 1; i + (1 << s) <= n + 1; i++){
				st[s][i] = min(st[s - 1][i], st[s - 1][i + (1 << (s - 1))], cmp);
			}
		}
	}
	T get(int l, int r){
		int d = __lg(r - l + 1);
		return min(st[d][l], st[d][r - (1 << d) + 1], cmp);
	}
};
void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // vector dp(n + 1, vector<mint>(k + 1));
	// vector cnt(n + 1, vector<mint>(k + 1));
	// cnt[0][0] = 1;
    // for(int j = 1; j <= k; j++){
    // 	for(int i = 1; i <= n; i++){
    // 		int mx = a[i], mi = a[i];
    // 		for(int d = i; d >= 1; d--){
    // 			mx = max(mx, a[d]);
    // 			mi = min(mx, a[d]);
    // 			if(cnt[d - 1][j - 1] == 0)continue;
    // 			dp[i][j] += dp[d - 1][j - 1] + cnt[d - 1][j - 1] * mx * mi;
    // 			cnt[i][j] += cnt[d - 1][j - 1];
    // 		}
    // 	}
    // }
    // cout << dp[n][k] << '\n';
    ST<int, greater<int>> stMax(a);
	ST stMin(a);
	mint ans = 0;
	auto get = [&](int N, int num) -> mint{
		if(num < 0)return 0;
		return C(N - 1, num - 1);
	};
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int mx = stMax.get(i, j);
			int mi = stMin.get(i, j);
			// dbg(i, j, mx, mi);
			mint res = mint(mx * mi);
			//ij 为一段的方案数
			if(i == 1 && j == n){
				if(k == 1)ans += res;
			}else if(i == 1 || j == n){
				ans += res * get(n - (j - i + 1), k - 1);
			}else{
				ans += res * get(n - (j - i + 1) - 1, k - 2);
			}
			// dbg(i, j, ans, res);
		}
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    // cin >> t;
    while(t--)solve();
    return 0;
}
/*
dpij 表示 前i个划分了j段的权值和,还要方案数
max * min * 方案
dpij <- dpj(k - 1) j < i + 
n ^ 3???
n^2 log可过

n^3 -> n^2log
也就是说优化掉枚举d的那层
有什么共同的性质都是从 j - 1转移过来
那么我可以先把j - 1 放到最外层
问题在于 mx * mi * cnt
cnt 和 dp是好做的
关键在于 mx 和mi
应该是一段一段的算
如何log？
如果ai < a（i - 1）那么max 肯定和a(i - 1)的变化一样
但是min 不一样
也就是max的变化曲线是和上一个比它大的数一样
min是和上一次比它小的数一样

分治？
dplrj 表示 l，r区间分j段的权值和
怎么转移
枚举分界点，复杂度n ^ 4

算贡献
mx * mi * 方案数
*/