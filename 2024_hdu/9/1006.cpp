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
	vector<int>val(11);
	for(int i = 1; i <= 10; i++) cin >> val[i];
	int n, m; cin >> n >> m;
	vector<pair<int, int>> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	vector<int> b(m + 1);
	auto get_val = [&](int x, int y) -> int{
		int d = x * 10;
		d = (d + y - 1) / y;
		return val[d];
	};
	for(int i = 1; i <= n; i++){
		auto [x, y] = a[i];
		b[x] = max(b[x], y);
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j < i; j++){
			if(!b[j] || !b[i - j])continue;
			b[i] = max(b[i], b[j] + b[i - j]);
		}
		//dbg(i, b[i]);
	}

	for(int i = 1; i <= m; i++){
		if(!b[i])continue;
		b[i] = get_val(b[i], i);
		//dbg(i, b[i]);
	}
	vector<int>dp(m + 1);
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			dp[j] = max(dp[j], dp[j - i] + i * b[i]);
		}
	}
	cout << dp[m] << '\n';
 	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}