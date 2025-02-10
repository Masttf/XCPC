#include<bits/stdc++.h>
// #define int long long
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
constexpr int inf = 1e9;
constexpr int maxn = 5005;
int dp[maxn][maxn][2];
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		dp[i][j][0] = dp[i][j][1] = inf;
    	}
    }
	for(int i = 1; i <= n; i++){
		dp[i][i][0] = 0;
		dp[i][i][1] = 1;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 1; i + len - 1 <= n; i++){
			int l = i, r = i + len - 1;
			dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + (a[l] != a[l + 1]));
			dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + (a[l] != a[r]));
			dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + (a[r] != a[l]));
			dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + (a[r] != a[r - 1]));
		}
	}
	cout << min(dp[1][n][0], dp[1][n][1]) << '\n';
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