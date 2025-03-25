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
	//ModInt(long long x) : x(int(x < 0 ? x % mod + mod : x % mod)) {} 
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
struct node{
	mint first, second;
	node() : first(1), second(0) {}
	node(mint _first, mint _second) : first(_first), second(_second) {}
};
void solve(){
    int n, q; cin >> n >> q;
    vector<int> k(n + 1), b(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> k[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	vector<vector<node>> st(32, vector<node>(n + 1));
	vector<vector<int>> to(32, vector<int>(n + 1));
	auto add = [&](node x, node y) -> node{
		node res = x;
		res.first = x.first * y.first;
		res.second = x.second * y.first + y.second;
		return res;
	};
	for(int i = 1; i <= n; i++){
		st[0][i] = {k[i], b[i]};
		to[0][i] = p[i];
	}
	for(int i = 1; i <= 31; i++){
		for(int j = 1; j <= n; j++){
			st[j][i] = add(st[j - 1][i], st[j - 1][to[j - 1][i]]);
		}
	}
	for(int i = 1; i <= q; i++){
		int x, l, y; cin >> x >> l >> y;
		node res = {1, 0};
		for(int j = 0; j <= 31; j++){
			if(l >> j & 1){
				res = add(res, st[j][x]);
				x = to[j][x];
			}
		}
		mint ans = y * res.first + res.second;
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
/*
1
5 5
2 3 1 2 4
3 4 2 1 2
2 3 5 1 4
1 2 4
2 4 5
3 3 4
4 5 2
5 2 1
*/