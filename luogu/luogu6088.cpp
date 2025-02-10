#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<string> bian(n);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	string s; cin >> s;
    	bian[i] = s;
    	g[u].push_back({v, i});
    	g[v].push_back({u, i});
    }
    vector<int> bl(n + 1);
    vector<int>dfn(n + 1), dep(n + 1);
    vector<int>L(n + 1), R(n + 1);
	vector st(21, vector<pair<int, int>>(n + 1));
	int tot = 0, num = 0;
	auto dfs = [&](auto self, int now, int father) -> void{
		dfn[now] = ++tot;
		L[now] = ++num;
		dep[now] = dep[father] + 1;
		st[0][tot] = {dep[now], father};
		for(auto [v, id] : g[now]){
			if(v == father)continue;
			bl[v] = id;
			self(self, v, now);
		}
		R[now] = ++num;
	};
	dfs(dfs, 1, 0);
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1ll << k) <= n + 1; i++){
			st[k][i] = min(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
		}
	}
	auto lca = [&](int a, int b) -> int{
		if(a == b)return a;
		if(dfn[a] > dfn[b])swap(a, b);
		int l = dfn[a] + 1;
		int r = dfn[b];
		int len = (r - l + 1);
		int d = __lg(len);
		return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
	};

	vector<int> root(2 * n + 1);
	tot = 0;
	vector<array<int, 26>> tr(n * 20);
	vector<int>cnt(n * 20);
	auto insert = [&](int u, int v, string x, int val) -> void{
		for(auto i : x){
			tr[u] = tr[v];
			int d = i - 'a';
			tr[u][d] = ++tot;
			u = tr[u][d];
			v = tr[v][d];
			cnt[u] = cnt[v] + val;
		}
	};

	auto query = [&](int u, int v, string x) -> int{
		for(auto i : x){
			int d = i - 'a';
			u = tr[u][d];
			v = tr[v][d];
		}
		assert(cnt[u] >= cnt[v]);
		return cnt[u] - cnt[v];
	};

	vector<pair<int, int>> op(2 * n + 1);
	for(int i = 2; i <= n; i++){
		op[L[i]] = {bl[i], 1};
		op[R[i]] = {bl[i], -1};
	}

	for(int i = 1; i <= 2 * n; i++){
		auto [id, val] = op[i];
		root[i] = ++tot;
		insert(root[i], root[i - 1], bian[id], val);
	}

	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int u, v; cin >> u >> v;
		if(dep[u] < dep[v])swap(u, v);
		string s; cin >> s;
		int fa = lca(u, v);
		if(fa == v){
			cout << query(root[L[u]], root[L[fa]], s) << '\n';
		}else{
			int ans = query(root[L[u]], root[L[fa]], s);
			ans += query(root[L[v]], root[L[fa]], s);
			cout << ans << '\n';
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