#include<bits/stdc++.h>
//#define int long long
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
	ModInt(long long x) : x(int(x % mod)) {} 
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
using mint = ModInt<mod>;
constexpr int maxn = 2e3 + 5;
mint f[maxn], inv[maxn];
void init(){
	f[0] = inv[0] = 1;
	for(int i = 1; i < maxn; i++){
		f[i] = f[i-1] * i;
		inv[i] = f[i].inv();
	}
}
mint C(int n, int m){
	if(m > n || n < 0)return 0;
	return f[n] * inv[m] * inv[n-m];
}
void solve(){
	int n; cin >> n;
	vector<array<int, 4>> a(n + 1);
	vector<int> px;
	vector<int> py;
	for(int i = 1; i <= n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i] = {x1, y1, x2, y2};
		px.push_back(x1);
		px.push_back(x2);
		py.push_back(y1);
		py.push_back(y2);
	}
	sort(px.begin(), px.end());
	px.erase(unique(px.begin(), px.end()), px.end());
	sort(py.begin(), py.end());
	py.erase(unique(py.begin(), py.end()), py.end());
	auto getx = [&](int x) -> int{
		return lower_bound(px.begin(), px.end(), x) - px.begin() + 1;
	};
	auto gety = [&](int x) -> int{
		return lower_bound(py.begin(), py.end(), x) - py.begin() + 1;
	};
	int N = px.size();
	int M = py.size();
	//dbg(N, M);
	vector pre(N + 1, vector<int>(M + 1));
	for(int i = 1; i<= n; i++){
		auto [x1, y1, x2, y2] = a[i];
		x1 = getx(x1);
		y1 = gety(y1);
		x2 = getx(x2) - 1;
		y2 = gety(y2) - 1;
		//dbg(i, x1, x2, y1, y2);
		pre[x2 + 1][y2 + 1] += 1;
		pre[x1][y1] += 1;
		pre[x2 + 1][y1] -= 1;
		pre[x1][y2 + 1] -= 1;
	}
	vector<mint> tot(n + 1);
	for(int i = 1; i < N ; i++){
		for(int j = 1; j < M ; j++){
			pre[i][j] += pre[i-1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			if(pre[i][j] != 0){
				tot[pre[i][j]] += 1ll * (px[i] - px[i - 1]) * (py[j] - py[j - 1]);
			}
		}
	}
	
	// for(int i = 1; i <= n; i++){
	// 	dbg(i, tot[i]);
	// }

	for(int k = 1; k <= n; k++){
		mint ans = 0;
		for(int i = 1; i <= n; i++){
			if(n - i < k)ans += tot[i];
			else ans += (1 - C(n - i, k) / C(n, k)) * tot[i]; 
		}
		cout << ans << '\n';
	}
 	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}