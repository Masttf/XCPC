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
constexpr int mod = 1e9 + 7;
int qmi(int a, int b){
	int res = 1;
	while(b){
		if(b & 1)res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}
struct node{
	int val1 = 0, val2 = 0;
	int tag = 0;
	int mi = 1e18, mx = 0;
};
mt19937 rd(time(0));
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int UP = 4e10;
	int B = 2e5;
	vector<int> p1(B + 1), p2(B + 1);
	vector<int> inv1(B + 1), inv2(B + 1);
	int X = rd();
	while(X >= mod){
		X = rd();
	}
	// dbg(X);
	p1[0] = p2[0] = 1;
	inv1[0] = inv2[0] = 1;
	int t = qmi(X, mod - 2);
	for(int i = 1; i <= B; i++){
		p2[i] = p2[i - 1] * X % mod;
		inv2[i] = inv2[i - 1] * t % mod;
	}
	for(int i = 1; i <= B; i++){
		p1[i] = p1[i - 1] * p2[B] % mod;
		inv1[i] = inv1[i - 1] * inv2[B] % mod;
	}
	vector<node> tr(n * 4);
	auto up = [&](node x, node y) -> node{
		node res;
		res.val1 = (x.val1 + y.val1) % mod;
		res.val2 = (x.val2 + y.val2) % mod;
		res.mi = min(x.mi, y.mi);
		res.mx = max(x.mx, y.mx);
		return res;
	};
	auto cg = [&](int p, int val) -> void{
		tr[p].val1 = tr[p].val1 * p1[val / B] % mod * p2[val % B] % mod;
		tr[p].val2 = tr[p].val2 * inv1[val / B] % mod * inv2[val % B] % mod;
		tr[p].mi += val;
		tr[p].mx += val;
		tr[p].tag += val;
	};
	auto down = [&](int p) -> void{
		if(tr[p].tag){
			cg(p << 1, tr[p].tag);
			cg(p << 1 | 1, tr[p].tag);
			tr[p].tag = 0;
		}
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			tr[p].val1 = p2[a[l]];
			tr[p].val2 = inv2[a[l]];
			tr[p].mi = tr[p].mx = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
	};
	bulid(bulid, 1, n, 1);

	auto update = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			cg(p, val);
			return ;
		}
		down(p);
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> node{
		if(x <= l && r <= y)return tr[p];
		node res;
		down(p);
		int mid = (l + r) >> 1;
		if(x <= mid)res = up(res, self(self, l, mid, x, y, p << 1));
		if(y > mid) res = up(res, self(self, mid + 1, r, x, y, p << 1 | 1));
		return res;
	};
	for(int i = 1; i <= q; i++){
		int ty; cin >> ty;
		if(ty == 1){
			int l, r, val; cin >> l >> r >> val;
			update(update, 1, n, l, r, val, 1);
		}else{
			int l, r; cin >> l >> r;
			node res = query(query, 1, n, l, r, 1);
			int m = res.mi + res.mx;
			int v1 = res.val1;
			// dbg(v1);
			int v2 = res.val2 * p1[m / B] % mod * p2[m % B] % mod;
			if(v1 == v2){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
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