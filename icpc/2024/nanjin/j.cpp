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


void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> vis(k + 1);
	for(int i = 1; i <= n; ++i) {
		int f;
		cin >> f;
		vis[f] = 1;
	}

	//SegmentTree
	vector<int> tree(k << 2);
	auto update = [&](auto self, int p, int l, int r, int index, int x) ->void {
		if(l == r) {
			tree[p] += x;
			return ;
		}
		int mid = l + r >> 1;
		if(index <= mid) self(self, p << 1, l, mid, index, x);
		else self(self, p << 1 | 1, mid + 1, r, index, x);

		tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
	};

	vector<vector<int>> v(k + 1);
	vector<int> cnt(k + 1);
	int tot = 0;
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		if (vis[a] && vis[b]) tot++;
		else if(a == b) {
			cnt[a]++;
		}
		else {
			if(vis[b]) cnt[a]++;
			else v[a].push_back(b);
			if(vis[a]) cnt[b]++;
			else v[b].push_back(a);
		}
	}
	for(int i = 1; i <= k; ++i) {
		if(!vis[i]) update(update, 1, 1, k, i, cnt[i]);
	}
	vector<int> p(k + 1);
	int ans = tot;

	for(int i = 1; i <= k; ++i) {
		if(vis[i]) continue;

		vis[i] = 1;
		update(update, 1, 1, k, i, -1000000);
		for(auto j:v[i]) {
			update(update, 1, 1, k, j, 1);
		}

		ans = max(ans, tot + cnt[i] + tree[1]);

		// dbg(i, mx);

		for(auto j:v[i]) 
			update(update, 1, 1, k, j, -1);

		update(update, 1, 1, k, i, 1000000);
		
		vis[i] = 0;
	}	

	cout << ans << '\n';

	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}