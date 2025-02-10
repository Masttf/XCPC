#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
template<const int T>
struct Modint{
	const static int mod = T;
	int x;
	Modint(int x = 0): x(x % mod){}
	int val(){return x;}
	Modint operator + (const Modint &a)const{
		int x0 = x + a.x;
		return Modint(x0 <mod ? x0 :x0-mod);
	}
	Modint operator - (const Modint &a)const{
		int x0 = x - a.x;
		return Modint(x0 < 0 ? x0 + mod : x0);
	}
	Modint operator * (const Modint &a)const{
		return Modint(1ll * x * a.x);
	}
	void operator += (const Modint &a){
		x += a.x;
		if(x >= mod) x -= mod;
	}
	void operator -= (const Modint &a){
		x -= a.x;
		if(x < 0) x += mod;
	}
	void operator *= (const Modint &a){
		x = 1ll * x * a.x % mod;
	}
	friend Modint operator + (int y, const Modint &a){
		int x0 = y + a.x;
		return Modint(x0 <mod ? x0 :x0-mod);
	}
	friend Modint operator - (int y, const Modint &a){
		int x0 = y - a.x;
		return Modint(x0 < 0 ? x0 + mod : x0);
	}
	friend Modint operator * (int y, const Modint &a){
		return Modint(1ll * y * a.x);
	}
	friend ostream &operator<<(ostream &os, const Modint &a){
		return os << a.x;
	}
	friend istream &operator>>(istream &is, Modint &t){
		return is >> t.x;
	}
};
constexpr int mod = 998244353;
using mint = Modint<mod>;
void solve(){
	int n; cin >> n;
	vector<int>a(n + 1);
	vector<int>p;
	p.push_back(0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	for(int i = 1;  i <= n; i++) a[i] = get(a[i]);
	vector<mint>dp1(n + 1);
	vector<mint>dp2(n + 1);
	vector<mint>tr(n * 4);
	auto updata = [&](auto self, int l, int r, int x, mint val, int p) -> void{
		if(l == r){
			tr[p] += val;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, p << 1);
		else self(self, mid + 1, r, x, val, p << 1 | 1);
		tr[p] = (tr[p << 1] + tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> mint{
		if(x <= l && r <= y)return tr[p];
		mint res = 0;
		int mid = (l + r) >> 1;
		if(x <= mid)res += self(self, l, mid, x, y, p << 1);
		if(y > mid)res += self(self, mid + 1, r, x, y, p << 1 | 1);
		return res;
	};
	int sz = p.size();
	for(int i = 1; i <= n; i++){
		dp1[i] = query(query, 1, sz, 1, a[i] - 1, 1) + 1;
		updata(updata, 1, sz, a[i], dp1[i], 1);
		//dbg(i, dp1[i]);
	}
	tr.assign(n * 4, 0);
	for(int i = n; i >= 1; i--){
		dp2[i] = query(query, 1, sz, 1, a[i] - 1, 1) + 1;
		updata(updata, 1, sz, a[i], dp2[i], 1);
		//dbg(i, dp2[i]);
	}
	vector<mint>t(sz + 1);
	auto add = [&](int x, mint val) -> void{
		while(x <= sz){
			t[x] += val;
			x += lowbit(x);
		}
	};
	auto ask = [&](int x) -> mint{
		mint res = 0;
		while(x){
			res += t[x];
			x -= lowbit(x);
		}
		return res;
	};
	for(int i = 1; i <= n; i++){
		add(a[i], dp2[i]);
		//dbg(a[i], ask(a[i]));
	}
	mint ans = 0;
	for(int i = 1; i <= n; i++){
		add(a[i], -1 * dp2[i]);
		//dbg(i, a[i], ask(a[i] - 1));
		mint res = dp1[i] * (ask(a[i] - 1) + 1);
		ans += res;
		//dbg(i, res);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}