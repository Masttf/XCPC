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
    int n, lx, ly; cin >> n >> lx >> ly;
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> x[i] >> y[i];
    }
    vector dp(n + 1, vector(n + 1, vector<int>(lx + 1, Max)));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= lx; k++){
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for(int j = 1; j <= i; j++){
            for(int k = x[i]; k <= lx; k++){
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - x[i]] + y[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= lx; j++){
            if(dp[n][i][j] <= ly){
                ans = max(ans, i + 1);
            }
        }
    }
    ans = min(ans, n);
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