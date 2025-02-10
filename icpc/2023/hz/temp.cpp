#include <bits/stdc++.h>
using namespace std;
#define int long long

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

const int maxn = 5e5 + 5;
struct node {
	int v,w;
};
vector<node>t[maxn];
int a[maxn],to[maxn],dep[maxn],fa[maxn][35];

void dfs(int u,int f) {
	for (auto i : t[u]) {
		if (i.v == f) continue;
		dep[i.v] = dep[u] + i.w;
		fa[i.v][0] = u;
		for (int j = 1;j <= 20;j++) fa[i.v][j] = fa[fa[i.v][j - 1]][j - 1];
		dfs(i.v,u);
	}
}

int lca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 20;i >= 0;i--) {
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	}
	if (u == v) return u;
	for (int i = 20;i >= 0;i--) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

int zj1[maxn],zj2[maxn];

bool check(int mid,int x,int k) {
	int lca1 = lca(x,zj1[mid]);
	int lca2 = lca(x,zj2[mid]);
	int now1 = dep[x] + dep[zj1[mid]] - 2 * dep[lca1];
	int now2 = dep[x] + dep[zj2[mid]] - 2 * dep[lca2];
	int res = max(now1,now2);
	//dbg(mid,x,k,res);
	if (res > k) return 0;
	else return 1;
}

void solve() {
	int n,q;cin >> n >> q;
	set<int>s;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	int now = 0;
	while (s.count(now)) now++;
	for (int i = 1;i <= n;i++) {
		if (a[i] <= now){
			//dbg(i,a[i]);
			to[a[i]] = i;
		}
	}
	dfs(1,0);
	dbg(lca(3,4));
	// for(int i=1;i<=n;i++){
	// 	dbg(i,dep[i]);
	// }
	for (int i = 0;i <= now - 1;i++) {
		if (i == 0) {
			zj1[i] = to[i];
			zj2[i] = to[i];
		}
		else if (i == 1) {
			zj2[i] = to[i];
			zj1[i] = zj1[i - 1];
		}
		else {
			int d1;
			int lca1 = lca(zj1[i - 1],zj2[i - 1]);
			int now1 = dep[zj1[i - 1]] + dep[zj2[i - 1]] - 2 * dep[lca1];
			int lca2 = lca(zj1[i - 1],to[i]);
			int now2 = dep[zj1[i - 1]] + dep[to[i]] - 2 * dep[lca2];
			int lca3 = lca(zj2[i - 1],to[i]);
			int now3 = dep[zj2[i - 1]] + dep[to[i]] - 2 * dep[lca2];
			if (now2 >= now3) {
				if (now2 >= now1) {
					zj1[i] = zj1[i - 1];
					zj2[i] = to[i];
				}
			}
			else {
				if (now3 >= now1) {
					zj2[i] = zj2[i - 1];
					zj1[i] = to[i];
				}
			}
			dbg(lca1,lca2,lca3);
		}
		dbg(zj1[i],zj2[i],i);
	}
	for (int i = 1;i <= q;i++) {
		int x,k;cin >> x >> k;
		int l = 0,r = now - 1;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid,x,k)) {
				l = mid + 1;
				ans = max(ans,mid);
			}
			else r = mid - 1;
		}
		cout << ans + 1 << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	//std::cin >> T;
	while(T--) solve();
	return 0;
}