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
constexpr int mod = 1e9 + 7;
using mint =ModInt<mod>;
struct Manacher{
	string res;
	vector<int> p;
	Manacher(string s){
		res = "^";
		for(auto x : s){
			res += '#';
			res += x;
		}
		res += "#&";
		p.resize(res.size() + 1);
		// s = abc idx 0 1 2
		// res = ^#a#b#c#& idx 2 4 6
		// s_idx -> res_idx * 2 + 2
	}
	pair<int, int> get(){
		int len = res.size();
		int c = 0, r = 0;
		int max_len = 0;
		int start = -1;
		for(int i = 1; i < len; i++){
			if(i <= r){
				p[i] = min(p[2 * c - i], r - i);
			}
			while(res[i - p[i] - 1] == res[i + p[i] + 1])p[i]++;
			if(i + p[i] > r){
				c = i;
				r = i + p[i];
			}
			if(p[i] > max_len){
				max_len = p[i];
				start = (i - p[i]) / 2;
			}
			// (i - p[i]) / 2是回文起始点,字符串下标从0开始
			// s_li = (i - p[i] + 1) / 2 - 1
			// s_ri = (i + p[i]) / 2 - 1
		}
		return {start, max_len};
	}
	bool check(int l, int r){
		int len = (r - l + 1);
		int center = (l + r) / 2;
		center = center * 2 + 2;
		if(len % 2 == 0)center++;
		return p[center] >= len;
	}
};
void solve(){
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	vector nex(30, vector<int>(n + 5));
	vector last(30, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++){
			last[j][i] = last[j][i - 1];
		}
		last[a[i] - 'a'][i] = i;
	}
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < 26; j++){
			nex[j][i] = nex[j][i + 1];
		}
		nex[a[i] - 'a'][i] = i;
	}
	int l = 1;
	for(int i = 1; i <= m; i++){
		if(!nex[b[i] - 'a'][l]){
			l = -1;
			break;
		}
		l = nex[b[i] - 'a'][l];
		l++;
	}
	int r = n;
	for(int i = 1; i <= m; i++){
		if(!last[b[i] - 'a'][r]){
			r = -1;
			break;
		}
		r = last[b[i] - 'a'][r];
		r--;
	}
	if(l == -1 || r == -1 || n < m){
		cout << 0 << '\n';
		return ;
	}
	vector<mint>dp(n + 1);
	for(int i = 0; i < 26; i++){
		dp[nex[i][l]] = 1;
	}
	for(int i = l; i <= r; i++){
		for(int j = 0; j < 26; j++){
			if(j == a[i] - 'a'){
				dp[nex[j][i + 1]] += dp[i];
			}else dp[nex[j][i]] += dp[i];
		}
	}
	mint ans = 0;
	Manacher res(b);
	res.get();
	for(int i = l; i <= r; i++)ans += dp[i];
	int rr = n;
	int lim = 0;
	for(int i = 1; i <= m; i++){
		if(last[b[i] - 'a'][rr] < l){
			break;
		}
		rr = last[b[i] - 'a'][rr];
		rr--;
		lim++;
	}
	if(lim == m)ans += 1;
	for(int i = 0; i <= min(lim, m - 1); i++){
		if(res.check(i + 1, m))ans += 1;
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}