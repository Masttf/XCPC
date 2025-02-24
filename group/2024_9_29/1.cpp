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
    vector a(2 * n + 1, vector<int>(2 * n + 1, -1));
    int lim = 0;
    int lim2 = 0;
    vector<int>mx(2 * n);
    for(int i = 1; i <= 2 * n - 1; i++){
    	for(int j = 1 + lim2; j <= n + lim; j++){
    		cin >> a[i][j];
    		mx[i] = max(mx[i], a[i][j]);
    	}
    	if(i < n)lim++;
    	else lim2++;
    }
    // for(int i = 1; i < 2 * n; i++){
    // 	for(int j = 1; j < 2 * n; j++){
    // 		cout << a[i][j] << ' ';
    // 	}
    // 	cout << '\n';
    // }
    vector dp(2 * n, vector(2 * n + 1, array<int, 2>()));
    for(int i = 1; i < 2 * n; i++){
    	for(int j = 1; j < 2 * n; j++){
    		dp[i][j][0] = a[i][j];
    	}
    }
    for(int i = 1; i < 2 * n - 1; i++){
    	for(int j = 1; j < 2 * n; j++){
    		if(a[i + 1][j] != -1){
    			dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + a[i + 1][j]);
    			dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][0] + mx[i + 1]);
    			dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + a[i + 1][j]);
    		}
    		if(a[i + 1][j + 1] != -1){
    			dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][1] + a[i + 1][j + 1]);
    			dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] + mx[i + 1]);
    			dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][0] + a[i + 1][j + 1]);
    		}
    	}
    }
    int ans = 0;
    for(int i = 1; i < 2 * n; i++){
    	ans = max({ans, dp[2 * n - 1][i][0], dp[2 * n - 1][i][1]});
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