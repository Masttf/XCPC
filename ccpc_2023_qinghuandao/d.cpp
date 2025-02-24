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
void solve(){
	int n, m;
	std::cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	vector<pair<int, int>> v(m);
	for(int i = 0; i < m; ++i) std::cin >> v[i].first >> v[i].second;
	std::ranges::sort(v, std::greater<>());
	std::priority_queue<int, vector<int>, greater<int>> q;
	int i = 1;
	while(!v.empty()) {
		auto x = v.back();
		v.pop_back();
		while(i <= n and i <= x.first) q.push(a[i++]);
		int mid = q.top();
		q.pop();
		q.push(mid - x.second);
	}
	while(i <= n) q.push(a[i++]);
	int ans = 0;
	while(!q.empty()) {
		ans += q.top();
		std::cout << ans << ' ';
		q.pop();
	}
	std::cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}