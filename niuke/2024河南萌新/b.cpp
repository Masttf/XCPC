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
	vector<vector<pair<int,int>>>g(n + 1);
	int mx = 1e5;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		//mx = max(mx, w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<int>dfn(n + 1), low(n + 1);
	vector<int>bl(n + 1), sz(n + 1);
	vector<int>stk;
	int cnt = 0;
	int num = 0;
	auto tarjan = [&](auto self ,int now, int father) -> void{
		dfn[now] = low[now] = ++num;
		stk.push_back(now);
		for(auto [v, w] : g[now]){
			if(v == father)continue;
			if(!dfn[v]){
				self(self, v, now);
				low[now] = min(low[now], low[v]);
			}else if(!bl[v]) low[now] = min(low[now], dfn[v]);
		}
		if(dfn[now] == low[now]){
			int y;
			cnt++;
			do{
				y = stk.back();
				stk.pop_back();
				sz[cnt]++;
				bl[y] = cnt;
			}while(y != now);
		}
	};
	tarjan(tarjan, 1, 0);
	vector edge(mx + 1, vector<pair<int, int>>());
	for(int i = 1; i <= n; i++){
		for(auto [v, w] : g[i]){
			int fa = bl[i];
			int fb = bl[v];
			if(fa == fb)continue;
			edge[w].push_back({fa, fb});
		}
	}
	vector<int>f(n + 1);
	vector<int>root(n + 1);
	vector<node>tr(n * 32);
	int tot = 0;
	for(int i = 1; i <= n; i++)f[i] = i;

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
		updata(updata, 1, n, sz[i], root[i]);
	}
	//dbg("yes");
	// for(int i = 1; i <= n; i++){
	// 	dbg(i, bl[i]);
	// }
	int q; cin >> q;
	vector res(mx + 1, vector<array<int, 3>>());
	for(int i = 0; i < q; i++){
		int u, x, k;
		cin >> u >> x >> k;
		res[x].push_back({bl[u], k, i});
	}
	vector<int>ans(q);
	for(int i = 1; i <= mx; i++){
		for(auto [a, b] : edge[i]){
			//dbg(i, a, b, find(find, a), find(find, b));
			mg(a, b);
			//dbg(find(find,a), find(find, b));
		}
		for(auto [u, k, id] : res[i]){
			int fa = find(find, u);
			int rt = root[fa];
			//dbg(u, id, fa, rt);
			if(tr[rt].val < k)ans[id] = -1;
			else ans[id] = query(query, 1, n, k, rt);
		}
	}
	for(auto x : ans)cout << x << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}