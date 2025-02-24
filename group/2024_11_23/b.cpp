#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

const int maxn = 2e5 + 5;
struct node {
	int v,w;
};
vector <node> g[maxn],t[maxn];
int now,vis[maxn],ok,num,sum,p;
int a[maxn];

void dfs1(int u,int f) {
	vis[u] = 1;
	a[u] = now;
	for (auto [v,w] : g[u]) {
		if (v == f) continue;
		if (vis[v]) {
			if ((now ^ w) == a[v]) continue;
			ok = 1;
			continue;
		}
		now ^= w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
		dfs1(v,u);
		now ^= w;
	}
}

void dfs(int u,int f,int val) {
	vis[u] = 1;
	if (val == 1) sum += num;
	for (auto [v,w] : t[u]) {
		if (v == f) continue;
		int noww = ((w >> p) & 1);
		dfs(v,u,(noww ^ val));
	}
}

void solve(){
	int n,m;cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v,w;cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		dfs1(i,0);
	}
	if (ok) {
		cout << "-1" << '\n';
		return ;
	}
	for (int i = 1;i <= n;i++) vis[i] = 0;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		if (vis[i]) continue;
		for (int j = 0;j < 30;j++) {
			int mi = 1e18;
			p = j;
			num = (1ll << j);
			sum = 0;
			dfs(i,0,0);
			mi = min(mi,sum);
			//dbg(sum);
			sum = 0;
			dfs(i,0,1);
			//dbg(sum);
			mi = min(mi,sum);
			ans += mi;
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