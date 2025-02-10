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
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;
using mint =ModInt<mod>;
vector<int>prim;
vector<mint>sump(1);
vector<int>vis(maxn);
void init(int n){
	vis[1] = 1;
	for(int i = 2; i <= n; i++){
		if(!vis[i]){
			prim.push_back(i);
			sump.push_back(sump.back() + i);
		}
		for(int j = 0; prim[j] * i <= n; j++){
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0)break;
		}
	}
}
void solve(){
    int n; cin >> n;
    int B = sqrt(n);
    init(B);
    vector<int>id1(B + 1), id2(B + 1);
    vector<int>w(2 * B + 1);
    vector<mint>g(2 * B + 1), h(2 * B + 1);
    int tot = 0;
    for(int i = 1, j; i <= n; i = j + 1){
    	j = n / (n / i);
    	w[++tot] = n / i;
    	h[tot] = mint(w[tot] - 1);
    	g[tot] = mint(w[tot]) * (w[tot] + 1) * mint(2).inv() - 1;
    	if(w[tot] <= B)id1[w[tot]] = tot;
    	else id2[j] = tot;
    }
    int sz = prim.size();
    for(int i = 0; i < sz; i++){
    	for(int j = 1; j <= tot; j++){
    		if(prim[i] * prim[i] > w[j])break;
    		int k = w[j] / prim[i];
    		if(k <= B) k = id1[k];
    		else k = id2[n / k];
    		h[j] -= h[k] - i;
    		g[j] -= prim[i] * (g[k] - sump[i]);
    	}
    }
    auto Min_25 = [&](auto self, int x, int y) -> mint{
	    if(x <= 1)return 0;
	    int k = x;
	    if(k <= B) k = id1[k];
	    else k = id2[n / k];
	    mint ret = g[k] - sump[y] - h[k] + y;//计算质数的贡献
	    if(y == 0)ret += 2;
	    for(int i = y; i < sz; i++){
	        if(prim[i] * prim[i] > x)break;
	        int t1 = prim[i];
	        int t2 = prim[i] * prim[i];
	        for(int e = 1; t2 <= x; e++){
	            //计算合数的贡献
	            ret += self(self, x / t1, i + 1) * (prim[i] ^ e) + (prim[i] ^ (e + 1));
	            t1 = t2;
	            t2 *= prim[i];
	        }
	    }
	    return ret;
	};
	cout << Min_25(Min_25, n, 0)  + 1 << '\n';
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