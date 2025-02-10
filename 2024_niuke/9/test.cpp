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
struct node{
	int val, r_val, tag;
};
void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	s = ' ' + s;
	vector<int>p(n + 1);
	vector p26(30, vector<int>(n + 1));
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * 131;
		for(int j = 1; j <= 26; j++){
			p26[j][i] = p26[j][i - 1] * 131 + j;
		}
	}
	vector<node>tr(n * 4);
	auto cg = [&](node &x, int val, int len) -> void{
		x.val = x.r_val = p26[val][len];
		x.tag = val;
	};
	auto down = [&](int p, int l, int r) -> void{
		if(tr[p].tag){
			int mid = (l + r) >> 1;
			cg(tr[p << 1], tr[p].tag, mid - l + 1);
			cg(tr[p << 1 | 1], tr[p].tag, r - mid);
			tr[p].tag = 0;
		}
	};
	auto up = [&](node x, node y, int len1, int len2) -> node{
		node res = {0, 0, 0};
		res.val = x.val * p[len2] + y.val;
		res.r_val = x.r_val + y.r_val * p[len1];
		return res;
	};
	auto bulid = [&](auto self, int l, int r, int p) -> void{
		if(l == r){
			cg(tr[p], s[l] - 'a' + 1, 1);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1], mid - l + 1, r - mid);
		//dbg(l, r, tr[p].val, tr[p].r_val);
	};
	bulid(bulid, 1, n, 1);
	//dbg("yes");
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			cg(tr[p], val, r - l + 1);
			return ;
		}
		down(p, l, r);
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
		tr[p] = up(tr[p << 1], tr[p << 1 | 1], mid - l + 1, r - mid);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> node{
		if(x <= l && r <= y)return tr[p];
		down(p, l, r);
		node res = {0, 0, 0};
		int mid = (l + r) >> 1;
		if(x <= mid)res = self(self, l, mid, x, y, p << 1);
		if(y > mid){
			node temp = self(self,mid + 1, r, x, y, p << 1 | 1);
			if(x <= mid){
				res=up(res, temp, mid - max(x, l) + 1, min(r, y) - mid);
			}else res=temp;
		}
		//dbg(l, r, res.val, res.r_val);
		return res;
	};
	vector<int>min_div(n + 1);
	vector<int>prim;
	vector<bool>vis(n + 1);
	for(int i = 2; i <= n; i++){
		if(!vis[i])prim.push_back(i), min_div[i] = i;
		for(int j = 0; prim[j] * i <= n; j++){
			vis[i * prim[j]] = 1;
			min_div[i * prim[j]] = prim[j];
			if(i % prim[j] == 0)break;

		}
	}
	auto get = [&](int l, int r, int ty) -> int{
		auto check = [&](int len) -> bool{
			if(len == r - l + 1)return true;
			int l1 = l, r1 = r - len;
			int l2 = l + len, r2 = r;
			node res1 = query(query, 1, n, l1, r1, 1);
			node res2 = query(query, 1, n, l2, r2, 1);
			if(ty == 1){
				return res1.val == res2.val;
			}else{
				return res1.r_val == res2.r_val;
			}
		};

		int ans = r - l + 1;
		int len = r - l + 1;
		while(len > 1){
			int v = ans / min_div[len];
			if(check(v)){
				ans = v;
			}
			len /= min_div[len];
		}
		if(check(1))ans = 1;
		return ans;
	};
	
	for(int i = 1; i <= m; i++){
		int op, l, r; cin >> op >> l >> r;
		if(op == 0){
			char c; cin >> c;
			updata(updata, 1, n, l, r, c - 'a' + 1, 1);
		}else{
			cout << get(l, r, op) << '\n';
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