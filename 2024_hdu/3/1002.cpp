#include<bits/stdc++.h>
//#define int long long
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
constexpr long long Max = 1e18;
struct node{
	int l, r;
	long long val, tag;
};
void solve(){
	int n; cin >> n;
	vector<int> c(n + 1), w(n + 1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> root(n + 1);
	vector<long long> dp(n + 1);
	vector<node> tr(n * 40);
	int tot = 0;
	long long sum = 0;
	auto cg = [&](int p, long long val) -> void{
		tr[p].val += val;
		tr[p].tag += val;
	};
	auto down = [&](int p) -> void{
		if(tr[p].tag != 0){
			int ls = tr[p].l;
			int rs = tr[p].r;
			if(ls)cg(ls, tr[p].tag);
			if(rs)cg(rs, tr[p].tag);
			tr[p].tag = 0;
		}
	};
	auto updata = [&](auto self, int l, int r, int x, int val, int &p) -> void{
		if(!p)p = ++tot;
		tr[p].val = val;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, tr[p].l);
		else self(self, mid + 1, r, x, val, tr[p].r);
	};
	auto merge = [&](auto self, int l, int r, int &x, int y, long long &res) -> void{
		if(!x || !y){
			x = x | y;
			return ;
		}
		if(l == r){
			res = max(res, tr[x].val + tr[y].val + sum);
			//dbg(l, tr[x].val, tr[y].val, sum);
			tr[x].val = max(tr[x].val, tr[y].val);
			return ;
		}
		down(x);down(y);
		tr[x].val = max(tr[x].val, tr[y].val);
		int mid = (l + r) >> 1;
		self(self, l, mid, tr[x].l, tr[y].l, res);
		self(self, mid + 1, r, tr[x].r, tr[y].r, res);
		return ;
	};
	auto dfs2 = [&](auto self, int now, int father) -> void{
		sum = 0;
		long long sm = 0;
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
			sm += dp[v];
		}
		sum = sm;
		dp[now] = sum;
		updata(updata, 1, n, c[now], w[now], root[now]);
		for(auto v : g[now]){
			if(v == father)continue;
			cg(root[v], -dp[v]);
			//dbg("merge ",now, v);
			merge(merge, 1, n, root[now], root[v], dp[now]);
		}
		cg(root[now], sm);

	};
	dfs2(dfs2, 1, 0);
	cout << dp[1] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}