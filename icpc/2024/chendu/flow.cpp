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
struct VirtualTree{
	static constexpr int k = 20;
	int n;
	vector<int> dep, dfn, val, cnt;
	vector<vector<int>> g;
	vector<vector<pair<int, int>>> st;
	VirtualTree(vector<vector<int>> &t){
		n = t.size() - 1;
		dfn.assign(n + 1, 0);
		val.assign(n + 1, 0);
		cnt.assign(n + 1, 0);
		dep.assign(n + 1, 0);
		g.assign(n + 1, {});
		st.assign(k + 1, vector<pair<int, int>>(n + 1));
		int tot = 0;
		auto dfs = [&](auto self, int now, int father) -> void{
			dfn[now] = ++tot;
			dep[now] = dep[father] + 1;
			st[0][tot] = {dep[now], father};
			for(auto v : t[now]){
				if(v == father)continue;
				self(self, v, now);
			}
		};
		dfs(dfs, 1, 0);
		for(int k = 1; k <= 20; k++){
			for(int i = 1; i + (1ll << k) <= n + 1; i++){
				st[k][i] = min(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
			}
		}
	}
	int lca(int a, int b){
		if(a == b)return a;
		if(dfn[a] > dfn[b])swap(a, b);
		int l = dfn[a] + 1;
		int r = dfn[b];
		int len = (r - l + 1);
		int d = __lg(len);
		return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
	}
    int build(vector<int> &c){
      auto v = c;
      sort(v.begin(), v.end(), [&](int x, int y) -> bool{
        return dfn[x] < dfn[y];
      });
      int sz = v.size();
      for(int i = 1; i < sz; i++){
      	v.push_back(lca(v[i-1], v[i]));
      }
      sort(v.begin(), v.end(), [&](int x, int y) -> bool{
        return dfn[x] < dfn[y];
      });
      v.erase(unique(v.begin(), v.end()), v.end());
      sz = v.size();
      // 建立虚树
      for(int i = 1; i < sz; i++){
      	g[lca(v[i-1], v[i])].push_back(v[i]);
      }
      // 跑贡献
      int ans = 0;
      for(auto x : c)cnt[x] = 1;
      auto dfs = [&](auto self, int now) -> void{
        for(auto x : g[now]){
        	self(self, x);
        	val[x] += cnt[x] * (dep[x] - dep[now]);
        	ans += val[now] * cnt[x] + val[x] * cnt[now];
        	val[now] += val[x];
        	cnt[now] += cnt[x];
        }
      };
      dfs(dfs, v[0]);
      // 记得清空
      for(auto x : v){
      	vector<int>().swap(g[x]);
      	val[x] = 0;
      	cnt[x] = 0;
      }
      return ans;
    }
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
    VirtualTree tr(g);
	vector<vector<int>> c(n + 1);
	for(int i = 1; i <= n; i++){
		c[a[i]].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(c[i].size() > 1){
			ans += tr.build(c[i]);
		}
	}
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