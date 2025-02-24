#include<bits/stdc++.h>
#define int long long
using namespace std;
#define lowbit(x) (x&(-(x)))
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

const int maxn = 1e6 + 5;
struct node {
	int v,w;
};
vector<node>t[maxn];
int dis[maxn],vis[maxn];
int n,m,k;

void dij() {
	for (int i = 1;i <= n;i++) dis[i] = 1e18;
	priority_queue<pair<int,int>>q;
	dis[1] = 0;
	q.push({0,1});
	while (!q.empty()) {
		auto now = q.top();q.pop();
		int u = now.second;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto i : t[u]) {
			if (dis[i.v] > dis[u] + i.w) {
				dis[i.v] = dis[u] + i.w;
				q.push({-dis[i.v],i.v});
			}
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
		vis[i] = 0;
	}
	for (int i = 1;i <= m;i++) {
		int u,v,w;cin >> u >> v >> w;
		t[u].push_back({v,w});
		t[v].push_back({u,w}); 
	}

	for (int i = 2;i <= n;i++) {
		int val = k * (1 | i);
		t[1].push_back({i,val});
		t[i].push_back({1,val});
	}
	for (int i = 2;i <= n;i++) {
		int v = lowbit(i);
		if (i == v) continue;
		int val = (k * (v | i));
		t[v].push_back({i,val});
		t[i].push_back({v,val});
	}
	dij();
	for (int i = 2;i <= n;i++) cout << dis[i] << ' ';
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}