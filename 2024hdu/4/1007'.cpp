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
int cnt1 = 0;
void solve(){
	int n,q;cin >> n >> q;
	vector<int>a(n + 5);
	vector<int>b(n + 5);
	vector<int>c(n + 5);
	mt19937 rng(time(0));
	uniform_int_distribution<int>dist(1,1e9);
	uniform_int_distribution<int>dist1(0,n-1);
	for (int i = 0;i < n;i++) {
		a[i] = dist(rng);
	}
	set<int>s;
	int mx = 0;
	for (int i = 0;i < n;i++) {
		b[i] = dist(rng);
		s.insert(b[i]);
		mx = max(mx,b[i]);
		c[i] = b[i];
	}
	sort(c.begin(),c.begin() + n);
	mx = c[n - 33];
	// mx = c[n - 33];
	// dbg(mx);
	// int ttt = 10;
	// auto it = s.rbegin();
	// while (ttt--) {
	// 	mx = *(it);
	// 	it = prev(it);
	// }
	// cout << '\n';
	int sum = 0,pre = 0;
	vector<int>vis(n + 5);
	for (int i = 1;i <= q;i++) {
		int k = dist1(rng);
		// for (int j = 1;j <= n;j++) cout << a[j] << ' ';
		//cout << '\n';
		int ti = 0;
		int ttttt = 0;
		for (int j = 0;j < n;j++) {
			int suf = a[j];
			a[j] = max(a[j],b[(j + k) % n]);
			if (a[j] < mx) ttttt++;
			if (s.count(a[j])) {
				int w = lower_bound(c.begin(),c.begin() + n,a[j]) - c.begin();
				vis[w]++;
			}
		}
		//cout << ttttt << '\n';
		pre = sum;
	}
	int all = 0;
	for (int i = 0;i < n;i++) all += vis[i];
	cout << all;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	//cout << cnt1;
	return 0;
}