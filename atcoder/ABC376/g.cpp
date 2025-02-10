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
struct cmp{
    bool operator() (const array<int, 3> &x, const array<int, 3> &y)const {
        if(x[2] == y[2])return false;
        if(x[0] * y[1] != y[0] * x[1]){
    		return x[1] * y[0] < x[0] * y[1];
    	}else return x[2] < y[2];
    }
};
void solve(){
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> a(n + 1);
	mint inv = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	inv += a[i];
    }
    vector<int> f(n + 1);
    vector<pair<int, int>> val(n + 1, {0, 1});
    for(int i = 1; i <= n; i++){
    	f[i] = i;
    	val[i].first = a[i];
    } 
    auto find = [&](auto self, int x) -> int{
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    set<array<int, 3>, cmp>s;
    mint ans = 0;
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	if(fa == fb)return ;
    	s.erase({val[fa].first, val[fa].second, fa});
    	s.erase({val[fb].first, val[fb].second, fb});
    	ans += val[fb].second * val[fa].first;
    	f[fa] = fb;
    	val[fb].first += val[fa].first;
    	val[fb].second += val[fa].second;
    	if(fb)s.insert({val[fb].first, val[fb].second, fb});
    };
    for(int i = 1; i <= n; i++){
    	s.insert({val[i].first, val[i].second, i});
    }
    while(!s.empty()){
    	int now = (*s.begin())[2];
    	merge(now, find(find, p[now]));
    }
    ans = ans * inv.inv();
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