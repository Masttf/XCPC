#include <bits/stdc++.h>

using namespace std;
#define int long long
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ... Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve() {
	int n; cin >> n;
	vector<array<int, 3>> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2];
		a[i][0] = a[i][2] - a[i][1] + 1;
	}
	sort(a.begin() + 1, a.end());
	vector<int> f(n + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	int ans = 1;
	for(int i = 1; i <= n; i++){
		auto [len, l, r] = a[i];
		int fa = find(find, l - 1);
		int fb = find(find, r);
		if(fa == fb)ans = 0;
		f[fa] = fb;
	}
	cout << ans << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}