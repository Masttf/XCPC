#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> c(m + 1);
	for(int i = 1; i <= m; i++) cin >> c[i];
	set<pair<int, int>>s;
	for(int i = 1; i <= n; i++){
		s.insert({a[i] - b[i], a[i]});
	}
	int last = 1e9;
	vector<pair<int, int>> res;
	res.push_back({0, 1e18});
	for(auto [x, y] : s){
		if(y < last){
			res.push_back({x, y});
			last = y;
		}
	}
	// dbg("????");
	int N = 1e6;
	vector<int> dp(N + 1);
	for(int i = 1, r = res.size() - 1; i <= N; i++){
		while(r > 0 && i >= res[r].second){
			r--;
		}
		r++;
		r = min(r, (int)res.size() - 1);
		if(i < res[r].second)continue;
		int k = (i - res[r].second) / res[r].first + 1;
		int v = i - k * res[r].first;
		// dbg(i, v);
		dp[i] = 2 * k + dp[v];
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(c[i] >= res[1].second){
			int k = (c[i] - res[1].second) / res[1].first + 1;
			ans += 2 * k;
			c[i] -= k * res[1].first;
		}
		ans += dp[c[i]];
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
花费ai - bi就可以获得2点
前提是 >= ai
d = ai - bi
now - kd >= ai
k <= (now - ai) / d
k ++

一种可以直接贪心，现在有m种

一次过后ci < 1e6
*/