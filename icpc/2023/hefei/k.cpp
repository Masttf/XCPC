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
	int l, r, mx, tag;
	int mx2;
};
void solve(){
    int n; cin >> n;
    vector<int> w(n + 1);
    vector<int>p;
    for(int i = 1; i <= n; i++){
    	cin >> w[i];
    	p.push_back(w[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
    	return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> root(n + 1), dp(n + 1);
    int tot = 0;
    int sum = 0;
    vector<node>tr(n * 40);
    tr[0].mx = tr[0].mx2 = -1e18;
    auto cg = [&](int p, int val) -> void{
    	tr[p].mx += val;
    	tr[p].mx2 += val;
    	tr[p].tag += val;
    };
    auto up = [&](int p) -> void{
    	int ls = tr[p].l;
    	int rs = tr[p].r;
    	tr[p].mx = max(tr[ls].mx, tr[rs].mx);
    	tr[p].mx2 = max(tr[ls].mx2, tr[rs].mx2);
    };
    auto down = [&](int p) -> void{
    	if(tr[p].tag){
    		int ls = tr[p].l;
    		int rs = tr[p].r;
    		if(ls)cg(ls, tr[p].tag);
    		if(rs)cg(rs, tr[p].tag);
    		tr[p].tag = 0;
    	}
    };
    auto update = [&](auto self, int l, int r, int x, int val1, int val2, int &u) -> void{
    	if(!u)u = ++tot;
    	if(l == r){
    		tr[u].mx = val1;
    		tr[u].mx2 = val2;
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, val1, val2, tr[u].l);
    	else self(self, mid + 1, r, x, val1, val2, tr[u].r);
    	up(u);
    	return ;
    };
    auto merge = [&](auto self, int l, int r, int &x, int y, int &ans) -> void{
    	if(!x || !y){
    		x = x | y;
    		return ;
    	}
    	if(l == r){
    		ans = max(ans, tr[x].mx + tr[y].mx2 + sum);
    		ans = max(ans, tr[x].mx2 + tr[y].mx + sum);
    		tr[x].mx = max(tr[x].mx, tr[y].mx);
    		tr[x].mx2 = max(tr[x].mx2, tr[y].mx2);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	down(x);down(y);
    	ans = max(ans, tr[tr[y].l].mx + tr[tr[x].r].mx2 + sum);
    	ans = max(ans, tr[tr[x].l].mx + tr[tr[y].r].mx2 + sum);
    	self(self, l, mid, tr[x].l, tr[y].l, ans);
    	self(self, mid + 1, r, tr[x].r, tr[y].r, ans);
    	up(x);
    	return ;
    };
    auto dfs = [&](auto self, int now, int father) -> void{
    	sum = 0;
    	int sm = 0;
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		sm += dp[v];
    	}
    	dp[now] = sm;
    	sum = sm;
    	update(update, 1, n, get(w[now]), w[now], 0ll, root[now]);
    	for(auto v : g[now]){
    		if(v == father)continue;
    		cg(root[v], -dp[v]);
    		merge(merge, 1, n, root[now], root[v], dp[now]);
    	}
    	cg(root[now], sm);
    	return ;
    };
    dfs(dfs, 1, 0);
    cout << dp[1] << '\n';
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