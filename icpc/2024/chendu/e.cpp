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
void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n + 1);
    for(int i = 2; i <= n; i++){
    	int x; cin >> x;
    	g[x].push_back(i);
    	g[i].push_back(x);
    }
    vector<mint> dp(n + 1);
    
    vector<int>dfn(n + 1), dep(n + 1);
    vector st(21, vector<pair<int, int>>(n + 1));
    int tot = 0;
    auto dfs = [&](auto self, int now, int father) -> void{
    	dp[now] = 1;
    	dfn[now] = ++tot;
    	dep[now] = dep[father] + 1;
    	st[0][tot] = {dep[now], father};
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		dp[now] *= dp[v] + 1;
    	}
    };
    dfs(dfs, 1, 0);
    for(int k = 1; k <= 20; k++){
    	for(int i = 1; i + (1ll << k) <= n + 1; i++){
    		st[k][i] = min(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
    	}
    }
    auto lca = [&](int a, int b) -> int{
    	if(a == b)return a;
    	if(dfn[a] > dfn[b])swap(a, b);
    	int l = dfn[a] + 1;
    	int r = dfn[b];
    	int len = (r - l + 1);
    	int d = __lg(len);
    	return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
    };
    vector<mint> val(n + 1);
    vector<mint> ff(n + 1);
    auto ndp = dp;
    auto dfs1 = [&](auto self, int now, int father) -> void{
    	// dbg(now, ndp[now]);
    	ff[now] = dp[now];
    	ff[now] += ff[father];
    	val[now] = ndp[father] * dp[now];
    	int sz = g[now].size();
    	vector<mint> pre(sz + 1), suf(sz + 5);
    	pre[0] = 1;
    	suf[sz + 1] = 1;
    	for(int i = 0, j = 1; i < g[now].size(); i++, j++){
    		int v = g[now][i];
    		pre[j] = pre[j - 1] * (ndp[v] + 1);
    	}
    	for(int i = g[now].size() - 1, j = sz; i >= 0; i--, j--){
    		int v = g[now][i];
    		suf[j] = suf[j + 1] * (ndp[v] + 1);
    	}
    	for(int i = 0, j = 1; i < g[now].size(); i++, j++){
    		int v = g[now][i];
    		if(v == father)continue;
    		mint lasv = ndp[v];
    		mint last = ndp[now];
    		ndp[now] = pre[j - 1] * suf[j + 1];
    		ndp[v] = dp[v] * (ndp[now] + 1);
    		self(self, v, now);
    		ndp[v] = lasv;
    		ndp[now] = last;
    	}
    };
    dfs1(dfs1, 1, 0);
    for(int i = 1; i <= q; i++){
    	int u, v; cin >> u >> v;
    	int fa = lca(u, v);
    	mint ans = val[fa] + dp[fa];
    	ans += ff[u] - ff[fa];
    	ans += ff[v] - ff[fa];
    	cout << ans << '\n';
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