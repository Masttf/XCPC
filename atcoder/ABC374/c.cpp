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
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	int ans = 1e18;
	// dbg(sum);
	auto dfs = [&](auto self, int now, int res) -> void{
		if(now == n + 1){
			ans = min(ans, max(res, sum - res));
			return ;
		}
		self(self, now + 1, res);
		self(self, now + 1, res + a[now]);
	};
	dfs(dfs, 1, 0);
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