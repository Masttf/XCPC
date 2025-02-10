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
	int l, r;
	int cnt;
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> p;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	p.push_back(a[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(int i = 1; i <= n; i++){
    	a[i] = get(a[i]);
    }
    vector g(n + 1, vector<int>());
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    int ans = 0;
    vector<int> root(n + 1);
    vector<node> tr(n * 40);
    int tot = 0;
    auto updata = [&](auto self, int l, int r, int x, int &p) -> void{
		if(!p)p = ++tot;
		tr[p].cnt = 1;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, tr[p].l);
		else self(self, mid + 1, r, x, tr[p].r);
	};
    auto merge = [&](auto self, int l, int r, int x, int y, int f) -> int{
	    if(!x || !y)return x | y;
	    int mid = (l + r) >> 1;
	    int rt = ++tot;
	    if(l == r){
	    	if(l < f)ans += tr[x].cnt * tr[y].cnt;
	        tr[rt].cnt = tr[x].cnt + tr[y].cnt;
	        return rt;
	    }
	    tr[rt].cnt = tr[x].cnt + tr[y].cnt;
	    tr[rt].l = self(self, l, mid, tr[x].l, tr[y].l, f);
	    tr[rt].r = self(self, mid + 1, r, tr[x].r, tr[y].r, f);
	    return rt;
	};
	auto run = [&](auto self, int l, int r, int x, int y, int f) -> void{
	   	if(tr[x].cnt - tr[y].cnt == 0)return ;
	   	if(tr[y].cnt == 0)return ;
	    int mid = (l + r) >> 1;
	    if(l == r){
	    	int d = tr[x].cnt - tr[y].cnt;
	    	// dbg(l, r, d, tr[y].cnt);
	    	if(l < f)ans += d * tr[y].cnt;
	    	return ;
	    }
	    self(self, l, mid, tr[x].l, tr[y].l, f);
	    self(self, mid + 1, r, tr[x].r, tr[y].r, f);
	    return ;
	};
    auto dfs = [&](auto self, int now, int father) -> void{
    	updata(updata, 1, n, a[now], root[now]);
	    for(auto v : g[now]){
	        if(v == father)continue;
	        self(self, v, now);
	        root[now] = merge(merge, 1, n, root[now], root[v], a[now]);
	    }
	};
	dfs(dfs, 1, 0);
	// dbg(ans);
	auto dfs2 = [&](auto self, int now, int father) -> void{
		for(auto v : g[now]){
			if(v == father)continue;
			// dbg(now, v);
			run(run, 1, n, root[1], root[v], a[v]);
			// dbg(now, v, ans);
			self(self, v, now);
		}
	};
	dfs2(dfs2, 1, 0);
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
枚举 lca z
然后算w相同的对数
还要换根

直接线段树合并秒了

*/