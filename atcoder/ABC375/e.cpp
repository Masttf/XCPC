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
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i] >> b[i];
    	sum += b[i];
    }
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
    	pre[i] = pre[i - 1] + b[i];
    }
    if(sum % 3 != 0){
    	cout << -1 << '\n';
    	return ;
    }
    sum /= 3;
    vector dp(n + 1, vector (sum + 1, vector<int>(sum + 1, Max)));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= sum; j++){
    		for(int k = 0; k <= sum; k++){
    			dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + (a[i] == 3 ? 0 : 1));
    			if(j + b[i] <= sum){
    				dp[i][j + b[i]][k] = min(dp[i][j + b[i]][k], dp[i - 1][j][k] + (a[i] == 1 ? 0 : 1));
    			}
    			if(k + b[i] <= sum){
    				dp[i][j][k + b[i]] = min(dp[i][j][k + b[i]], dp[i - 1][j][k] + (a[i] == 2 ? 0 : 1));
    			}
    		}
    	}
    }
    if(dp[n][sum][sum] == Max)cout << -1 << '\n';
    else cout << dp[n][sum][sum] << '\n';
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