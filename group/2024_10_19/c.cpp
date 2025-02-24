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

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<mint> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++){
    	f[i] = f[i - 1] * i;
    }
    vector<mint> cnt(n + 1);
    vector<int>sz(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	sz[now] = 1;
    	cnt[now] = 1;
    	int tot = 0;
    	mint p = 1;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		sz[now] += sz[v];
    		p = p * cnt[v];
    		tot++;
    	}
    	cnt[now] = f[tot] * p;
    	// dbg(now, cnt[now]);
    };
    dfs(dfs, 1, 0);
    vector dp(n + 1, vector<mint>(n + 1));
    dp[1][1] = cnt[1];
    vector sdp(n + 1, vector<mint>(n + 1));
    vector<mint> val(n + 1);
    auto dfs2 = [&](auto self, int now, int father) -> void{
    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j <= n; j++){
    			sdp[i][j] = 0;
    		}
    	}	
    	sdp[0][0] = 1;
    	int son = 0;
    	mint p = 1;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		son++;
    		p *= cnt[v];
    		for(int j = n; j >= sz[v]; j--){
    			for(int k = n - 1; k >= 0; k--){
    				sdp[j][k + 1] += sdp[j - sz[v]][k]; 
    			}
    		}
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		for(int j = sz[v]; j <= n; j++){
    			for(int k = 0; k < n; k++){
    				sdp[j][k + 1] -= sdp[j - sz[v]][k]; 
    			}
    		}
    		val.assign(n + 1, 0);
    		for(int i = 0; i <= n; i++){
	    		for(int j = 0; j < son; j++){
	    			val[i] += sdp[i][j] * f[j] * f[(son - j - 1)];
	    		}
	    	}
	    	for(int i = 0; i <= n; i++){
	    		val[i] /= cnt[now];
	    		val[i] *= p;
	    	}
    		for(int k = 1; k <= n; k++){
    			for(int j = k + 1; j <= n; j++){
	    			dp[v][j] += dp[now][k] * val[j - k - 1];
	    		}
    		}
    		for(int j = n; j >= sz[v]; j--){
    			for(int k = n - 1; k >= 0; k--){
    				sdp[j][k + 1] += sdp[j - sz[v]][k]; 
    			}
    		}
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    	}
    };
    dfs2(dfs2, 1, 0);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cout << dp[i][j] << ' ';
    	}
    	cout << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}