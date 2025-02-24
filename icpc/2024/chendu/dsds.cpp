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
using mint =ModInt<mod>;
int qmi(int a,int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n + 1);
    for(int i = 2; i <= n; i++){
    	int x; cin >> x;
    	g[x].push_back(i);
    }
    vector<int> dep(n + 1);
    vector<int> dp(n + 1);
    vector<vector<int>> f(25, vector<int>(n + 1));
    auto dfs = [&](auto self, int now, int father) -> void{
    	dep[now] = dep[father] + 1;
    	f[0][now] = father;
    	dp[now] = 1;
    	for(int i = 1; i <= 20; i++){
    		f[i][now] = f[i - 1][f[i - 1][now]];
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		dp[now] = dp[now] * (dp[v] + 1);
    		dp[now] %= mod;
    	}
    	return ;
    };
    dfs(dfs, 1, 0);
    
    auto lca = [&](int a, int b) -> int{
    	if(dep[a] < dep[b])swap(a,b);
    	for(int i = 20; i >= 0; i--){
    		if(dep[a] - (1ll << i) >= dep[b])a = f[i][a];
    	}
    	if(a == b)return a;
    	for(int i = 20; i >= 0; i--){
    		if(f[i][a] != f[i][b]){
    			a = f[i][a];
    			b = f[i][b];
    		}
    	}
    	return f[0][a];
    };
    vector<int> val(n + 1);
	vector<int> ff(n + 1);
    auto dfs1 = [&](auto self, int now, int father) -> void{
    	val[now] = dp[now] + val[father];
    	val[now] %= mod;
    	ff[now] = (ff[father] * qmi(dp[now] + 1,mod - 2) % mod) % mod * dp[now] % mod;
    	ff[now] = ff[now] + dp[now];
    	ff[now] %= mod;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    	}
    };

    dfs1(dfs1, 1, 0);
    for(int i = 1; i <= q; i++){
    	int u, v; cin >> u >> v;
    	int fa = lca(u, v);
    	int ans = ff[fa];
    	ans = (ans + val[u] - val[fa] + mod) % mod;
    	ans = (ans + val[v] - val[fa] + mod) % mod;
    	cout << (ans + mod) % mod << '\n';
    }
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