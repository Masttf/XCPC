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
constexpr int Max = 1e18;
void solve(){
    int n, K, X; cin >> n >> K >> X;
    vector<int> a(n + 1);
    a[0] = -X;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	
	vector dp(n + 1, vector(n + 1, vector<int>(n + 1, Max)));
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = max(0ll, i - K); j < i; j++){
			for(int k = 0; k <= j; k++){
				for(int p = 0; p <= i; p++){
					if(a[i] >= a[k] + p * X + X)dp[i][i][0] = min(dp[i][i][0], dp[j][k][p] + a[i] * (i - j) - (pre[i] - pre[j]));
					else dp[i][k][p + 1] = min(dp[i][k][p + 1], dp[j][k][p] + (a[k] + p * X + X) * (i - j) - (pre[i] - pre[j]));	
				}
			}
		}
	}
	int ans = Max;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			ans = min(ans, dp[n][i][j]);
		}
	}
	cout << ans << '\n';
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