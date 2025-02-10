#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector dp(n + 1, vector<int>(n + 1, Max));
    dp[1][0]=0;
    for(int i = 2; i <= n; i++){
    	for(int j = 1; j < i-1; j++){
    		dp[i][j] = max(dp[i - 1][j], abs(a[i] - a[j]));
    		dp[i][i - 1] = min(dp[i][i - 1], max(dp[i - 1][j], abs(a[i] - a[j])));
    	}
    }
    int ans = Max;
    for(int i = 0; i < n; i++)ans = min(ans, dp[n][i]);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}