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
	int l, r, val;
};
void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n + 1);
	vector<int>f(n + 1);
	vector<int>root(n + 1);
	vector<node>tr(n * 32);
	int tot = 0;
	vector<int> id(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		id[a[i]] = i;
		f[i] = i;
	}
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	auto updata = [&](auto self, int l, int r, int x, int &p) -> void{
		if(!p)p = ++tot;
		tr[p].val++;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, tr[p].l);
		else self(self, mid + 1, r, x, tr[p].r);
	};
	auto query = [&](auto self, int l, int r, int k, int p) -> int{
		if(l == r)return l;
		int mid = (l + r) >> 1;
		int ls = tr[p].l;
		int rs = tr[p].r;
		int res = tr[ls].val;
		if(res >= k)return self(self, l, mid, k, ls);
		else return self(self, mid + 1, r, k - res, rs);
	};
	auto merge = [&](auto self, int l, int r, int &x, int y) -> void{
		if(!x || !y){
			x = x | y;
			return ;
		}
		if(l == r){
			tr[x].val += tr[y].val;
			return ;
		}
		int mid = (l + r) >> 1;
		tr[x].val += tr[y].val;
		self(self, l, mid, tr[x].l, tr[y].l);
		self(self, mid + 1, r, tr[x].r, tr[y].r);
	};
	auto mg = [&](int a, int b) -> void{
		int fa = find(find, a);
		int fb = find(find, b);
		if(fa == fb)return ;
		f[fa] = fb;
		merge(merge, 1, n, root[fb], root[fa]);
	};
	for(int i = 1; i <= n; i++){
		updata(updata, 1, n, a[i], root[i]);
	}
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		mg(u, v);
	}
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		char t;int x,y;
		cin >> t >> x >> y;
		if(t == 'Q'){
			int fa = find(find, x);
			int rt = root[fa];
			if(tr[rt].val < y)cout << -1 << '\n';
			else cout << id[query(query, 1, n, y, rt)] << '\n';
		}else{
			mg(x, y);
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