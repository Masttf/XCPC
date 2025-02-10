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
struct node{
	int lson, rson;
	int sum, tag;
	int cnt;
};
void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> root(n + 1);
	vector<node> tr(n * 40);
	int tot = 0;
	auto cg = [&](int p, int val) -> void{
		tr[p].sum += val * tr[p].cnt;
		tr[p].tag += val;
	};
	auto down = [&](int p) -> void{
		if(!tr[p].tag)return ;
		int ls = tr[p].lson;
		int rs = tr[p].rson;
		if(ls)cg(ls, tr[p].tag);
		if(rs)cg(rs, tr[p].tag);
		tr[p].tag = 0;
	};
	auto update = [&](auto self, int l, int r, int x, int &p) -> void{
		if(!p) p = ++tot;
		tr[p].sum = 0;
		tr[p].cnt = 1;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid) self(self, l, mid, x, tr[p].lson);
		else self(self, mid + 1, r, x, tr[p].rson);
		return ;
	};
	int ans = 0;
	auto merge = [&](auto self, int l, int r, int &x, int y) -> void{
		if(!x || !y){
			x = x | y;
			return ;
		}
		if(l == r){
			int v1 = tr[y].sum * tr[x].cnt + tr[x].sum * tr[y].cnt;
			ans += v1;
			tr[x].sum += tr[y].sum;
			tr[x].cnt += tr[y].cnt;
			return ;
		}
		int mid = (l + r) >> 1;
		down(x);down(y);
		tr[x].sum += tr[y].sum;
		tr[x].cnt += tr[y].cnt;
		self(self, l, mid, tr[x].lson, tr[y].lson);
		self(self, mid + 1, r, tr[x].rson, tr[y].rson);
	};
	auto dfs = [&](auto self, int now, int father) -> void{

		update(update, 1, n, a[now], root[now]);
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
			cg(root[v], 1);
			merge(merge, 1, n, root[now], root[v]);
		}
		// dbg(now, ans);
	};
	dfs(dfs, 1, 0);
	cout << ans << '\n';
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
/*

*/