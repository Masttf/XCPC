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
constexpr int Max = 1e18;
struct node{
	int lval, rval, tag, f1, f2, f3, f4;
};
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	vector<node>tr(n * 4);
	auto up = [&](node x, node y) -> node{
		node res = {0, 0, 0, 0, 0, 0, 0};
		res.lval = x.lval;
		res.rval = y.rval;
		if(x.f1 && y.f1){
			if(res.lval == res.rval){
				res.f1 = 1;
			}
		}
		if(x.f2 && y.f3){
			if(x.lval != x.rval && y.lval != y.rval)res.f4 = 1;
			else if(x.lval == x.rval && y.lval != y.rval){
				if(x.rval < y.lval)res.f4 = 1;
			}else if(x.lval != x.rval && y.lval == y.rval){
				if(x.rval > y.lval)res.f4 = 1;
			}

		}
		if(x.f4 && y.f3){
			if(x.rval > y.lval)res.f4 = 1;
		}
		if(y.f4 && x.f2){
			if(x.rval < y.lval)res.f4 = 1;
		}
		if(x.f2 && y.f2){
			if(x.rval < y.lval){
				res.f2 = 1;
			}
		}
		if(x.f3 && y.f3){
			if(x.rval > y.lval){
				res.f3 = 1;
			}
		}
		return res;
	};
	auto cg = [&](node &x, int val) -> void{
		x.lval += val;
		x.rval += val;
		x.tag += val;
	};
	auto down = [&](int p) -> void{
		if(tr[p].tag){
			cg(tr[p << 1], tr[p].tag);
			cg(tr[p << 1 | 1], tr[p].tag);
			tr[p].tag = 0;
		}
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			tr[p].lval = tr[p].rval = a[l];
			tr[p].f1 = tr[p].f2 = tr[p].f3 = 1;
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
		// dbg(l, r, tr[p].lval, tr[p].rval);
		// dbg(tr[p].f1, tr[p].f2, tr[p].f3, tr[p].f4);
	};
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r<= y){
			cg(tr[p],val);
			return ;
		}
		down(p);
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> node{
		if(x <= l && r <= y){
			return tr[p];
		}
		down(p);
		int mid = (l + r) >> 1;
		node res = {Max, Max, 0, 0, 0, 0, 0};
		if(x <= mid)res = self(self, l, mid, x, y, p << 1);
		if(y > mid){
			node temp = self(self, mid + 1, r, x, y, p << 1 | 1);
			if(res.lval == Max)res = temp;
			else{
				res = up(res, temp);
			}
		}
		return res;
	};
	bulid(bulid, 1, n, 1);
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int t;cin >>t;
		if(t == 1){
			int l, r, val;cin >> l >> r >> val;
			updata(updata, 1, n, l, r, val, 1);
		}else{
			int l, r; cin >> l >> r;
			node res = query(query, 1, n, l, r, 1);
			if(t == 2)cout << res.f1 << '\n';
			else if(t == 3)cout << res.f2 << '\n';
			else if(t == 4)cout << res.f3 << '\n';
			else cout << res.f4 << '\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}