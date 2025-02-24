#include<bits/stdc++.h>
//#define int long long
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
void solve(){
	int n, q; cin >> n >> q;
	vector<pair<int, int>>b(n);
	vector<int>a(n);
	vector<int>c(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < n; i++){
		cin >> c[i];
		b[i] = {c[i], i};
	}
	sort(b.begin(), b.end(), greater<>());
	long long ans = 0;
	for(int i = 0; i < n; i++)ans += a[i];
	int block = sqrt(n);
	int lim = b[block].first;
	vector<int>s;
	for(int i = 0 ; i < n; i++){
		if(a[i] < lim)s.push_back(i);
	}
	for(int i = 1; i <= q; i++){
		int x; cin >> x;
		vector<int>temp;
		for(auto k : s){
			int d = c[(x + k) % n];
			ans -= a[k];
			a[k] = max(a[k], d);
			ans += a[k];
			if(a[k] < lim)temp.push_back(k);
		}
		s = temp;
		for(int j = 0; j <= block; j++){
			auto [val, id] = b[j];
			int t = (id - x + n) % n;
			ans -= a[t];
			a[t] = max(a[t], val);
			ans += a[t];
		}
		cout << ans << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}