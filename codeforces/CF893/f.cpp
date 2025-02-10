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
constexpr int Max = 1e18;
struct node{
	int lson, rson;
	int val;
};
void solve(){
    int n, rt; cin >> n >> rt;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
   	vector<vector<int>> g(n + 1);
  	for(int i = 1; i < n; i++){
  		int u, v; cin >> u >> v;
  		g[u].push_back(v);
  		g[v].push_back(u);
  	}
  	vector<node>tr(n * 40);
  	tr[0].val = Max;
  	int tot = 0;
  	vector<int> root(n + 1);
  	auto update = [&](auto self, int l, int r, int x, int val, int &p) -> void{
  		p = ++tot;
  		tr[p].val = val;
  		if(l == r)return ;
  		int mid = (l + r) >> 1;
  		if(x <= mid)self(self, l, mid, x, val, tr[p].lson);
  		else self(self, mid + 1, r, x, val, tr[p].rson);
  	};
  	auto merge = [&](auto self, int l, int r, int x, int y) -> int{
  		if(!x || !y)return x | y;
  		int p = ++tot;
  		tr[p].val = min(tr[x].val, tr[y].val);
  		if(l == r)return p;
  		int mid = (l + r) >> 1;
  		tr[p].lson = self(self, l, mid, tr[x].lson, tr[y].lson);
  		tr[p].rson = self(self, mid + 1, r, tr[x].rson, tr[y].rson);
  		return p;
  	};
  	auto query = [&](auto self, int l, int r, int x, int y, int p) -> int{
  		if(!p)return Max;
  		if(x <= l && r <= y)return tr[p].val;
  		int res = Max;
  		int mid = (l + r) >> 1;
  		if(x <= mid)res = min(res, self(self, l, mid, x, y, tr[p].lson));
  		if(y > mid)res = min(res, self(self, mid + 1, r, x, y, tr[p].rson));
  		return res;
  	};
  	vector<int> dep(n + 1);
  	auto dfs = [&](auto self, int now, int father) -> void{
  		dep[now] = dep[father] + 1;
  		update(update, 1, n, dep[now], a[now], root[now]);
  		for(auto v : g[now]){
  			if(v == father)continue;
  			self(self, v, now);
  			root[now] = merge(merge, 1, n, root[now], root[v]);
  		}
  	};
  	dfs(dfs, rt, 0);
  	int q; cin >> q;
  	int last = 0;
  	for(int i = 1; i <= q; i++){
  		int x, k; cin >> x >> k;
  		x = (x + last) % n + 1;
  		k = (k + last) % n;
  		last = query(query, 1, n, dep[x], min(n, dep[x] + k), root[x]);
  		cout << last << '\n';
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