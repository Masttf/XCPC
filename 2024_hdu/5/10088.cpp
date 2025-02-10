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

struct node {
	int v,w;
};

const int maxn = 1005;
vector<node>t1[maxn],t2[maxn];

void solve(){
	int n,k;cin >> n >> k;
	vector<int>vis(n + 1);
	vector<int>vis1(n + 1),vis2(n + 1);
	vector<int>a(k + 5);
	for (int i = 1;i <= n;i++) {
		t1[i].clear();
		t2[i].clear();
	}
	for (int i = 1;i <= k;i++) {
		int x;cin >> x;
		a[i] = k;
		vis[x] = 1;
		vis1[x] = 1;
		vis2[x] = 1;
	}
	int ans = 0;
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		t1[u].push_back({v,w});
		t1[v].push_back({u,w});
		ans += w;
	}
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		t2[u].push_back({v,w});
		t2[v].push_back({u,w});
		ans += w;
	}
	for (int i = 1;i <= k;i++) {
		if (vis1[i] == 0 || vis2[i] == 0) continue;
		int now = a[i];
		int sum1 = 0,sum2 = 0;
		for (auto j : t1[now]) {
			if (vis1[j.v] == 0) continue;
			sum1 += j.w;
		}
		for (auto j : t2[now]) {
			if (vis2[j.v] == 0) continue;
			sum2 += j.w;
		}
		if (sum1 >= sum2) {
			vis2[now] = 0;
			ans -= sum2;
		}
		else {
			vis1[now] = 0;
			ans -= sum1;
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}