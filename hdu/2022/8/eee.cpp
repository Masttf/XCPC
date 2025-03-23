#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int MAX = 1e6 + 15;

vector<int> sn[MAX];
int a[MAX], b[MAX], f[MAX];
int mx[MAX];

int find(int x) {
	if(f[x] != x) {
		f[x] = find(f[x]);
	}
	return f[x];
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if(u != v) {
		f[u] = v;
		mx[v] = max(mx[v], mx[u]);
	}
}

vector<int> pos[MAX];
void run() {
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		for(auto x : sn[a[i]]) {
			pos[x].push_back(i);
		}
		f[i] = mx[i] = i;
	}
	for(int i = 1; i < n; i++) {
		cin >> b[i];
	}
	vector<int> l(n + 1), r(n + 1);

	for(int i = n; i >= 1; i--) {
		int t = i;
		l[i] = r[i] = i;
		while(1) {
			int is = 0;
			int to = mx[find(t)];
			if(to == n) break;
			auto & v = pos[b[to]];

			int nt = lower_bound(v.begin(), v.end(), i) - v.begin();
			if(nt != (int)v.size() && v[nt] <= to) {
				merge(t, to + 1);
				t = find(t);
			} else break;
		}
		r[i] = mx[find(i)];
	}

	for(int i = 1; i <= n; i++) {
		if(i <= r[i - 1]) {
			auto & v = pos[b[i - 1]];
			int t = lower_bound(v.begin(), v.end(), i) - v.begin();
			if(t != (int)v.size() && v[t] <= r[i]) {
				l[i] = l[i - 1];
				r[i] = r[i - 1];
			}
		} else {
			while(1) {
				int is = 0;
				if(l[i] > 1) {
					int to = l[i] - 1; 
					auto & v = pos[b[to]];
					int t = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
					if(t != (int)v.size() && v[t] <= r[i]) {
						l[i] = l[to];
						r[i] = max(r[i], r[to]);
						is = 1;
					}
				}

				if(r[i] < n) {
					int to = r[i] + 1;
					auto & v = pos[b[r[i]]];
					int t = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
					if(t != (int)v.size() && v[t] <= r[i]) {
						r[i] = r[to];
						l[i] = min(l[i], l[to]);
						is = 1;
					}
				}
				if(!is) break;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
//		cout << l[i] << ' ' << r[i] << endl;
	}
	for(int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if(l[x] <= y && y <= r[x]) {
			cout << "Yes" << endl;
		} else cout << "No" << endl;
	}
	for(int i = 1; i <= n; i++) {
		for(auto x : sn[a[i]]) {
			pos[x].clear();
		}
	}
}
/*

*/


bitset<MAX> p;
void init() {
	int n = 2e5;
	for(int i = 2; i <= n; i++) {
		if(p[i]) continue;
		for(int j = i; j <= n; j += i) {
			p[j] = 1;
			sn[j].push_back(i);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	init();
	while(t--) {
		run();
	}
	return 0;

}