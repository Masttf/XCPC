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
struct node{
	mint val, sum;
	int tag;
};
void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n + 1);
	vector<int>s(m + 1);
	vector<vector<int>>pos(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= m; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		pos[a[i]].push_back(i);
	}
	vector op(n + 2,vector<array<int, 3>>());
	for(int i = 1; i <= n; i++){
		if(pos[i].empty())continue;
		int sz = pos[i].size();
		for(int j = 0; j < sz; j++){
			int now = pos[i][j];
			int nex = n + 1;
			if(j != sz -1)nex = pos[i][j + 1];
			for(int k = 1; k <= m; k++){
				int lim = s[k];
				if(j + 1 >= lim){
					int p = pos[i][j - lim + 1];
					int pp = 1;
					if(j - lim >= 0)pp = pos[i][j - lim] + 1;
					op[now].push_back({pp, p, 1});
					op[nex].push_back({pp, p, -1});
				}
			}
		}
	}

	vector<node>tr(n * 4);
	auto up = [&](int p, int l, int r) -> void{
		if(tr[p].tag){
			tr[p].val = 0;
		}else{
			if(l == r)tr[p].val = tr[p].sum;
			else tr[p].val = tr[p << 1].val + tr[p << 1 |1].val;
		}
	};
	auto add = [&](auto self, int l, int r, int x, mint val, int p) -> void{
		if(l == r){
			tr[p].sum += val;
			up(p, l, r);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, p << 1);
		else self(self, mid + 1, r, x, val, p << 1 | 1);
		tr[p].sum += tr[p << 1].sum + tr[p << 1 | 1].sum;
		up(p, l, r);
	};
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].tag += val;
			up(p, l, r);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		up(p, l, r);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> mint{
		if(x <= l && r <= y)return tr[p].val;
		mint res = 0;
		int mid = (l + r) >> 1;
		if(x <= mid)res += self(self, l, mid, x, y, p << 1);
		if(y > mid)res += self(self, mid + 1, r, x, y, p << 1 | 1);
		return res;
	};
	vector<mint> dp(n + 1);
	dp[0] = 1;
	add(add, 0, n, 0, 1, 1);
	for(int i = 1; i <= n; i++){
		for(auto [l, r, val] : op[i]){
			updata(updata, 0, n, l - 1, r - 1, val, 1);
		}
		dp[i] = query(query, 0, n, 0, i, 1);
		add(add, 0, n, i, dp[i], 1);
	}
	cout << dp[n] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}