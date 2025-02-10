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
	//ModInt(long long x) : x(int(x % mod)) {} 
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
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n);
    int K; cin >> K;
    vector<pair<int, int>> L(n + 1);
    vector<int>op;
    op.push_back(0);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	u--; v--;
    	op.push_back(u);
    	op.push_back(v);
    	g[u].push_back(v);
    }
    sort(op.begin(), op.end());
    op.erase(unique(op.begin(), op.end()), op.end());
    int tot = 0;
    vector<int> id(n + 1), bl(n + 1);
    int sz = op.size();
    vector<vector<int>>G(n + 1);
    for(int i = 0; i < sz; i++){
    	id[op[i]] = ++tot;
    	bl[tot] = op[i];
    	L[tot] = {op[i], op[i]};
    	int s = (op[i] + 1) % n;
    	int nex = (op[(i + 1) % sz] - 1 + n) % n;
    	if(nex == op[i])continue;
    	id[s] = ++tot;
    	bl[tot] = s;
    	L[tot] = {s, nex};
    }
    for(int i = 1; i <= tot; i++){
    	int now = bl[i];
    	for(auto v : g[now]){
    		v = id[v];
    		G[id[now]].push_back(v);
    	}
    }
    vector dp(tot + 1, vector<mint>(K + 1));
    for(int i = 1; i <= tot; i++){
    	dp[i][0] = 1;
    }
    for(int i = 1; i <= K; i++){
    	for(int j = 1; j <= tot; j++){
    		auto [l, r] = L[j];
    		if(l == r){
    			dp[j][i] += dp[id[(r + 1) % n]][i - 1];
    			for(auto v : G[j]){
    				dp[j][i] += dp[v][i - 1];
    			}
    		}else{
    			int len = r - l + 1;
    			if(i > len){
    				dp[j][i] = dp[id[(r + 1) % n]][i - len];
    			}else dp[j][i] = 1;
    		}
    		
    	}
    }
    cout << dp[id[0]][K] << '\n';
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