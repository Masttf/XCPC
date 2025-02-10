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
    string t1; cin >> t1;
    if(n == 1){
    	if(t1[0] == '?')cout  << 2 << '\n';
    	else cout << 1 << '\n';
    	return ;
    }
    string t2 = t1;
    reverse(t2.begin(), t2.end());
    mint ans = 0;
    vector dp(n + 1, vector(2, vector<mint>(3)));
    auto run = [&](string s) -> void{
    	s = ' ' + s;
    	for(int i = 1; i <= n; i++){
    		for(int j = 0; j <= 1; j++){
    			for(int k = 0; k <= 2; k++){
    				dp[i][j][k] = 0;
    			}
    		}
    	}
    	auto get1 = [&](int i) -> void{
    		if(i == 1){
    			dp[i][1][1] = 1;
    		}else{
    			for(int j = 0; j <= 1; j++){
    				for(int k = 0; k <= 2; k++){
    					if(dp[i - 1][j][k] == 0)continue;
    					if(j == 0){ // 01
    						dp[i][1][k - 1] += dp[i - 1][j][k];
    					}else{ // 11
    						dp[i][1][k] += dp[i - 1][j][k];
    					}
    				}
    			}
    		}
    	};
    	auto get0 = [&](int i) -> void{
    		if(i == 1){
    			dp[i][0][1] = 1;
    		}else{
    			for(int j = 0; j <= 1; j++){
    				for(int k = 0; k <= 2; k++){
    					if(dp[i - 1][j][k] == 0)continue;
    					if(j == 0){ // 00
    						dp[i][0][k] += dp[i - 1][j][k];
    					}else{ // 10
    						dp[i][0][k + 1] += dp[i - 1][j][k];
    					}
    				}
    			}
    		}
    	};
    	for(int i = 1; i <= n; i++){
    		// dbg(i);
    		if(s[i] == '1'){
    			get1(i);
    		}else if(s[i] == '0'){
    			get0(i);
    		}else{
    			get1(i);
    			get0(i);
    		}
    	}
    	// dbg(dp[n][1][1] + dp[n][0][1]);
    	ans += dp[n][1][0];
    	ans += dp[n][0][2];
    	return ;
    };
    run(t1);
    ans += (dp[n][1][1] + dp[n][0][1]) * (n - 2);
    run(t2);
    cout << ans << '\n';
    // dbg(ans);
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
2e5?
只跟结尾有关
dp ij 表示前i个 以j 结尾的 val数量？

10 为cnt1
01 为cnt2
差值 cnt1 - cnt2
先考虑 0 变 1有啥影响
000 这样的改变中间不影响差值
001 011 不变
010 000 不变
011 001 不变
100 110 不变
101 111 不变
110 100 不变
111 101 不变
也就是说 只要一开始平衡
翻转除头尾都没有影响
00 -> 10 +1
01 -> 11 +1
10 -> 00 -1
11 -> 01 -1

00 -> 01 -1
01 -> 00 +1
10 -> 11 -1
11 -> 10 +1
对差值影响只在 -1， 到 1
这三个

差值为-1 时 头两个要是 00， 01
尾两个是 01， 11

差值为1 时 头两个是10，11
尾 00， 10

0111111110000
差值最多就是-1， 0，1
dpijk 表示前i个以j 结尾的差值为k的方案数
*/