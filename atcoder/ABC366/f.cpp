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
struct node{
	int a, b;
};
void solve(){
    int n, k; cin >> n >> k;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].a >> a[i].b;
    }
    sort(a.begin() + 1, a.end(), [&](node x, node y) -> bool{
    	return (x.a - 1) * y.b < (y.a - 1) * x.b;
    });
    vector dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
    	auto [x, b] = a[i];
    	for(int j = 0; j <= k; j++)dp[i][j] = dp[i - 1][j];
    	for(int j = 1; j <= min(k, i); j++){
    		dp[i][j] = max(dp[i][j], x * dp[i - 1][j - 1] + b);
    	}
    }
    cout << dp[n][k] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}