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
mint dp[105][8][(1 << 16)][2];
void solve(){
    int n, m, k; cin >> n >> m >> k;
    string w; cin >> w;
    int val = 0;
    for(int i = 0; i < k; i++){
    	val += (w[i] - '0') * (1 << (k - 1 - i));
    }

    int N = 1 << (1 << (k + 1));
    for(int i = 0; i < (1 << k); i++){
    	dp[k][i][0][i == val] = 1;
    }
    int bit = ((1 << (k - 1)) - 1);
    // dbg(val, bit, N, (1 << 16));
    for(int i = k; i <= max(n, m); i++){
    	for(int j = 0; j < (1 << k); j++){
    		for(int d = 0; d < N; d++){
    			for(int _ = 0; _ <= 1; _++){
    				if(dp[i][j][d][_] == 0)continue;
    				// dbg(i, j, d, _, dp[i][j][d][_]);
    				int v = (j & bit) * 2;
	    			int to = j * 2;
	    			// dbg(1 << to);
	    			dp[i + 1][v][d | (1 << to)][(v == val) | _] += dp[i][j][d][_];
    				dp[i + 1][v + 1][d | (1 << (to + 1))][(v + 1 == val) | _] += dp[i][j][d][_];
    			}
    		}
    	}
    	// dbg(i);
    }
    vector<mint> res1(N), res2(N);
    vector<int> v1, v2;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < (1 << k); j++){
    		res1[i] += dp[n][j][i][1];
    		res2[i] += dp[m][j][i][1];
    	}
    	if(res1[i].val() > 0) v1.push_back(i);
    	if(res2[i].val() > 0) v2.push_back(i);
    	// dbg(i, res1[i]);
    }
    // dbg("yes");
    mint ans = 0;
    for(auto x : v1){
    	for(auto y : v2){
    		if(x & y)continue;
    		ans += res1[x] * res2[y];
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}