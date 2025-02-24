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
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<array<int, 2>> dp(n + 1);
	int ans = 0;
	a[0] = 1e9;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			if(a[j] > a[i]){
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
			if(a[j] < a[i]){
				if(dp[j][1] >= 3)dp[i][1] = max(dp[i][1], dp[j][1] + 1);
				if(dp[j][0] >= 2)dp[i][1] = max(dp[i][1], dp[j][0] + 1);
			}
		}
		ans = max(ans, dp[i][1]);
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