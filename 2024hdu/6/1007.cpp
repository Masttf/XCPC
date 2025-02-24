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
	vector<int>pos(n + 1);
	vector<int>par(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int rt = pos[0];
	vector<mint>dp(n + 1, 1);
	vector<mint>temp(n + 1, 1);
	auto dfs = [&](auto self, int now, int father) -> void{
		par[now] = father;
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
			dp[now] *= dp[v] + 1;
		}
	};
	dfs(dfs, rt, 0);
	//dbg("yes");
	vector<int>vis(n + 1);
	mint ans = n;
	mint res = dp[rt];
	vis[rt] = 1;
	for(int i = 1; i < n; i++){
		int u = pos[i];
		if(vis[u])continue;
		temp[u] = 0;
		while(!vis[par[u]]){
			int now = par[u];
			for(auto v : g[now]){
				if(v == par[now])continue;
				if(v == u)temp[now] *= 1 + temp[v];
				else temp[now] *= 1 + dp[v];
			}
			u = now;
			//dbg(i, u);
		}
		res /= mint(dp[u] + 1);
		//dbg(i, res, u);
		res *= temp[u] + 1;
		ans += res * i;
		//dbg(i, ans, res);
		
		res /= temp[u] + 1;
		u = pos[i];
		for(auto v : g[u]){
			if(v == par[u])continue;
			res *= 1 + dp[v];
		}
		vis[u] = 1;
		while(!vis[par[u]]){
			int now = par[u];
			for(auto v : g[now]){
				if(v == par[now] || v == u)continue;
				res *= 1 + dp[v];
			}
			u = now;
			vis[u] = 1;
		}
		//dbg(i, res);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}